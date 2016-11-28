// Copyright(C) Kiyofumi Kondoh

#pragma once

#include <new>
#include <malloc.h>
#include <assert.h>

#if defined(MY_USE_IMPLIMENT_CRT_MALLOCFREE)
static
inline
void* operator new(size_t size)
{
    return ::malloc(size);
}

static
inline
void operator delete(void* p)
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_msize( p );
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
#endif // defined(_MSC_VER)
    ::free(p);
}

static
inline
void* operator new[](size_t size)
{
    return ::malloc(size);
}

static
inline
void operator delete[](void* p)
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_msize( p );
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
#endif // defined(_MSC_VER)
    ::free(p);
}

#endif // defined(MY_USE_IMPLIMENT_CRT_MALLOCFREE)


#if defined(MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN)
#define     MY_ALLOC_ALIGN      8

#if 1
static
inline
void* operator new(size_t size)
{
    void* p;
#if defined(_MSC_VER)
    p = ::_aligned_malloc( size, MY_ALLOC_ALIGN );
#if defined(_WIN32) && defined(MY_DISP_LOG)
    {
        char buff[256];
        ::wsprintfA( buff, "op new %p %u\n", p, size );
        ::OutputDebugStringA( buff );
    }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
#endif // defined(_MSC_VER)

    return p;
}

static
inline
void operator delete(void* p)
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_aligned_msize( p, MY_ALLOC_ALIGN, 0 );
#if defined(_WIN32) && defined(MY_DISP_LOG)
        {
            char buff[256];
            ::wsprintfA( buff, "op del %p %u\n", p, size );
            ::OutputDebugStringA( buff );
        }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
    ::_aligned_free( p );
#endif // defined(_MSC_VER)
}
#endif

#if 0
static
inline
void* operator new(size_t size) throw(std::bad_alloc)
{
    void* p;
#if defined(_MSC_VER)
    p = ::_aligned_malloc( size, MY_ALLOC_ALIGN );
#if defined(_WIN32) && defined(MY_DISP_LOG)
    {
        char buff[256];
        ::wsprintfA( buff, "op new %p %u\n", p, size );
        ::OutputDebugStringA( buff );
    }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
#endif // defined(_MSC_VER)

    return p;
}

static
inline
void operator delete(void* p) throw()
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_aligned_msize( p, MY_ALLOC_ALIGN, 0 );
#if defined(_WIN32) && defined(MY_DISP_LOG)
        {
            char buff[256];
            ::wsprintfA( buff, "op del %p %u\n", p, size );
            ::OutputDebugStringA( buff );
        }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
    ::_aligned_free( p );
#endif // defined(_MSC_VER)
}
#endif


#if 0
static
inline
void* operator new[](size_t size) throw(std::bad_alloc)
{
    void* p;
#if defined(_MSC_VER)
    p = ::_aligned_malloc( size, MY_ALLOC_ALIGN );
#if defined(_WIN32) && defined(MY_DISP_LOG)
    {
        char buff[256];
        ::wsprintfA( buff, "op new[] %p %u\n", p, size );
        ::OutputDebugStringA( buff );
    }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
#endif // defined(_MSC_VER)

    return p;
}

static
inline
void operator delete[](void* p) throw()
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_aligned_msize( p, MY_ALLOC_ALIGN, 0 );
#if defined(_WIN32) && defined(MY_DISP_LOG)
        {
            char buff[256];
            ::wsprintfA( buff, "op del[] %p %u\n", p, size );
            ::OutputDebugStringA( buff );
        }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
    ::_aligned_free( p );
#endif // defined(_MSC_VER)
}
#endif

#if 1
static
inline
void* operator new[](size_t size)
{
    void* p;
#if defined(_MSC_VER)
    p = ::_aligned_malloc( size, MY_ALLOC_ALIGN );
#endif // defined(_MSC_VER)
#if defined(_WIN32) && defined(MY_DISP_LOG)
    {
        char buff[256];
        ::wsprintfA( buff, "op new[] %p %u\n", p, size );
        ::OutputDebugStringA( buff );
    }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)

    return p;
}


static
inline
void operator delete[](void* p)
{
#if defined(_MSC_VER)
    {
        const size_t size = ::_aligned_msize( p, MY_ALLOC_ALIGN, 0 );
#if defined(_WIN32) && defined(MY_DISP_LOG)
        {
            char buff[256];
            ::wsprintfA( buff, "op del[] %p %u\n", p, size );
            ::OutputDebugStringA( buff );
        }
#endif // defined(_WIN32) && defined(MY_DISP_LOG)
        if ( (size_t)-1 == size )
        {
            assert(0);
        }
    }
    ::_aligned_free( p );
#endif // defined(_MSC_VER)
}
#endif



#endif // defined(MY_USE_IMPLIMENT_CRT_MALLOCFREE_ALIGN)

