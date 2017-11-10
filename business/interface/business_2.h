/*
 * business_2.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_BUSINESS_2_H_
#define INTERFACE_BUSINESS_2_H_

#include "mysdk.h"
#include <string>


class Business2Impl;


class Business2 : public Mysdk
{
public:
    int do_action(const std::string& param_1, const std::string& param_2, const std::string& param_3);

private:
    Business2Impl *m_business2_impl;
};


#endif /* INTERFACE_BUSINESS_2_H_ */
