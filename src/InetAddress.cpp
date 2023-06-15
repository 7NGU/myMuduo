#include "InetAddress.h"

//构造函数
InetAddress::InetAddress(uint16_t port, std::string ip){
    ::bzero(&addr_, sizeof(addr_)); //对地址结构进行清零
    //::memset(&addr_, 0, sizeof(addr_)); 与上面等效
    addr_.sin_family = AF_INET; //IPv4
    addr_.sin_port = ::htons(port); //host主机字节序转换为NBO
    //addr_.sin_addr.s_addr = htonl(INADDR_ANY); 
    //FIXME : it should be addr.ip() and need some conversion
    char temp[64];
    ::strcpy(temp, ip.c_str());
    ::inet_pton(AF_INET, temp, &addr_.sin_addr);
}

//成员函数实现
std::string InetAddress::toIp() const{
    char buf[64] = {0};
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof(buf));
    //inet_ntop()相比inet_ntoa()支持多种地址族，作用是将NBO转换为字符串
    return buf;
}

std::string InetAddress::toIpPort() const{
    char buf[64] = {0};
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof(buf));
    size_t end = ::strlen(buf);
    uint16_t port = ::ntohs(addr_.sin_port);
    sprintf(buf + end, ":%u", port); //127.0.0.1:0 %u-无符号十进制整数
    return buf;
}

uint16_t InetAddress::toPort() const{
    return ::ntohs(addr_.sin_port);
}


#include <iostream>
int main()
{
    InetAddress addr(8080, "192.168.1.1");
    std::cout << addr.toIpPort() << std::endl;
   
    return 0;
}