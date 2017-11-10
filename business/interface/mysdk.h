/*
 * mysdk.h
 *
 *  Created on: 2017年11月10日
 *      Author: bluehu
 */

#ifndef INTERFACE_MYSDK_H_
#define INTERFACE_MYSDK_H_


class Callback
{
public:
    Callback();
    virtual ~Callback();

    virtual void callback() = 0;
    virtual void timeout() = 0;
};


class MysdkImpl;
class Mysdk {
protected:
    int Init(const Callback& callback) {
        return m_mysdk_impl.Init(callback);
    }

    int Update() {
        return m_mysdk_impl.Update();
    }

private:
    MysdkImpl m_mysdk_impl;
};


#endif /* INTERFACE_MYSDK_H_ */
