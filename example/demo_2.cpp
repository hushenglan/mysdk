/*
 * demo_2.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_2.h"
#include <iostream>


class Demo2Callback : public Busi2Callback
{
    void callback(const struct Busi2CallbackParam& param)
    {
        std::cout << "in Demo2Callback callback, seq: " << param.seq <<
                                          ", is_need: " << param.is_need << std::endl;
    }

    void timeout(const struct Busi2CallbackParam& param)
    {
        std::cout << "in Demo2Callback timeout" << std::endl;
    }
};


int main(int argc, char *argv[])
{
    Demo2Callback callback;

    Business2 busi;
    busi.Init(&callback);

    Busi2ActionParam param;
    param.param_1 = "I ";
    param.param_2 = "am ";
    param.param_3 = "super man";
    busi.do_action(param);
    busi.Update();

    busi.Fini();

    return 0;
}



