#ifndef XLIB__BUFFER__HPP
#define XLIB__BUFFER__HPP


#include "type.hpp"

#include "pixel.hpp"


namespace xlib
{
    class canvas
    {
    public:
        ~canvas();

        void allocate( int32 width, int32 height );

        void plot( int32 x, int32 y, const pixel& data );

        void line( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data );

        void write_image( const char* file );

    private:
        void line_bresenham( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data );

        void line_dda( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data );

    private:
        pixel* _buffer = nullptr;

        int32 _width  = 0;
        int32 _height = 0;
    };
}


#endif
