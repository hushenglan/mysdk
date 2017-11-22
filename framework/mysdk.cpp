/*
 * mysdk.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "mysdk.h"
#include "mysdk_impl.h"
#include <cstdio>


Mysdk::Mysdk() : m_mysdk_impl(NULL)
{
}

Mysdk::~Mysdk()
{
    if (m_mysdk_impl != NULL) {
        delete m_mysdk_impl;
        m_mysdk_impl = NULL;
    }
}

int Mysdk::Init(Callback *callback)
{
    if (m_mysdk_impl == NULL) {
        m_mysdk_impl = new MysdkImpl();
        return m_mysdk_impl->Init(callback);
    }

    return 0;
}

int Mysdk::SendData(char* buf, int buf_len)
{
    return m_mysdk_impl->SendData(buf, buf_len);
}

int Mysdk::Update()
{
    return m_mysdk_impl->Update();
}

int Mysdk::Fini()
{
    return m_mysdk_impl->Fini();
}
