/*
 * demo_1.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#include "business_1.h"
#include <iostream>


class Busi1Callback : public Callback
{
    virtual void callback()
    {
        std::cout << "in Busi1Callback callback" << std::endl;
    }

    virtual void timeout()
    {
        std::cout << "in Busi1Callback timeout" << std::endl;
    }
};


int main(int argc, char *argv[])
{
    Business1 busi;
    Busi1Callback callback;

    busi.Init(callback);

    busi.do_action(1, 2, 3);
    busi.Update();

    return 0;
}
