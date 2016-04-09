#pragma once

#include "..\depend\glew\glew.h"
#include "..\depend\freeglut\freeglut.h"
#include <iostream>

class Shader
{
private:
	GLuint _program;
	GLuint _loc_x, _loc_y;
	bool _ready;

	std::string _ReadShader(char *filename);
	GLuint _CreateShader(GLenum shaderType, std::string source, char* shaderName);

public:
	Shader();
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename);
	~Shader();

	GLuint GetProgram();

	void CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename);
	void UseShader();
	GLuint GetX();
	GLuint GetY();
};
	

