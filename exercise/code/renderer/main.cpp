#include <renderer/tgaimage.h>

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

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

int main()
{
    TGAImage image(128, 128, TGAImage::RGB);
    line_v2(0, 0, 128, 128, image, red);
    line_v2(0, 1, 128, 127, image, red);
    line_v2(0, 100, 128, 118, image, red);
    image.write_tga_file("line_2.tga");
    
    return 0;
}