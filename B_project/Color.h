#pragma once
#include"Config.h"
namespace bf
{
	class Color
	{
    public:
        Color() :r(0), g(0), b(0), a(255) {}

        Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255) :r(red), g(green), b(blue), a(alpha) {}
        
        explicit Color(Uint32 color)
        {
            a = color & 0xff;
            b = color >> 8 & 0xff;
            g = color >> 16 & 0xff;
            r = color >> 24 & 0xff;
        }

        Uint32 toInteger() const
        {
            return a + b << 8 + g << 16 + r << 24;
        }

        static const Color Black;       ///< Black predefined color
        static const Color White;       ///< White predefined color
        static const Color Red;         ///< Red predefined color
        static const Color Green;       ///< Green predefined color
        static const Color Blue;        ///< Blue predefined color
        static const Color Yellow;      ///< Yellow predefined color
        static const Color Magenta;     ///< Magenta predefined color
        static const Color Cyan;        ///< Cyan predefined color
        static const Color Transparent; ///< Transparent (black) predefined color

        Uint8 r; ///< Red component
        Uint8 g; ///< Green component
        Uint8 b; ///< Blue component
        Uint8 a; ///< Alpha (opacity) component
	};
}
