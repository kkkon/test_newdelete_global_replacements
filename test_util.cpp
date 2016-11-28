// Copyright(C) Kiyofumi Kondoh

#include "stdafx.h"

#if defined(MY_CHECK_FAIL_1)
//#define MY_USE_IMPLIMENT_CRT_MALLOCFREE
#define MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN
#include "mynewdelete.h"
#endif

#include "test_util.h"

#if 0
#if defined(_DEBUG)
#pragma comment(lib,"msvcrtd.lib")
#else
#pragma comment(lib,"msvcrt.lib")
#endif
#endif

#if 0
//#define MY_USE_IMPLIMENT_CRT_MALLOCFREE
#define MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN
#include "mynewdelete.h"
#endif

namespace test_util {


A::A()
{
    this->buff = new char[64];
}

A::~A()
{
    delete [] this->buff;
}

/*
void
A::setSize(size_t value)
{
    mValue.resize(value);
}
*/

bool
limit( std::vector<class A>& in )
{
    if ( in.empty() )
    {
        return false;
    }

    const size_t count = in.size();
    const size_t pos = (count/2);
    if ( 0 == pos )
    {
        return false;
    }

    std::vector<class A>::iterator it = in.begin();
    it += pos;
    in.erase( it );
    return true;
}

/*
AA::AA()
{
}
*/

AA::~AA()
{
}


bool
limit( std::vector<class AA>& in )
{
    if ( in.empty() )
    {
        return false;
    }

    const size_t count = in.size();
    const size_t pos = (count/2);
    if ( 0 == pos )
    {
        return false;
    }

    std::vector<class AA>::iterator it = in.begin();
    it += pos;
    in.erase( it );
    return true;
}







} // namespace test_util

