#ifndef XLIB__WRITER__HPP
#define XLIB__WRITER__HPP


#include "image.hpp"


namespace xlib
{
    class writer
    {
    public:
        static void png( const image& data, const char* file );
    };
}


#endif
