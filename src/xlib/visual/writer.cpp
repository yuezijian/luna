#include "writer.hpp"

#include <cstdlib>
#include <cstring>

#include <png.h>


using namespace xlib;


void writer::png( const char* file, uint32 width, uint32 height, const pixel* data )
{
    png_image image;

    memset( &image, 0, ( sizeof image ) );

    image.version = PNG_IMAGE_VERSION;
    image.width   = width;
    image.height  = height;
    image.format  = PNG_FORMAT_RGBA;

    auto bytes = static_cast< png_bytep >( malloc( PNG_IMAGE_SIZE( image ) ) );

    for ( auto y = 0; y < height; ++y )
    {
        for ( auto x = 0; x < width; ++x )
        {
            auto i = width * y + x;

            auto p = pixel_rgba_uint8( data[i] );

            bytes[ 4 * i     ] = p.red;
            bytes[ 4 * i + 1 ] = p.green;
            bytes[ 4 * i + 2 ] = p.blue;
            bytes[ 4 * i + 3 ] = p.alpha;
        }
    }

    png_image_write_to_file( &image, file, 0, bytes, 0, nullptr );

    free( bytes );
}
