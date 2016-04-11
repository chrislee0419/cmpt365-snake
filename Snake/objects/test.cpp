/*
//	for CMPT 365 Term Project
//	by Chris Lee - cla235
*/

#include "test.h"

// Globals
Shader Test::_shader = Shader();

// Constructor
Test::Test()
{
	_vao = 0;
	_pos_vbo = 0;
	_col_vbo = 0;

	_box_test = false;
	_text_test = false;
}

// Destructor
Test::~Test()
{
	if (_box_test)
		free(box_objects);
	if (_text_test)
		free(text_objects);
}

// Test setup
// Comment out the tests that do not need to be run
void Test::SetupTest()
{
	_CreateBoxTest();
	//_CreateTextTest();
}

void Test::DisplayTest()
{
	_DisplayBoxTest();
	_DisplayTextTest();
}

void Test::SetProgram(const Shader shader)
{
	_shader = shader;
}

void Test::BasicTest()
{
	_shader.UseShader();
	GLuint program = _shader.GetProgram();
	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	GLuint vertex_colour = glGetAttribLocation(program, "vColour");

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	glGenBuffers(1, &_pos_vbo);
	glGenBuffers(1, &_col_vbo);
	glm::vec4 vertices[3] = { glm::vec4(0, 0, 0, 1), glm::vec4(800, 0, 0, 1), glm::vec4(0, 800, 0, 1) };
	glBindBuffer(GL_ARRAY_BUFFER, _pos_vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(glm::vec4), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(vertex_position, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertex_position);
	glm::vec4 colours[3] = { glm::vec4(1, 0, 0, 1), glm::vec4(0, 1, 0, 1), glm::vec4(0, 0, 1, 1) };
	glBindBuffer(GL_ARRAY_BUFFER, _col_vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(glm::vec4), colours, GL_STATIC_DRAW);
	glVertexAttribPointer(vertex_colour, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertex_colour);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Test::BasicTestDisplay()
{
	_shader.UseShader();
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}