#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "shaders.h"

Shader::Shader(int id) : id(id){
}

Shader::~Shader(){
    glDeleteProgram(id);
}

Shader* download(std::string vertexFile, std::string fragmentFile) {
    std::string verCode;
    std::string fragCode;
    std::ifstream fileVertex;
    std::ifstream fileShader;


    fileVertex.open(vertexFile);
    fileShader.open(fragmentFile);
    std::stringstream vertexShader, fragmentShader;

    vertexShader << fileVertex.rdbuf();
    fragmentShader << fileShader.rdbuf();

    fileVertex.close();
    fileShader.close();

    verCode = vertexShader.str();
    fragCode = fragmentShader.str();

    const GLchar* vertexCode = verCode.c_str();
    const GLchar* fragmentCode = fragCode.c_str();

    GLuint vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, nullptr);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, nullptr);
    glCompileShader(fragment);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);


    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return new Shader(program);
}