/*
 * business_2_impl.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_2_impl.h"
#include <iostream>


int Business2Impl::DoAction(const Busi2ActionParam& param)
{
    std::cout << "Business2Impl DoAction: " << param.param_1 << param.param_2 << param.param_3 << std::endl;
    return 0;
}


