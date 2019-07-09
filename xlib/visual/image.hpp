#ifndef XLIB__IMAGE__HPP
#define XLIB__IMAGE__HPP


#include "type.hpp"

#include "pixel.hpp"


namespace xlib
{
    class image
    {
    public:
        ~image();

        void allocate( int32 width, int32 height );

        inline void set( int32 x, int32 y, const pixel& data )
        {
            _buffer[ _width * y + x ] = data;
        }

        inline const pixel& get( int32 x, int32 y ) const
        {
            return _buffer[ _width * y + x ];
        }

        inline int32 width () const { return _width;  }
        inline int32 height() const { return _height; }

        inline const pixel* buffer() const { return _buffer; }

    private:
        pixel* _buffer = nullptr;

        int32 _width  = 0;
        int32 _height = 0;
    };
}


#endif
