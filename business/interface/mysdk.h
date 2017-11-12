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
 */
class Callback
{
public:
    virtual void _callback(void *param);
    virtual void _timeout(void *param);
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
