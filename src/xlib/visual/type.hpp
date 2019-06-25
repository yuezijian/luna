#ifndef XLIB__TYPE__HPP
#define XLIB__TYPE__HPP


namespace xlib
{
    typedef unsigned char uint8;
    typedef unsigned int  uint32;

    typedef int    int32;
    typedef float  float32;
    typedef double float64;

    class type
    {
    public:
        template < typename ts, typename td >
        static td to_type( ts value )
        {
            return static_cast< td >( value );
        }
    };
}


#endif
