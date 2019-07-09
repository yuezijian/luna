#ifndef XLIB__MATH__HPP
#define XLIB__MATH__HPP


#include <cmath>
#include <cstdlib>

#include "type.hpp"


namespace xlib
{
    class math
    {
    public:
        static inline float32 round_float32( float32 value )
        {
            return round( value );
        }

        static inline float64 round_float64( float64 value )
        {
            return round( value );
        }

        static inline int32 absolute_int32( int32 value )
        {
            return abs( value );
        }
    };
}


#endif
