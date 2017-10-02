#include "Shader.h"
#include "InputFile.h"

shader::shader() {
	_shaderHandle = 0;
}
shader::~shader() {
	glDeleteShader(_shaderHandle);
}
void shader::CreateShader(std::string path, GLenum type) {
	if (_shaderHandle != 0) {
		glDeleteShader(_shaderHandle);
	}
	InputFile ifile;
	ifile.Read(path);
	std::string vertexSource = ifile.GetContents();
	_shaderHandle = glCreateShader(type);
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	glCompileShader(_shaderHandle);
}
GLuint shader::GetHandle() {
	return _shaderHandle;
}