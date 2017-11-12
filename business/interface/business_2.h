/*
 * business_2.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_BUSINESS_2_H_
#define INTERFACE_BUSINESS_2_H_

#include "mysdk.h"
#include <string>


/*
 * 回调参数
 */
struct Busi2CallbackParam
{
    unsigned int seq;
    bool is_need;
};


/*
 * 用户需要实现的回调函数基类，子类实现callback和timeout即可
 */
class Busi2Callback : public Callback
{
public:
    virtual void callback(const struct Busi2CallbackParam& param) = 0;
    virtual void timeout(const struct Busi2CallbackParam& param) = 0;

    CALLBACK_USELESS_DECLARE;
};


/*
 * 接口参数
 */
struct Busi2ActionParam
{
    std::string param_1;
    std::string param_2;
    std::string param_3;
};


/*
 * 用户可以使用的业务接口
 */
class Business2Impl;
class Business2 : public Mysdk
{
public:
    int Init(Callback *callback);
    int do_action(const Busi2ActionParam& param);
    int Update();
    int Fini();

private:
    Business2Impl *m_business2_impl;
};


#endif /* INTERFACE_BUSINESS_2_H_ */
