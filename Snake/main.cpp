
#include <iostream>

#include "depend\glew\glew.h"
#include "depend\freeglut\freeglut.h"
#include "shaders\Shader.h"

#include "depend\glm\vec3.hpp"
#include "depend\glm\vec4.hpp"
#include "depend\glm\mat4x4.hpp"

#include "objects\menu\Box.h"
#include "objects\menu\Text.h"

#include "objects\test.h"
#include "objects\_util.h"

using namespace std;

// GLOBAL VARIABLES
bool enable_test = true;
Test *tester_object;

int window_x = 800;
int window_y = 800;

Shader default_shader, texture_shader;	// stores shader programs

void Initialize()
{
	// Prepare shaders
	default_shader = Shader("shaders\\vshader.glsl", "shaders\\fshader.glsl");
	texture_shader = Shader("shaders\\vtexshader.glsl", "shaders\\ftexshader.glsl");

	// Set up window size uniforms
	GLuint program = default_shader.GetProgram();

	// Provide each class with their respective shader programs
	Box::SetShader(default_shader);
	Text::SetShader(texture_shader);

	// Extra preparation
	Text::PrepareFT();

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Cleanup()
{
	delete tester_object;
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Send window length and width to default shader program
	glUniform1i(default_shader.GetX(), window_x);
	glUniform1i(default_shader.GetY(), window_y);
	glUniform1i(texture_shader.GetX(), window_x);
	glUniform1i(texture_shader.GetY(), window_y);

	if (enable_test)
	{
		tester_object->DisplayTest();
		//tester_object->BasicTestDisplay();
	}

	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		Cleanup();
		exit(EXIT_SUCCESS);
	}
}

void Reshape(GLsizei w, GLsizei h)
{
	window_x = w;
	window_y = h;
	glViewport(0, 0, w, h);
}

int main(int argc, char **argv) {

	// GLUT initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(window_x, window_y);
	glutCreateWindow("Snake");
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW failed to init");
		return 1;
	}

	// Initialization
	Initialize();

	// Testing
	if (enable_test)
	{
		Test::SetProgram(default_shader);
		tester_object = new Test();
		tester_object->SetupTest();
		//tester_object->BasicTest();
	}

	// Callback registration
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);

	glutMainLoop();

	return 0;
}