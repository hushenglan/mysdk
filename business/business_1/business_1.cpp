/*
 * business_1.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1.h"
#include "business_1_impl.h"
#include <iostream>


int Business1::do_action(int param_1, int param_2, int param_3)
{
    return m_business1_impl->do_action(param_1, param_2, param_3);
}

