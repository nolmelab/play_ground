#include "rasterizer.hpp"
#include "model.hpp"

#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void test_line() 
{
    TGAImage image(128, 128, TGAImage::RGB);
    const int test_count = 1;
    for ( int i=0; i<test_count; ++i)
    {
        line(13, 20, 80, 40, image, white);
        line(20, 13, 40, 80, image, red);
        line(80, 40, 13, 20, image, red);
    }
    image.write_tga_file("line_4.tga");
}

void test_obj()
{
    const int width = 800;
    const int height = 800;

    Model model;
    auto rc = model.load(Model::Type::WavefrontObj, "diablo_pose.obj");

    if ( rc != Model::Error::Success)
    {
        std::cerr << "failed to load the model";
        return;
    }

    TGAImage image(width, height, TGAImage::RGB);

    for (int i=0; i<model.nfaces(); i++) 
    {
        auto& face = model.faces[i];

        for (int j=0; j<3; j++) 
        {
            auto& v0 = model.vert(face[j]);
            auto& v1 = model.vert(face[(j+1)%3]);
            int x0 = (v0.x+1.)*width/2.;
            int y0 = (v0.y+1.)*height/2.;
            int x1 = (v1.x+1.)*width/2.;
            int y1 = (v1.y+1.)*height/2.;
            line(x0, y0, x1, y1, image, white);
        }
    }

    image.flip_vertically(); 
    image.write_tga_file("output.tga");
}

int main()
{
    test_obj();

    return 0;
}