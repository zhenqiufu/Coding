/*
***********************************************************************
* tcpserver.h: 基于进程的并发服务器
*
*  by Zhenqiu Fu
***********************************************************************
*/

#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

// #include "common/logging/include/easylogging++.h"

namespace ASV {

class tcpserver {
 public:
  explicit tcpserver(const std::string &_port)
      : fdmax(0), listener(0), port(_port), results(0) {
    initializesocket();
  }
  virtual ~tcpserver() = default;

  void selectserver(char *recv_buffer, const char *send_buffer, int recv_size,
                    int send_size) {
    read_fds = master;  // copy it
    if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
      // CLOG(ERROR, "tcp-server") << "select: " << strerror(errno);
      std::cout << "ERROR"
                << "select: " << strerror(errno) << std::endl;
      results = 4;
    }

    // run through the existing connections looking for data to read
    for (int i = 0; i <= fdmax; i++) {  //迭代服务器,一个一个处理
      if (FD_ISSET(i, &read_fds)) {     // we got one!!
        if (i == listener) {            // handle new connections
          // newly accept()ed socket descriptor
          socklen_t addrlen = sizeof remoteaddr;
          int newfd =
              accept(listener, (struct sockaddr *)&remoteaddr, &addrlen);

          if (newfd == -1) {
            // CLOG(ERROR, "tcp-server") << "accept: " << strerror(errno);
            std::cout << "(ERROR, tcp-server)"
                      << "accept: " << strerror(errno) << std::endl;
          } else {
            FD_SET(newfd, &master);  // add to master set
            if (newfd > fdmax) {     // keep track of the max
              fdmax = newfd;
            }
            // CLOG(INFO, "tcp-server")
            std::cout << "INFO tcp-server"
                      << "selectserver: new connection from "
                      << inet_ntop(remoteaddr.ss_family,
                                   get_in_addr((struct sockaddr *)&remoteaddr),
                                   remoteIP, INET6_ADDRSTRLEN)
                      << " on socket " << std::to_string(newfd);
          }
        } else {
          // handle data from a client
          int recv_bytes = recv(i, recv_buffer, recv_size, 0);
          if (recv_bytes <= 0) {
            // got error or connection closed by client
            if (recv_bytes == 0) {
              // connection closed
              // CLOG(INFO, "tcp-server")
              //     << "selectserver: socket " << i << " hung up";
              std::cout << "INFO"
                        << "selectserver: socket " << i << " hung up"
                        << std::endl;
            } else {
              // CLOG(ERROR, "tcp-server") << "recv: " << strerror(errno);
              std::cout << "ERROR"
                        << "recv: " << strerror(errno) << std::endl;
            }
            close(i);            // bye!
            FD_CLR(i, &master);  // remove from master set
          } else {
            // we got some data from a client
            int send_bytes = send(i, send_buffer, send_size, 0);
            if (send_bytes == -1) {
              // CLOG(ERROR, "tcp-server") << "send: " << strerror(errno);
              std::cout << "ERROR"
                        << "recv: " << strerror(errno) << std::endl;
            }
          }

        }  // END handle data from client
      }    // END got new incoming connection
    }      // END looping through file descriptors
  }        // selectserver()

  void selectserver_process(char *recv_buffer, const char *send_buffer,
                            int recv_size, int send_size) {
    //多进程并发
    while (1) {
      socklen_t addrlen = sizeof remoteaddr;  //客户端地址大小
      int connfd = accept(listener, (struct sockaddr *)&remoteaddr, &addrlen);
      // 创建子进程，为这个客户创建一个子进程，并判断当前是运行是在父进程还是在子进程中
      if (fork() == 0) {
        // 在子进程中
        printf("new process created! \n");
        int recv_bytes = recv(connfd, recv_buffer, recv_size, 0);
        int send_bytes = send(connfd, send_buffer, send_size, 0);
        // printf("The buffer recived: %s\n", recv_buffer);
        // close(listener);
        // read(connfd, &ch, 1);
        // ch++;
        // write(connfd, &ch, 1);
        // close(connfd);
        // sleep(5);
        // printf("subprocess, ch: %d, exit\n", ch);
        // exit(0);
      } else {
        // 在父进程中
        printf("father process! \n");
        close(connfd);
      }
    }
  }

  int getsocketresults() const noexcept { return results; }
  int getconnectioncount() const {
    int clientcount = 0;  // # of clients connected
    for (int i = 0; i <= fdmax; i++) {
      if (FD_ISSET(i, &master)) ++clientcount;
    }
    return clientcount - 1;  // remove self fd
  }

 private:
  fd_set master;    // master file descriptor list
  fd_set read_fds;  // temp file descriptor list for select()
  int fdmax;        // maximum file descriptor number
  int listener;     // listening socket descriptor

  struct sockaddr_storage remoteaddr;  // client address

  char remoteIP[INET6_ADDRSTRLEN];

  std::string port;  // port we're listening on
  int results;
  // get sockaddr, IPv4 or IPv6:
  void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
      return &(((struct sockaddr_in *)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
  }

  void initializesocket() {
    struct addrinfo hints, *ai, *p;

    FD_ZERO(&master);  // clear the master and temp sets
    FD_ZERO(&read_fds);

    // get us a socket and bind it
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;  //被动的,用于server
    int rv = getaddrinfo(NULL, port.c_str(), &hints, &ai);
    if (rv != 0) {  // getaddrinfo 出错,输出错误信息
      // CLOG(ERROR, "tcp-server") << "selectserver: " << gai_strerror(rv);

      fprintf(stderr, "selectserver: %s\n", gai_strerror(rv));
      results = 1;
    }

    for (p = ai; p != NULL; p = p->ai_next) {
      listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
      if (listener < 0) {
        continue;
      }

      // // lose the pesky "address already in use" error message
      // int yes = 1;  // for setsockopt() SO_REUSEADDR, below
      // setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

      struct timeval tv;
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      setsockopt(listener, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv,
                 sizeof tv);

      //服务器套接字地址与套接字描述符bind
      if (bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
        close(listener);  //-1 error,关闭
        continue;
      }

      break;
    }
    // if we got here, it means we didn't get bound
    if (p == NULL) {
      // CLOG(ERROR, "tcp-server") << "selectserver: failed to bind";
      std::cout << "selectserver: failed to bind" << std::endl;
      results = 2;
    }

    freeaddrinfo(ai);  // all done with this

    // listen
    if (listen(listener, 10) == -1) {
      // CLOG(ERROR, "tcp-server") << "listen: " << strerror(errno);
      std::cout << "ERROR"
                << "listen: " << strerror(errno) << std::endl;
      results = 3;
    }

    // add the listener to the master set
    // FD_SET(listener, &master);

    // keep track of the biggest file descriptor
    // fdmax = listener;  // so far, it's this one
    // 避免出现僵尸进程
    // signal(SIGCHLD, SIG_IGN);
  }
};

}  // end namespace ASV

#endif /*_TCPSERVER_H_*/
