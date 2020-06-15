# 基于TinyWebServer高性能Web服务器开发

## 目标

- 巩固C++, 
- 学习不太熟悉的Unix网络知识
- 学习多进程,多线程,多路复用,进程通信,线程通信
- IO多路复用 + non-blocking + threadpool的设计方案

- 顺便学习一下数据库
- 还有好多要学的

## 从零开始

1. 建立一个TCP socket 服务器
   - 先简单一些:监听80端口,接收请求
2. 编写一个解析HTTP request 解析器
3. 实现URL路由
4. 产生 Response

## 未来加入:

类封装

GET POST

线程池  https://wangpengcheng.github.io/2019/05/17/cplusplus_theadpool/

select/poll/epoll

多进程

数据库

动态请求

负载均衡

## 过程记录:

### 请求报文

![img](https://img-blog.csdn.net/20180920123303821?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2NTczODI4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

头部字段：+空格+数值+\r+\n 

最后一个头部字段后有两个\r+\n \r+\n 



接下来是请求数据



### 相应报文

![img](https://img-blog.csdn.net/20180920140005429?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM2NTczODI4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)



其中响应首行格式如：HTTP/1.1+状态响应码+\r\n 状态响应码参考如下：

- `200 OK` 客户端请求成功
- `301 Moved Permanently` 请求永久重定向
- `302 Moved Temporarily` 请求临时重定向
- `304 Not Modified` 文件未修改，可以直接使用缓存的文件。
- `400 Bad Request` 由于客户端请求有语法错误，不能被服务器所理解。
- `401 Unauthorized` 请求未经授权。这个状态代码必须和WWW-Authenticate报头域一起使用
- `403 Forbidden` 服务器收到请求，但是拒绝提供服务。服务器通常会在响应正文中给出不提供服务的原因
- `404 Not Found` 请求的资源不存在，例如，输入了错误的URL
- `500 Internal Server Error` 服务器发生不可预期的错误，导致无法完成客户端的请求。
- `503 Service Unavailable` 服务器当前不能够处理客户端的请求，在一段时间之后，服务器可能会恢复正常。









参考:https://blog.csdn.net/qq_36573828/article/details/82784425?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase#commentBox