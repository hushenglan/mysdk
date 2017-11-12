/*
 * mysdk_impl.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "mysdk_impl.h"
#include <cstdio>
#include <iostream>
#include "business_1.h"
#include "business_2.h"


MysdkImpl::MysdkImpl() : m_callback(NULL)
{
}

MysdkImpl::~MysdkImpl()
{
}

int MysdkImpl::Init(Callback *callback)
{
    m_callback = callback;

    /*
     * 一些通用组件的初始化，比如网络、日志等
     */
    printf("in MysdkImpl::Init\n");

    return 0;
}

int MysdkImpl::Update()
{
    /*
     * 从后端接收数据包，根据数据包的seq可以查询本地session
     * 本地session会保存请求的业务类型，所以根据返回的数据包就可以得到业务类型
     * 然后根据对应的回调函数参数结构体调用业务定义的回调
     */

    int request_type = BUSINESS_1;
    switch(request_type)
    {
        case BUSINESS_1:
        {
            printf("Update to BUSINESS_1\n");
            struct Busi1CallbackParam param;
            param.seq = 100001;
            param.result = 99984386;
            char msg[1024] = "wo le ge qu";
            param.msg = msg;
            m_callback->_callback(&param);
            m_callback->_timeout(&param);
            break;
        }

        case BUSINESS_2:
        {
            printf("Update to BUSINESS_2\n");
            struct Busi2CallbackParam param;
            param.seq = 100002;
            param.is_need = false;
            m_callback->_callback(&param);
            m_callback->_timeout(&param);
            break;
        }

        default:
        {
            printf("unknown request_type: %d\n", request_type);
            break;
        }
    }

    return 0;
}

int MysdkImpl::Fini()
{
    return 0;
}
