#ifndef INET_ADDRESS_H
#define INET_ADDRESS_H

#include <arpa/inet.h> //提供IP地址转换函数
#include <netinet/in.h> //定义数据结构sockaddr_in
#include <string>
#include <string.h>

class InetAddress
{
public:
    explicit InetAddress(uint16_t port = 0, std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in &addr) : addr_(addr) {}

    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const;

    const sockaddr_in *getSockAddr() const { return &addr_; }
    void setSockAddr(const sockaddr_in &addr) { addr_ = addr; }

private:
    sockaddr_in addr_;
    /*
    struct sockaddr_in{
        sa_family_t    sin_family; 地址族
        uint16_t       sin_port; 16位TCP/UDP端口号，网络字节序（NBO）
        strcut in_addr sin_addr; 32位IP地址，NBO
        char           sin_zero[8]; 不使用
    };

    strcut in_addr{
        In_addr_t      s_addr; //32位IPv4地址
    };
    */

};

#endif