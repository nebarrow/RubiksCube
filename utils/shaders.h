#ifndef LABA8_SHADERS_H
#define LABA8_SHADERS_H
#include <iostream>

class Shader {
public:
    int id;
    Shader(int id);
    ~Shader();
};

extern Shader* download(std::string vertex, std::string fragment);

#endif
