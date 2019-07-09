#ifndef XLIB__CANVAS__HPP
#define XLIB__CANVAS__HPP


#include "image.hpp"


namespace xlib
{
    class canvas
    {
    public:
        void size( int32 width, int32 height );

        void plot( int32 x, int32 y, const pixel& color );

        void line( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color );

        void fill( int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, const pixel& color );

        inline const image& data() const { return _image; }

    private:
        void line_bresenham( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color );
        void line_dda      ( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color );

        void fill_horizontal( int32 x1, int32 x2, int32 y, const pixel& color );

        void fill_triangle_flat_bottom( int32 xt, int32 yt, int32 x1, int32 x2, int32 yb, const pixel& color );
        void fill_triangle_flat_top   ( int32 xb, int32 yb, int32 x1, int32 x2, int32 yt, const pixel& color );

    private:
        image _image;
    };
}


#endif
