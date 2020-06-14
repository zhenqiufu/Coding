/*************************************************************************
        > File Name: multithread.cpp
        > Author: Zhenqiu Fu
        > Mail: fuzhenqiu0810@gmail.com
        > Created Time: 2020年06月14日 星期日 13时39分04秒
 ************************************************************************/

#include <unistd.h>

#include <iostream>
#include <mutex>
#include <thread>  // 1.

//类内调用类内函数,除此以外还可以设置为 static静态函数

// class multithread {
//  public:
//   multithread(){};
//   ~multithread(){};
//   void mainloop() {
//     std::thread mythread(&multithread::prin, this);
//     mythread.detach();
//   }

//  private:
//   void prin() { std::cout << "thread created!!!!!!!" << std::endl; }
// };

// int main() {
//   multithread my;
//   std::cout << "start!" << std::endl;
//   my.mainloop();
//   std::cout << "finishi!" << std::endl;
//   return 0;
// }

/***********************************************************************************/
// detach和join

// void hello_thread() { std::cout << "hello_thread t1!" << std::endl; }
// void msum(int a, int b) {
//   int c = a + b;
//   std::cout << "a"
//             << "+"
//             << "b"
//             << "=" << c << std::endl;
// }

// int main() {
//   /* code */
//   std::thread t1(hello_thread);
//   std::thread t2(msum, 2, 3);
//   // t1.join();
//   // t2.join();

//   t1.detach();
//   t2.detach();

//   std::cout << "main process!" << std::endl;

//   return 0;
// }

/***********************************************************************************/
// 类外调用类内函数,
// class multithread {
//  public:
//   multithread(){};
//   ~multithread(){};

//  public:
//   void prin(int age) {
//     std::cout << "thread created!!!!!!!" << std::endl;
//     std::cout << age << std::endl;
//   }
// };

// int main() {
//   /* code */
//   multithread my;
//   std::thread t1(&multithread::prin, my, 25);
//   t1.join();
//   std::cout << "main process!" << std::endl;

//   return 0;
// }

/***********************************************************************************/
// 互斥
std::mutex mt;
int data = 1;
void add(int a) {
  // mt.lock();
  data += a;
  std::cout << "add data" << data << std::endl;
  // mt.unlock();
}

void multi(int a) {
  // mt.lock();
  data *= a;
  std::cout << "multi data" << data << std::endl;
  // mt.unlock();
}

int main() {
  /* code */
  std::thread t1(add, 2);
  std::thread t2(multi, 6);
  t1.detach();
  t2.detach();
  usleep(100);
  std::cout << "main process!" <<data<< std::endl;
getchar();
  return 0;
}