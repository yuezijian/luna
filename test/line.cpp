#include <xlib/sdk.hpp>


int main( int argc, char* argv[] )
{
    xlib::pixel red  ( 0xff, 0x00, 0x00 );
    xlib::pixel green( 0x00, 0xff, 0x00 );
    xlib::pixel blue ( 0x00, 0x00, 0xff );
    xlib::pixel white( 0xff, 0xff, 0xff );

    xlib::canvas canvas;

    canvas.size( 23, 23 );

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

    xlib::writer::png( canvas.data(), "test_line.png" );

    xlib::viewer::show( canvas );

    return 0;
}
