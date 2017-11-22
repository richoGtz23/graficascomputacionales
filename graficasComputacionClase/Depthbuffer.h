#pragma once
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
using namespace std;
using namespace glm;

class Depthbuffer {
public:
	Depthbuffer();
	~Depthbuffer();
	void Create(int resolution);
	void Bind();
	void Unbind();
	void BindDepthMap();
	void UnbindDepthMap();
private:
	GLuint _framebuffer = 0;
	GLuint _depthmap = 0;
	GLsizei _resolution = 0;
};