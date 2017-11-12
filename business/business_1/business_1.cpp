/*
 * business_1.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1.h"
#include "business_1_impl.h"
#include <iostream>


void Busi1Callback::_callback(void *param)
{
    struct Busi1CallbackParam *busi_param = (struct Busi1CallbackParam*)param;
    this->callback(busi_param);
}

void Busi1Callback::_timeout(void *param)
{
    struct Busi1CallbackParam *busi_param = (struct Busi1CallbackParam*)param;
    this->timeout(busi_param);
}


int Business1::Init(Callback *callback, int param_1, int param_2)
{
    Mysdk::Init(callback);
    return m_business1_impl->Init(param_1, param_2);
}

int Business1::do_action(int param_1, int param_2, int param_3)
{
    return m_business1_impl->do_action(param_1, param_2, param_3);
}

int Business1::Update()
{
    return Mysdk::Update();
}

int Business1::Fini()
{
    return Mysdk::Fini();
}

