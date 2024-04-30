#include <iostream>
#include <cmath>

int main(int argc, const char* argv[])
{
    std::string in;
    std::cin >> in;
    auto v = std::atof(in.c_str());
    std::cout << "sqrt of " << v << " is " << std::sqrt(v) << std::endl;

    return 0;
}