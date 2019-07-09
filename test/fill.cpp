#include <xlib/sdk.hpp>


int main( int argc, char* argv[] )
{
    xlib::pixel white( 0xff, 0xff, 0xff );

    xlib::canvas canvas;

    canvas.size( 100, 100 );

    {
        xlib::int32 x1 = 10;
        xlib::int32 y1 = 30;

        xlib::int32 x2 = 30;
        xlib::int32 y2 = 10;

        xlib::int32 x3 = 40;
        xlib::int32 y3 = 50;

        canvas.fill( x1, y1, x2, y2, x3, y3, white );
    }

    {
        xlib::int32 x1 = 80;
        xlib::int32 y1 = 50;

        xlib::int32 x2 = 70;
        xlib::int32 y2 = 30;

        xlib::int32 x3 = 50;
        xlib::int32 y3 = 80;

        canvas.fill( x1, y1, x2, y2, x3, y3, white );
    }

    xlib::writer::png( canvas.data(), "test_fill.png" );

    xlib::viewer::show( canvas );

    return 0;
}
