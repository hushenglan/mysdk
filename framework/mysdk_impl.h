/*
 * mysdk_impl.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef FRAMEWORK_MYSDK_IMPL_H_
#define FRAMEWORK_MYSDK_IMPL_H_

#include "mysdk.h"


enum REQUEST_TYPE {
    BUSINESS_1 = 0,
    BUSINESS_2,
};


class MysdkImpl
{
public:
    MysdkImpl();
    ~MysdkImpl();

    int Init(Callback *callback);
    int Update();
    int Fini();
    int SendData(char* buf, int buf_len);

private:
    Callback *m_callback;
};


#endif /* FRAMEWORK_MYSDK_IMPL_H_ */
