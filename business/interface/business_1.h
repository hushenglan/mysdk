/*
 * business_1.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_BUSINESS_1_H_
#define INTERFACE_BUSINESS_1_H_


#include "mysdk.h"


class Business1Impl;


class Business1 : public Mysdk
{
public:
    int do_action(int param_1, int param_2, int param_3)
    {
        return m_business1_impl.do_action(param_1, param_2, param_3);
    }

private:
    Business1Impl m_business1_impl;
};


#endif /* INTERFACE_BUSINESS_1_H_ */
