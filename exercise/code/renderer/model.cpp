#include "model.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Model::Error Model::load(Model::Type type, const std::string& filename)
{
    switch (type) 
    {
    case Type::WavefrontObj:
        return load_wavefront_obj(filename);
    }

    return Error::Error_UnsupportedFormat;
}

Model::Error Model::load_wavefront_obj(const std::string& filename)
{
    std::ifstream in;
    in.open (filename, std::ifstream::in);

    if (in.fail()) 
    {
        return Error::Error_FileNotFound;
    }

    std::string line;

    while (!in.eof()) 
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;
        if (!line.compare(0, 2, "v ")) 
        {
            iss >> trash; // v
            Vec3f v;
            iss >> v.x >> v.y >> v.z;
            verts.push_back(v);

            // std::cerr << line << " orig " << std::endl;
            // std::cerr << "v " << v.x << " " << v.y << " " << v.z << std::endl;
        } 
        else if (!line.compare(0, 2, "f ")) 
        {
            int itrash, v1, v2, v3;
            iss >> trash; // f 
            int fi = 0; 
            iss >> v1>> trash >> itrash >> trash >> itrash; // vertex, texture, normal
            iss >> v2>> trash >> itrash >> trash >> itrash;
            iss >> v3>> trash >> itrash >> trash >> itrash;

            Face f{--v1, --v2, --v3}; // obj index starts from 1
            faces.push_back(f);

            // std::cerr << line << " orig " << std::endl;
            // std::cerr << "f " << v1 << " " << v2 << " " << v3 << std::endl;
        }
        // vn : vertex normal 
        // vt : texuture coord
    }

    std::cerr << "# v# " << verts.size() << " f# "  << faces.size() << std::endl;

    return Error::Success;
}
