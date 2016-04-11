
#include <iostream>

#include "depend\glew\glew.h"
#include "depend\freeglut\freeglut.h"
#include "shaders\Shader.h"

#include "depend\glm\vec3.hpp"
#include "depend\glm\vec4.hpp"
#include "depend\glm\mat4x4.hpp"

#include "objects\basic\Box.h"
#include "objects\basic\Text.h"
#include "objects\GameManager.h"

#include "objects\test.h"
#include "objects\_util.h"
#include "objects\_macro.h"

using namespace std;

// GLOBAL VARIABLES
bool enable_test = false;
Test *tester_object = NULL;
bool reset_pause = false;

GameManager *manager;

int window_x = 800;
int window_y = 800;

Shader default_shader, texture_shader;	// stores shader programs

void Initialize()
{
	// Prepare shaders
	default_shader = Shader("shaders\\vshader.glsl", "shaders\\fshader.glsl");
	texture_shader = Shader("shaders\\vtexshader.glsl", "shaders\\ftexshader.glsl");

	// Provide each class with their respective shader programs
	Box::SetShader(default_shader);
	Text::SetShader(texture_shader);

	// Extra preparation
	Box::Prepare();
	Text::Prepare();

	// GameManager preparation
	manager = new GameManager();

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Cleanup()
{
	if (enable_test)
		delete tester_object;

	Box::Cleanup();
	Text::Cleanup();

	delete manager;
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Send window length and width to shader programs
	glUniform1i(default_shader.GetX(), window_x);
	glUniform1i(default_shader.GetY(), window_y);
	glUniform1i(texture_shader.GetX(), window_x);
	glUniform1i(texture_shader.GetY(), window_y);

	// display test objects
	if (enable_test)
	{
		tester_object->DisplayTest();
		//tester_object->BasicTestDisplay();
	}

	// Render game
	manager->Draw();

	glutSwapBuffers();
}

void Timer(int value)
{
	if (reset_pause)
	{
		reset_pause = false;
		return;
	}

	int time = manager->Timer();
	if (time > 0)
		glutTimerFunc(time, Timer, 0);
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	int time = 0;

	switch (key)
	{
	case 'q':
		Cleanup();
		exit(EXIT_SUCCESS);
	case 'r':
		if (manager->GetState() == STATE_PLAY)
			reset_pause = true;
		time = manager->Reset();
		break;
	case 'p':
		time = manager->Pause();
		break;
	case 'i':
		time = manager->Instructions();
	}

	if (time > 0)
		glutTimerFunc(time, Timer, 0);
	glutPostRedisplay();
}

void Special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		manager->PlayerDirection(MOVE_UP);
		break;
	case GLUT_KEY_DOWN:
		manager->PlayerDirection(MOVE_DOWN);
		break;
	case GLUT_KEY_LEFT:
		manager->PlayerDirection(MOVE_LEFT);
		break;
	case GLUT_KEY_RIGHT:
		manager->PlayerDirection(MOVE_RIGHT);

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
	glutSpecialFunc(Special);
	glutReshapeFunc(Reshape);

	glutMainLoop();

	return 0;
}