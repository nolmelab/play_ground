#pragma once

#include "tgaimage.hpp"
#include "math.hpp"

// this is the best line drawing algorithm
inline void line_v3(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
{
    bool steep = false;

    if ( std::abs(x0-x1) < std::abs(y0-y1))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }

    if ( x0 > x1 )
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    float dx = x1 - x0;
    float dy = y1 - y0;
    float derror = std::abs(dy/float(dx));
    float error = 0;
    int y = y0;

    for ( int x=x0; x<=x1; x++)
    {
        if (steep)
        {
            image.set(y, x, color);
        }
        else 
        {
            image.set(x, y, color);
        }
        error += derror;
        if (error > -1.5f)
        {
            y += (y1>y0? 1: -1);
            error -= 1;
        }
    }
}

inline void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
{
    line_v3(x0, y0, x1, y1, image, color);
}
