#include "writer.hpp"

#include <cstdlib>
#include <cstring>

#include <png.h>


using namespace xlib;


void writer::png( const image& data, const char* file )
{
    auto width  = data.width();
    auto height = data.height();

    png_image png;

    memset( &png, 0, ( sizeof png ) );

    png.version = PNG_IMAGE_VERSION;
    png.format  = PNG_FORMAT_RGBA;
    png.width   = width;
    png.height  = height;

    auto bytes = static_cast< png_bytep >( malloc( PNG_IMAGE_SIZE( png ) ) );

    for ( auto y = 0; y < height; ++y )
    {
        for ( auto x = 0; x < width; ++x )
        {
            auto i = width * y + x;

            const auto& p = data.get( x, y );

            bytes[ 4 * i     ] = p.red;
            bytes[ 4 * i + 1 ] = p.green;
            bytes[ 4 * i + 2 ] = p.blue;
            bytes[ 4 * i + 3 ] = p.alpha;
        }
    }

    png_image_write_to_file( &png, file, 0, bytes, 0, nullptr );

    free( bytes );
}
