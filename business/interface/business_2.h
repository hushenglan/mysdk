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


class Business2Impl;


struct Busi2CallbackParam
{
    unsigned int seq;
    bool is_need;
};


class Busi2Callback : public Callback
{
public:
    virtual void callback(struct Busi2CallbackParam *param) = 0;
    virtual void timeout(struct Busi2CallbackParam *param) = 0;

    CALLBACK_USELESS_DECLARE;
};


class Business2 : public Mysdk
{
public:
    int do_action(const std::string& param_1, const std::string& param_2, const std::string& param_3);

private:
    Business2Impl *m_business2_impl;
};


#endif /* INTERFACE_BUSINESS_2_H_ */
