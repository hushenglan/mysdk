/*
 * mysdk.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_MYSDK_H_
#define INTERFACE_MYSDK_H_


class MysdkImpl;


#define CALLBACK_USELESS_DECLARE \
    void _callback(void *param); \
    void _timeout(void *param)


class Callback
{
public:
    virtual void _callback(void *param);
    virtual void _timeout(void *param);
};


class Mysdk {
public:
    int Init(Callback *callback);
    int Update();

private:
    MysdkImpl *m_mysdk_impl;
};


#endif /* INTERFACE_MYSDK_H_ */
