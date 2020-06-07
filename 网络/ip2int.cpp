//输入点分十进制的IP，将其转换成整型后，再反向转换进行验证
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

using namespace std;

unsigned int IPtoInt(char *str_ip) {
  in_addr addr;
  unsigned int int_ip;
  if (inet_pton(AF_INET, str_ip, &addr)) {  //点分十进制src转二进制网络字节序
    int_ip = ntohl(addr.s_addr);  //网络字节序转主机字节序
  }
  return int_ip;
}

string IpToDot(unsigned int nIp) {
  in_addr addr;
  addr.s_addr = htonl(nIp);  //主机字节序转网络字节序
  char strip[INET_ADDRSTRLEN];
  const char *ptr = inet_ntop(AF_INET, &addr, strip,
                              sizeof(strip));  //二进制网络字节序转点分十
  if (NULL != ptr) {
    return strip;
  }
  return NULL;
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    unsigned int nIp = IPtoInt(argv[i]);
    cout <<"0x" << nIp << endl;
    cout << IpToDot(nIp) << endl;
  }
}
