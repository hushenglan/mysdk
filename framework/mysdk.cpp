/*
 * mysdk.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "mysdk.h"
#include "mysdk_impl.h"


int Mysdk::Init(Callback *callback)
{
    m_mysdk_impl = new MysdkImpl();
    return m_mysdk_impl->Init(callback);
}

int Mysdk::Update()
{
    return m_mysdk_impl->Update();
}
