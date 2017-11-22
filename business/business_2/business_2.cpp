/*
 * business_2.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_2.h"
#include <iostream>
#include <cstdio>
#include <cstring>


void Busi2Callback::_callback(void *param)
{
    struct Busi2CallbackParam busi_param = *(struct Busi2CallbackParam*)param;
    this->Callback(busi_param);
}

void Busi2Callback::_timeout(void *param)
{
    struct Busi2CallbackParam busi_param = *(struct Busi2CallbackParam*)param;
    this->Timeout(busi_param);
}


int Business2::Init(Callback *callback)
{
    return Mysdk::Init(callback);
}

int Business2::DoAction(const Busi2ActionParam& param)
{
    std::cout << "Business2Impl DoAction: " << param.param_1 << param.param_2 << param.param_3 << std::endl;

    char buf[] = "abcdefg";
    return SendData(buf, strlen(buf) + 1);
}

int Business2::Update()
{
    return Mysdk::Update();
}

int Business2::Fini()
{
    return Mysdk::Fini();
}

