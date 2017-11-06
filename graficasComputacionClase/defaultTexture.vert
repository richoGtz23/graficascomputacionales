
#version 330

in vec3 VertexPosition;
in vec2 VertexTextCoord;

out vec2 InterpolatedTextCoord;

uniform mat4 mvplMatrix;

void main(){
	InterpolatedTextCoord = VertexTextCoord;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}