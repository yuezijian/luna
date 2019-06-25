#ifndef XLIB__PIXEL__HPP
#define XLIB__PIXEL__HPP


#include "math.hpp"


namespace xlib
{
    typedef unsigned char uint8;
    typedef unsigned int  uint32;

    typedef double float64;

    struct pixel_rgba_float64
    {
        pixel_rgba_float64() : red( 0.0 ), green( 0.0 ), blue( 0.0 ), alpha( 1.0 )
        {
        }

        pixel_rgba_float64( float64 r, float64 g, float64 b, float64 a = 1.0 ) : red( r ), green( g ), blue( b ), alpha( a )
        {
        }

        float64 red;
        float64 green;
        float64 blue;
        float64 alpha;
    };

    struct pixel_rgba_uint8
    {
        pixel_rgba_uint8() : red( 0 ), green( 0 ), blue( 0 ), alpha( 255 )
        {
        }

        pixel_rgba_uint8( uint8 r, uint8 g, uint8 b, uint8 a = 255 ) : red( r ), green( g ), blue( b ), alpha( a )
        {
        }

        explicit pixel_rgba_uint8( const pixel_rgba_float64& p )
        {
            red   = type::to_type< float64, uint8 >( math::round_float64( 255.0 * p.red   ) );
            green = type::to_type< float64, uint8 >( math::round_float64( 255.0 * p.green ) );
            blue  = type::to_type< float64, uint8 >( math::round_float64( 255.0 * p.blue  ) );
            alpha = type::to_type< float64, uint8 >( math::round_float64( 255.0 * p.alpha ) );
        }

        uint8 red;
        uint8 green;
        uint8 blue;
        uint8 alpha;
    };

    typedef pixel_rgba_float64 pixel;
}

#endif
