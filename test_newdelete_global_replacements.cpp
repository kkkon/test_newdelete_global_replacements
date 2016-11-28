// test_newdelete_global_replacements.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#if defined(MY_CHECK_FAIL_0)
//#define MY_USE_IMPLIMENT_CRT_MALLOCFREE
#define MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN
#include "mynewdelete.h"
#endif

#if 1
#include <vector>

#include "test_util.h"
#endif

#if 0
//#define MY_USE_IMPLIMENT_CRT_MALLOCFREE
#define MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN
#include "mynewdelete.h"
#endif

#if defined(_MSC_VER)
#include <crtdbg.h>
#endif // defined(_MSC_VER)


int _tmain(int argc, _TCHAR* argv[])
{
#if defined(_MSC_VER)
#if defined(_DEBUG)
    {
        int value = ::_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
        value |= _CRTDBG_ALLOC_MEM_DF;
        value |= _CRTDBG_LEAK_CHECK_DF;
        ::_CrtSetDbgFlag(value);
    }
#endif // defined(_DEBUG)
#endif // defined(_MSC_VER)

    {
        int* temp = new int[128];

        delete [] temp;
    }

  size_t loop1Count = 128*1024;

  for ( size_t loop1 = 0; loop1 < loop1Count; ++loop1 )
  {
#if 1

#if defined(_WIN32)
    if ( 0 == (loop1%1024) )
    {
        char buff[64];
        ::wsprintfA( buff, "loop=0x%08X\n", loop1 );
        ::OutputDebugStringA( buff );
        printf( "%s", buff );
    }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)



#if defined(_WIN32) && defined(MY_DISP_LOG)
    ::OutputDebugStringA( "\n" );
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
    {
        std::vector<std::string>    test;
        test.push_back( "hoge" );
    }



#if defined(_WIN32) && defined(MY_DISP_LOG)
    ::OutputDebugStringA( "\n" );
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
    {
        std::vector<test_util::A>    test;
        test_util::A a1,a2;
        a1.setSize(5);
        a2.setSize(3);
        test.push_back( a1 );
        test.push_back( a2 );
        test_util::limit( test );
    }


#if defined(_WIN32) && defined(MY_DISP_LOG)
    ::OutputDebugStringA( "\n" );
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
    {
        std::vector<test_util::A>    test;
        test_util::A a1,a2;
        a1.setSize(5);
        a2.setSize(3);
        a1.push_back( std::string("hoge") );
        a1.push_back( std::string("moge") );
        a2.push_back( std::string("moge") );
        a2.push_back( std::string("hoge") );
        test.push_back( a1 );
        test.push_back( a2 );
        test_util::limit( test );
    }


#if defined(_WIN32) && defined(MY_DISP_LOG)
    ::OutputDebugStringA( "\n" );
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
    {
        std::vector<test_util::AA>    test;
        test_util::AA aa1,aa2;
        aa1.setSize(5);
        aa2.setSize(3);
        test.push_back( aa1 );
        test.push_back( aa2 );
        test_util::limit( test );
    }


#if defined(_WIN32) && defined(MY_DISP_LOG)
    ::OutputDebugStringA( "\n" );
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
    {
        std::vector<test_util::AA>    test;
        test_util::AA aa1,aa2;
        aa1.setSize(5);
        aa2.setSize(3);
        aa1.push_back( std::string("hoge") );
        aa1.push_back( std::string("moge") );
        aa2.push_back( std::string("moge") );
        aa2.push_back( std::string("hoge") );
        test.push_back( aa1 );
        test.push_back( aa2 );
        test_util::limit( test );
    }













#endif
  } // loop1


    if ( ::IsDebuggerPresent() )
    {
        ::DebugBreak();
    }

	return 0;
}

