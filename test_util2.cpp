// Copyright(C) Kiyofumi Kondoh

#include "stdafx.h"

#if defined(MY_CHECK_FAIL_2)
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

A::A(const A &r)
{
    this->buff = new char[64];
    this->buff[0] = r.buff[0];
}

void
A::push_back(const std::string& in)
{
    this->buff[0] = reinterpret_cast<size_t>(in.c_str());
}


void
AA::push_back(const std::string& in)
{
    mA[0].push_back( in );
    mA[1].push_back( in );
    mA[2].push_back( in );
}





} // namespace test_util

