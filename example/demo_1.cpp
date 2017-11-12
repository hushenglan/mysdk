/*
 * demo_1.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1.h"
#include <iostream>


class Demo1Callback : public Busi1Callback
{
    void callback(struct Busi1CallbackParam *param)
    {
        std::cout << "in Demo1Callback callback, seq: " << param->seq <<
                                            ", result: " << param->result <<
                                            ", msg: " << param->msg << std::endl;
    }

    void timeout(struct Busi1CallbackParam *param)
    {
        std::cout << "in Demo1Callback timeout" << std::endl;
    }
};


int main(int argc, char *argv[])
{
    Demo1Callback callback;

    Business1 busi;
    busi.Init(&callback, 200, 201);

    busi.do_action(1, 2, 3);
    busi.Update();

    busi.Fini();

    return 0;
}
