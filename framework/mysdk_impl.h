/*
 * mysdk_impl.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef FRAMEWORK_MYSDK_IMPL_H_
#define FRAMEWORK_MYSDK_IMPL_H_


#include "mysdk.h"


class MysdkImpl
{
public:
    int Init(const Callback& callback);
    int Update();

private:
    Callback& m_callback;
};


#endif /* FRAMEWORK_MYSDK_IMPL_H_ */
