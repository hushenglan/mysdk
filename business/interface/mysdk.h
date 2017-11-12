/*
 * mysdk.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_MYSDK_H_
#define INTERFACE_MYSDK_H_


/*
 * 通常业务不直接使用Callback类
 * 注意下面的宏需要和Callback内部的定义保持一致
 */
class Callback
{
public:
    virtual void _callback(void *param) = 0;
    virtual void _timeout(void *param) = 0;
};

#define CALLBACK_USELESS_DECLARE \
    void _callback(void *param); \
    void _timeout(void *param)


/*
 * 通常业务不直接使用Mysdk类
 */
class MysdkImpl;
class Mysdk {
public:
    Mysdk();
    ~Mysdk();

    int Init(Callback *callback);
    int Update();
    int Fini();

private:
    MysdkImpl *m_mysdk_impl;
};


#endif /* INTERFACE_MYSDK_H_ */
