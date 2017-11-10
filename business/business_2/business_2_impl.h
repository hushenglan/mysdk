/*
 * business2_impl.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef BUSINESS_BUSINESS_2_BUSINESS2_IMPL_H_
#define BUSINESS_BUSINESS_2_BUSINESS2_IMPL_H_


#include "business_2.h"


class Business2Impl : public Business2
{
public:
    int do_action(const std::string& param_1, const std::string& param_2, const std::string& param_3);
};


#endif /* BUSINESS_BUSINESS_2_BUSINESS2_IMPL_H_ */
