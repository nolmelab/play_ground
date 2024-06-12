#pragma once

#include "tgaimage.hpp"
#include "math.hpp"

#include <algorithm>

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
        if (error > 0.5f)
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

inline void triangle_v1(const Vec2i& v0, const Vec2i& v1, const Vec2i& v2, TGAImage& image, TGAColor color)
{
    line(v0.x, v0.y, v1.x, v1.y, image, color);
    line(v1.x, v1.y, v2.x, v2.y, image, color);
    line(v2.x, v2.y, v0.x, v0.y, image, color);
}

inline void triangle_v2(const Vec2i& v0, const Vec2i& v1, const Vec2i& v2, TGAImage& image, TGAColor color)
{
    if (v0.y > v1.y) std::swap(v0, v1);
    if (v0.y > v2.y) std::swap(v0, v2);
    if (v1.y > v2.y) std::swap(v1, v2);

    line(v0.x, v0.y, v1.x, v1.y, image, color);
    line(v1.x, v1.y, v2.x, v2.y, image, color);
    line(v2.x, v2.y, v0.x, v0.y, image, color);
}

void triangle_v3(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color) 
{ 
    // sort the vertices, t0, t1, t2 lower−to−upper (bubblesort yay!) 
    if (t0.y>t1.y) std::swap(t0, t1); 
    if (t0.y>t2.y) std::swap(t0, t2); 
    if (t1.y>t2.y) std::swap(t1, t2); 
    int total_height = t2.y-t0.y; 
    for (int y=t0.y; y<=t1.y; y++) { 
        int segment_height = t1.y-t0.y+1; 
        float alpha = (float)(y-t0.y)/total_height; 
        float beta  = (float)(y-t0.y)/segment_height; // be careful with divisions by zero 
        Vec2i A = t0 + (t2-t0)*alpha; 
        Vec2i B = t0 + (t1-t0)*beta; 
        if (A.x>B.x) std::swap(A, B); 
        for (int j=A.x; j<=B.x; j++) { 
            image.set(j, y, color); // attention, due to int casts t0.y+i != A.y 
        } 
    } 
    for (int y=t1.y; y<=t2.y; y++) { 
        int segment_height =  t2.y-t1.y+1; 
        float alpha = (float)(y-t0.y)/total_height; 
        float beta  = (float)(y-t1.y)/segment_height; // be careful with divisions by zero 
        Vec2i A = t0 + (t2-t0)*alpha; 
        Vec2i B = t1 + (t2-t1)*beta; 
        if (A.x>B.x) std::swap(A, B); 
        for (int j=A.x; j<=B.x; j++) { 
            image.set(j, y, color); // attention, due to int casts t0.y+i != A.y 
        } 
    } 
}

inline void triangle(const Vec2i& v0, const Vec2i& v1, const Vec2i& v2, TGAImage& image, TGAColor color)
{
    triangle_v1(v0, v1, v2, image, color);
}

