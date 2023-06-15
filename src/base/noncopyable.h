#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

/*
禁止拷贝操作的基类，设置为protect权限的成员函数可以让派生类继承
派生类对象可以正常地构造和析构
*/

class noncopyable
{
public:
    noncopyable(const noncopyable &) = delete;
    noncopyable &operator=(const noncopyable &) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

//得益于C++11的新特性，使用delete可以禁用函数调用，default让编译器默认生成
//C++98中要实现一个类不被复制，只能通过对拷贝和赋值构造函数private声明来实现。

#endif