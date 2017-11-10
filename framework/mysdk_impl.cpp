/*
 * mysdk_impl.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "mysdk_impl.h"
#include <stdlib.h>


MysdkImpl::MysdkImpl() : m_callback(NULL)
{
}

MysdkImpl::~MysdkImpl()
{
}

int MysdkImpl::Init(Callback *callback)
{
    m_callback = callback;
    return 0;
}

int MysdkImpl::Update()
{
    /*
     * 调用回调
     */
    m_callback->callback();
    return 0;
}

