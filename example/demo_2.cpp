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
    void callback(struct Busi2CallbackParam *param)
    {
        std::cout << "in Demo2Callback callback, seq: " << param->seq <<
                                          ", is_need: " << param->is_need << std::endl;
    }

    void timeout(struct Busi2CallbackParam *param)
    {
        std::cout << "in Demo2Callback timeout" << std::endl;
    }
};


int main(int argc, char *argv[])
{
    Business2 busi;
    Demo2Callback callback;

    busi.Init(&callback);

    busi.do_action("I ", "am ", "super man");
    busi.Update();
    busi.Fini();

    return 0;
}



