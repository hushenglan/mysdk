/*
 * demo_2.cpp
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */


#include "business_2.h"
#include <iostream>


class Busi2Callback : public Callback
{
    virtual void callback()
    {
        std::cout << "in Busi2Callback callback" << std::endl;
    }

    virtual void timeout()
    {
        std::cout << "in Busi2Callback timeout" << std::endl;
    }
};


int main(int argc, char *argv[])
{
    Business2 busi;
    Busi2Callback callback;

    busi.Init(&callback);

    busi.do_action("I ", "am ", "super man");
    busi.Update();

    return 0;
}



