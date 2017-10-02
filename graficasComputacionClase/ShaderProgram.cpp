#include "ShaderProgram.h"
#include "InputFile.h"
#include "shader.h"
#include <memory>
ShaderProgram::ShaderProgram() {
	_programHandle = 0;
}
ShaderProgram::~ShaderProgram() {
	DeleteProgram();
}
void ShaderProgram::CreateProgram() {
	_programHandle = glCreateProgram();
}
void ShaderProgram::AttachShader(std::string path, GLenum type) {
	// Create and add the shaders to a list
	std::unique_ptr<shader> shader(new shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}
void ShaderProgram::LinkProgram() {
	for (int i = 1; i<_attachedShaders.size() + 1; i++) {
		glAttachShader(_programHandle, _attachedShaders[i - 1]->GetHandle());
	}
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}
void ShaderProgram::Activate() {
	glUseProgram(_programHandle);
}
void ShaderProgram::Deactivate() {
	glUseProgram(0);
}
void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());

}
void ShaderProgram::SetUniformf(std::string name, float value) {
	glUniform1f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), value);
}
void ShaderProgram::SetUniformf(std::string name, float x, float y) {
	glUniform2f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y);
}
void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {
	glUniform3f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z);
}
void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {
	glUniform4f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z, w);
}
void ShaderProgram::DeleteAndDetachShaders() {
	for (int i = 1; i<_attachedShaders.size() + 1; i++) {
		glDetachShader(_programHandle, _attachedShaders[i - 1]->GetHandle());
	}
	_attachedShaders.clear();
}
void ShaderProgram::DeleteProgram() {
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}