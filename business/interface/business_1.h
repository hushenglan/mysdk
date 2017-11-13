/*
 * business_1.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_BUSINESS_1_H_
#define INTERFACE_BUSINESS_1_H_

#include "mysdk.h"


/*
 * 回调参数
 */
struct Busi1CallbackParam
{
    unsigned int seq;
    int result;
    char *msg;
};


/*
 * 用户需要实现的回调函数基类，子类实现Callback和Timeout即可
 */
class Busi1Callback : public Callback
{
public:
    virtual void Callback(struct Busi1CallbackParam *param) = 0;
    virtual void Timeout(struct Busi1CallbackParam *param) = 0;

    CALLBACK_USELESS_DECLARE;
};


/*
 * 用户可以使用的业务接口
 */
class Business1Impl;
class Business1 : public Mysdk
{
public:
    int Init(Callback *callback, int param_1, int param_2);
    int DoAction(int param_1, int param_2, int param_3);
    int Update();
    int Fini();

private:
    Business1Impl *m_business1_impl;
};


#endif /* INTERFACE_BUSINESS_1_H_ */
