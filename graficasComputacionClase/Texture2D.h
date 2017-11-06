#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <IL/il.h>
#include <string>

class Texture2D {
public:
	Texture2D();
	~Texture2D();

	void LoadTexture(std::string path);
	void LoadTexture(GLint format, GLsizei width, GLsizei height, const void * pixels);


	void Bind();
	void Unbind();

private:
	GLuint _textureId; //identificador de textura
};