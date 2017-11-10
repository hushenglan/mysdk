/*
 * mysdk_impl.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "mysdk_impl.h"


int MysdkImpl::Init(const Callback& callback)
{
    m_callback = callback;
    return 0;
}

int MysdkImpl::Update()
{
    /*
     * 调用回调
     */
    return m_callback.callback();
}

