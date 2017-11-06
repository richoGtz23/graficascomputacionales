#include "ShaderProgram.h"
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <vector>

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string name, GLenum type)
{
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(name, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());

	glLinkProgram(_programHandle);

	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());
}

void ShaderProgram::SetUniformf(std::string name, float x)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1f(uniformLocation, x);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform2f(uniformLocation, x, y);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3f(uniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
}
void ShaderProgram::SetUniformMatrix(std::string name, mat4 matrix) {
	GLuint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, value_ptr(matrix));
}
void ShaderProgram::SetUniformMatrix3(string name, glm::mat3 matrix){
	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}
void ShaderProgram::DeleteAndDetachShaders()
{
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());

	_attachedShaders.clear();
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
void ShaderProgram::SetUniformf(std::string name, vec3 pos)
{
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform3fv(uniformLocation,1 ,&pos[0]);
}
void ShaderProgram::SetUniformi(std::string name, int value) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
	glUniform1i(uniformLocation, value);
}