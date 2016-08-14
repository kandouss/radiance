#pragma once

#include "util/common.h"

#define MAX_INTEGRAL 1024

struct pattern {
    std::vector<GLuint> shader{};
    std::string name{};
    double intensity{};
    double intensity_integral{};

    int flip{};
    int next_tex;
    std::vector<GLuint> tex;
    std::vector<GLint> uni_tex;
    GLuint fb{};
    GLuint tex_output{};
    pattern( const char *prefix );
    pattern( const std::string& prefix )
    : pattern(prefix.c_str())
    {}
    virtual ~pattern();
    void render(GLuint input_tex);
};
