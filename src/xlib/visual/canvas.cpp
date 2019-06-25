#include "canvas.hpp"

#include "math.hpp"
#include "writer.hpp"


using namespace xlib;


canvas::~canvas()
{
    if ( _buffer )
    {
        delete[] _buffer;

        _buffer = nullptr;
    }
}

void canvas::allocate( int32 width, int32 height )
{
    if ( width == _width && height == _height )
    {
        return;
    }

    if ( _buffer )
    {
        delete[] _buffer;

        _buffer = nullptr;
    }

    _buffer = new pixel[ width * height ];

    _width  = width;
    _height = height;
}

void canvas::plot( int32 x, int32 y, const pixel& data )
{
    y = _height - y - 1;

    if ( 0 <= x && x < _width && 0 <= y && y < _height )
    {
        auto i = _width * y + x;

        _buffer[ i ] = data;
    }
}

void canvas::line( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data )
{
    #if 1
    this->line_bresenham( x1, y1, x2, y2, data );
    #else
    this->line_dda( x1, y1, x2, y2, data );
    #endif
}

void canvas::write_image( const char* file )
{
    writer::png( file, _width, _height, _buffer );
}

void canvas::line_bresenham( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data )
{
    #define absolute math::absolute_int32

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
        auto e = dy < 0 ? dy : -dy;

        for ( auto i = 0; i <= ady; ++i )
        {
            this->plot( x, y, data );

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
        auto e = dx < 0 ? dx : -dx;

        for ( auto i = 0; i <= adx; ++i )
        {
            this->plot( x, y, data );

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

void canvas::line_dda( int32 x1, int32 y1, int32 x2, int32 y2, const pixel& data )
{
    // Digital Differential Analyzer

    #define absolute math::absolute_int32
    #define round    math::round_float64

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
        this->plot( round( x ), round( y ), data );

        x += ix;
        y += iy;
    }
}
