#ifndef XLIB__PIXEL__HPP
#define XLIB__PIXEL__HPP


#include "type.hpp"


namespace xlib
{
    struct pixel
    {
        uint8 red;
        uint8 green;
        uint8 blue;
        uint8 alpha;

        pixel() : red( 0 ), green( 0 ), blue( 0 ), alpha( 255 )
        {
        }

        pixel( uint8 r, uint8 g, uint8 b, uint8 a = 255 ) : red( r ), green( g ), blue( b ), alpha( a )
        {
        }
    };
}


#endif
