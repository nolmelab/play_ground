#include <renderer/tgaimage.hpp>

void line_v1(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
{
    int wx = x1 - x0;
    int wy = y1 - y0;


    for ( float t= 0.f; t<1.f; t += 0.01f) 
    {
        float dx = wx * t;
        float dy = wy * t;
        int x = x0 + dx;
        int y = y0 + dy;
        image.set(x, y, color);
    }
}

void line_v2(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
{
    float wx = x1 - x0;

    for ( int x=x0; x<=x1; x++)
    {
        float rx = (x-x0) / wx;
        int y = y0 + (y1 - y0) * rx;
        image.set(x, y, color);
    }
}

void line_v3(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
{
    bool steep = false;
    float wx = x1 - x0;

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

    for ( int x=x0; x<=x1; x++)
    {
        float rx = (x-x0)/wx;
        int y = y0 + (y1 - y0) * rx;
        if (steep)
        {
            image.set(y, x, color);
        }
        else 
        {
            image.set(x, y, color);
        }
    }
}

// this is the best line drawing algorithm
void line_v4(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) 
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

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

int main()
{
    TGAImage image(128, 128, TGAImage::RGB);
    const int test_count = 1;
    for ( int i=0; i<test_count; ++i)
    {
        line_v4(13, 20, 80, 40, image, white);
        line_v4(20, 13, 40, 80, image, red);
        line_v4(80, 40, 13, 20, image, red);
    }
    image.write_tga_file("line_4.tga");
    
    return 0;
}