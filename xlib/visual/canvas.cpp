#include "canvas.hpp"

#include "math.hpp"
#include "writer.hpp"


using namespace xlib;


#define absolute math::absolute_int32
#define round    math::round_float64


void swap_int32( int32& a, int32& b )
{
    if ( a != b )
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}


void canvas::size( int32 width, int32 height )
{
    _image.allocate( width, height );
}

void canvas::plot( int32 x, int32 y, const pixel& color )
{
    if ( 0 <= x && x < _image.width() && 0 <= y && y < _image.height() )
    {
        _image.set( x, _image.height() - y - 1, color );
    }
}

void canvas::line( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color )
{
    #if 1
    this->line_bresenham( x1, y1, x2, y2, color );
    #else
    this->line_dda( x1, y1, x2, y2, color );
    #endif
}

void canvas::fill( int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, const pixel& color )
{
    if ( y1 > y2 )
    {
        swap_int32( x1, x2 );
        swap_int32( y1, y2 );
    }

    if ( y1 > y3 )
    {
        swap_int32( x1, x3 );
        swap_int32( y1, y3 );
    }

    if ( y2 > y3 )
    {
        swap_int32( x2, x3 );
        swap_int32( y2, y3 );
    }

    if ( y1 == y2 )
    {
        if ( x1 < x2 )
        {
            this->fill_triangle_flat_bottom( x3, y3, x1, x2, y2, color );
        }
        else
        {
            this->fill_triangle_flat_bottom( x3, y3, x2, x1, y2, color );
        }
    }
    else if ( y2 == y3 )
    {
        if ( x2 < x3 )
        {
            this->fill_triangle_flat_top( x1, y1, x2, x3, y2, color );
        }
        else
        {
            this->fill_triangle_flat_top( x1, y1, x3, x2, y2, color );
        }
    }
    else
    {
        auto dx31 = ( float64 )( x3 - x1 );
        auto dy21 = ( float64 )( y2 - y1 );
        auto dy31 = ( float64 )( y3 - y1 );

        auto x4 = ( int32 )( round( x1 + dy21 / dy31 * dx31 ) );

        if ( x2 < x4 )
        {
            this->fill_triangle_flat_bottom( x3, y3, x2, x4, y2, color );
            this->fill_triangle_flat_top   ( x1, y1, x2, x4, y2, color );
        }
        else
        {
            this->fill_triangle_flat_bottom( x3, y3, x4, x2, y2, color );
            this->fill_triangle_flat_top   ( x1, y1, x4, x2, y2, color );
        }

    }
}

void canvas::line_bresenham( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color )
{
    auto dx = x2 - x1;
    auto dy = y2 - y1;

    auto adx = absolute( dx );
    auto ady = absolute( dy );

    auto ddx = adx * 2;
    auto ddy = ady * 2;

    auto x = x1;
    auto y = y1;

    auto tx = x1 < x2 ? 1 : -1;
    auto ty = y1 < y2 ? 1 : -1;

    if ( adx < ady )
    {
        auto e = -ady;

        for ( auto i = 0; i <= ady; ++i )
        {
            this->plot( x, y, color );

            y += ty;
            e += ddx;

            if ( e > 0 )
            {
                x += tx;
                e -= ddy;
            }
        }
    }
    else
    {
        auto e = -adx;

        for ( auto i = 0; i <= adx; ++i )
        {
            this->plot( x, y, color );

            x += tx;
            e += ddy;

            if ( e > 0 )
            {
                y += ty;
                e -= ddx;
            }
        }
    }
}

void canvas::line_dda( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& color )
{
    // Digital Differential Analyzer

    int32 dx = x2 - x1;
    int32 dy = y2 - y1;

    int32 steps = 0;

    if ( absolute( dx ) < absolute( dy ) )
    {
        steps = absolute( dy );
    }
    else
    {
        steps = absolute( dx );
    }

    auto ix = ( float64 )( dx ) / ( float64 )( steps );
    auto iy = ( float64 )( dy ) / ( float64 )( steps );

    auto x = ( float64 )( x1 );
    auto y = ( float64 )( y1 );

    for ( auto i = 0; i <= steps; ++i )
    {
        this->plot( round( x ), round( y ), color );

        x += ix;
        y += iy;
    }
}

void canvas::fill_horizontal( int32 x1, int32 x2, int32 y, const pixel& color )
{
    for ( auto x = x1; x <= x2; ++x )
    {
        this->plot( x, y, color );
    }
}

void canvas::fill_triangle_flat_bottom( int32 xt, int32 yt, int32 x1, int32 x2, int32 yb, const pixel& color )
{
    auto dx_min = ( float64 )( x1 - xt );
    auto dx_max = ( float64 )( x2 - xt );

    auto dy = ( float64 )( yb - yt );

    auto x_min = ( float64 )( x1 );
    auto x_max = ( float64 )( x2 );

    auto ix_min = dx_min / dy;
    auto ix_max = dx_max / dy;

    for ( auto y = yb; y <= yt; ++y )
    {
        this->fill_horizontal( round( x_min ), round( x_max ), y, color );

        x_min += ix_min;
        x_max += ix_max;
    }
}

void canvas::fill_triangle_flat_top( int32 xb, int32 yb, int32 x1, int32 x2, int32 yt, const pixel& color )
{
    auto dx_min = ( float64 )( x1 - xb );
    auto dx_max = ( float64 )( x2 - xb );

    auto dy = ( float64 )( yt - yb );

    auto x_min = ( float64 )( x1 );
    auto x_max = ( float64 )( x2 );

    auto ix_min = dx_min / dy;
    auto ix_max = dx_max / dy;

    for ( auto y = yt; y >= 0; --y )
    {
        this->fill_horizontal( round( x_min ), round( x_max ), y, color );

        x_min -= ix_min;
        x_max -= ix_max;
    }
}
