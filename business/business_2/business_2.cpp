/*
 * business_2.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_2.h"
#include "business_2_impl.h"
#include <iostream>


void Busi2Callback::_callback(void *param)
{
    struct Busi2CallbackParam *busi_param = (struct Busi2CallbackParam*)param;
    this->callback(busi_param);
}

void Busi2Callback::_timeout(void *param)
{
    struct Busi2CallbackParam *busi_param = (struct Busi2CallbackParam*)param;
    this->timeout(busi_param);
}


int Business2::Init(Callback *callback)
{
    return Mysdk::Init(callback);
}

int Business2::do_action(const std::string& param_1, const std::string& param_2, const std::string& param_3)
{
    return m_business2_impl->do_action(param_1, param_2, param_3);
}

int Business2::Update()
{
    return Mysdk::Update();
}

int Business2::Fini()
{
    return Mysdk::Fini();
}

