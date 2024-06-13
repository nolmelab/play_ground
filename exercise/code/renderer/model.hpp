#pragma once

#include "math.hpp"

#include <string>
#include <vector>

struct TGAImage;

struct Face
{
    int v[3];

    Face(int v_1, int v_2, int v_3)
    {
        v[0] = v_1;
        v[1] = v_2;
        v[2] = v_3; 
    }

    int operator[](int index) const 
    {
        return v[index];
    }

    int& operator[](int index)
    {
        return v[index];
    }
};

/**
 * obj model format loader 
 */
struct Model 
{
    enum class Type 
    {
        WavefrontObj,
    };

    enum class Error 
    {
        Success,
        Error_FileNotFound, 
        Error_UnsupportedFormat
    };

    using Vec3f = glm::fvec3;

    std::vector<Face> faces;
    std::vector<Vec3f> verts;

    size_t nfaces() 
    {
        return faces.size();
    }

    size_t nverts()
    {
        return verts.size();
    }

    const Vec3f& vert(int index)
    {
        return verts[index];
    }

    // loads a model from filename of type 
    Error load(Type type, const std::string& filename);

    // loads a wavefront obj format model from filename
    Error load_wavefront_obj(const std::string& filename);
};
