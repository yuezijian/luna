#ifndef XLIB__WRITER__HPP
#define XLIB__WRITER__HPP


#include "type.hpp"

#include "pixel.hpp"


namespace xlib
{
    class writer
    {
    public:
        static void png( const char* file, uint32 width, uint32 height, const pixel* data );
    };
}


#endif
