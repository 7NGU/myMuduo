#pragma once //avoid a header file be imported repeatedly

#include "noncopyable.h"
//如果不禁止Socket的拷贝，会发生临时的对象被析构之后，原本的SOCKET被SHUTDOWN

class Socket : noncopyable
{
public:
    explicit Socket(int sockfd) : sockfd_(sockfd) {} //explicit防止C++编译器隐式转换
    ~Socket();

    //get sockfd
    int fd() const { return sockfd_; }
    //bind sockfd
    void bindAddress(const InetAddress &localaddr);
    //make sockef connectable
    void listen();
    //accept connect
    int accept(InetAddress *peeraddr);

    //set 半关闭
    void shutdownWrite();

    void setTcpNoDely(bool on); // 设置Nagel算法
    void setReuseAddr(bool on); //设置地址复用
    void setReusePort(bool on); //设置端口复用
    void SetKeepAlive(bool on); //设置长连接

private:
    const int sockfd_;
};