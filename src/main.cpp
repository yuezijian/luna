#include "xlib/sdk.hpp"


int main( int argc, char* argv[] )
{
    xlib::canvas canvas;

    canvas.allocate( 23, 23 );

    xlib::pixel red  ( 1.0, 0.0, 0.0 );
    xlib::pixel green( 0.0, 1.0, 0.0 );
    xlib::pixel blue ( 0.0, 0.0, 1.0 );
    xlib::pixel white( 1.0, 1.0, 1.0 );

    xlib::int32 ox = 11;
    xlib::int32 oy = 11;

    canvas.line( 0 + ox, 0 + oy,  10 + ox,   0 + oy, red );
    canvas.line( 0 + ox, 0 + oy, -10 + ox,   0 + oy, red );
    canvas.line( 0 + ox, 0 + oy,   0 + ox,  10 + oy, red );
    canvas.line( 0 + ox, 0 + oy,   0 + ox, -10 + oy, red );

    canvas.line( 0 + ox, 0 + oy,  10 + ox,  10 + oy, green );
    canvas.line( 0 + ox, 0 + oy, -10 + ox,  10 + oy, green );
    canvas.line( 0 + ox, 0 + oy,  10 + ox, -10 + oy, green );
    canvas.line( 0 + ox, 0 + oy, -10 + ox, -10 + oy, green );

    canvas.line( 0 + ox, 0 + oy,  10 + ox,  5 + oy, blue );
    canvas.line( 0 + ox, 0 + oy, -10 + ox,  5 + oy, blue );
    canvas.line( 0 + ox, 0 + oy,  10 + ox, -5 + oy, blue );
    canvas.line( 0 + ox, 0 + oy, -10 + ox, -5 + oy, blue );

    canvas.line( 0 + ox, 0 + oy,  5 + ox,  10 + oy, white );
    canvas.line( 0 + ox, 0 + oy, -5 + ox,  10 + oy, white );
    canvas.line( 0 + ox, 0 + oy,  5 + ox, -10 + oy, white );
    canvas.line( 0 + ox, 0 + oy, -5 + ox, -10 + oy, white );

    canvas.write_image( "output.png" );

    return 0;
}
