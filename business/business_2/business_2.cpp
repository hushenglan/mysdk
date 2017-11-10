/*
 * business_2.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_2.h"
#include <iostream>


int Business2::do_action(int param_1, int param_2, int param_3)
{
    return m_business2_impl->do_action(param_1, param_2, param_3);
}

