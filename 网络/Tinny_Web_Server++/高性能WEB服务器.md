# 基于TinyWebServer高性能Web服务器开发

## 目标

- 巩固C++, 
- 学习不太熟悉的Unix网络知识
- 学习多进程,多线程,多路复用,进程通信,线程通信
- IO多路复用 + non-blocking + threadpool的设计方案



## 多进程与线程



 - 多进程：accept 之后 fork，父进程继续 accept，子进程来处理这 connfd。这样在高并发下，存在几个问题：
   	- 问题1：每次来一个连接都 **fork 开销太大** 。可以查一下调用 fork 时系统具体做了什么，注意一下复制父进程页表的操作。
   	- 问题2：并发量上来后，进程调度器压力太大，**进程切换**开销非常大。
   	- 问题3：高负载下，消耗太多内存，此外高并发下，**进程间通**信带来的开销也不能忽略。

- 多线程：accept 之后开线程来处理连接。这样解决了 fork 的问题，但是问题2和3还是无法解决,甚至线程崩溃影响其他.

- 线程池：线程数量固定。解决上述问题

参考:https://segmentfault.com/a/1190000013215615

https://blog.csdn.net/Tanswer_/article/details/78574402

https://blog.csdn.net/tanswer_/article/details/77099008