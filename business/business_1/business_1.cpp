/*
 * business_1.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1.h"
#include <iostream>
#include <cstdio>
#include <cstring>


void Busi1Callback::_callback(void *param)
{
    struct Busi1CallbackParam *busi_param = (struct Busi1CallbackParam*)param;
    this->Callback(busi_param);
}

void Busi1Callback::_timeout(void *param)
{
    struct Busi1CallbackParam *busi_param = (struct Busi1CallbackParam*)param;
    this->Timeout(busi_param);
}


int Business1::Init(Callback *callback, int param_1, int param_2)
{
    Mysdk::Init(callback);
    /*
     * 此business单独的一些初始化，可以利用framework里面的组件
     */
    printf("in Business1::Init, param_1: %d, param_2: %d\n", param_1, param_2);

    return 0;
}

int Business1::DoAction(int param_1, int param_2, int param_3)
{
    std::cout << "Business1 DoAction: " << param_1 + param_2 + param_3 << std::endl;

    char buf[] = "abcdefg";
    return SendData(buf, strlen(buf) + 1);
}

int Business1::Update()
{
    return Mysdk::Update();
}

int Business1::Fini()
{
    return Mysdk::Fini();
}

