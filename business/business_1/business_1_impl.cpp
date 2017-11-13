/*
 * business_1_impl.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1_impl.h"
#include <iostream>
#include <cstdio>


int Business1Impl::Init(int param_1, int param_2)
{
    /*
     * 此business单独的一些初始化，可以利用framework里面的组件
     */
    printf("in Business1Impl::Init, param_1: %d, param_2: %d\n", param_1, param_2);

    return 0;
}

int Business1Impl::DoAction(int param_1, int param_2, int param_3)
{
    std::cout << "Business1Impl DoAction: " << param_1 + param_2 + param_3 << std::endl;
    return 0;
}

