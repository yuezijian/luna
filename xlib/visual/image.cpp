#include "image.hpp"


using namespace xlib;


image::~image()
{
    if ( _buffer )
    {
        delete[] _buffer;

        _buffer = nullptr;
    }
}

void image::allocate( int32 width, int32 height )
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
