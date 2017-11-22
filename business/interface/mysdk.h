/*
 * mysdk.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_MYSDK_H_
#define INTERFACE_MYSDK_H_


/*
 * 业务不直接使用Callback类
 * 注意下面的宏需要和Callback内部的定义保持一致
 */
class Callback
{
public:
    virtual void _callback(void *param) = 0;
    virtual void _timeout(void *param) = 0;
};

#define USELESS_DECLARE \
    void _callback(void *param); \
    void _timeout(void *param)


/*
 * 业务不直接使用Mysdk类
 */
class MysdkImpl;
class Mysdk {
public:
    Mysdk();
    ~Mysdk();

protected:
    int Init(Callback *callback);
    int Update();
    int Fini();
    int SendData(char* buf, int buf_len);

private:
    MysdkImpl *m_mysdk_impl;
};


#endif /* INTERFACE_MYSDK_H_ */
