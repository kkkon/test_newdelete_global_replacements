// Copyright(C) Kiyofumi Kondoh

#pragma once

#include <vector>
#include <string>

namespace test_util {

class A {
public:
    A();
    A(const A &r);
    virtual ~A();

    A& operator=(const A &r)
    {
        if ( this != &r )
        {
            memcpy(this->buff, r.buff, 64);
        }
        return *this;
    }

public:
    void setSize(size_t value)
    {
        //mValue.resize(value);
    }

    void push_back(const std::string& in);

protected:
    char*    buff;
}; // class A

bool
limit( std::vector<class A>& in );

class AA {
public:
    AA() { }
    virtual ~AA();

public:
    void setSize(size_t value)
    {
        mA[0].setSize(value);
        mA[1].setSize(value);
        mA[2].setSize(value);
    }

    void push_back(const std::string& in);

protected:
    class A mA[3];
}; // class AA

bool
limit( std::vector<class AA>& in );

} // namespace test_util

