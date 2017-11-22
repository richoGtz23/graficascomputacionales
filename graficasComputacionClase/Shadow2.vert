#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;
in vec2 VertexTexCoord;

out vec3 InterpolatedNormal;
out vec3 InterpolatedColor;
out vec3 pixelPosition;
out vec2 InterpolatedTexCoord;
out vec4 PixelPositionLightSpace;

uniform mat4 mvpMatrix;
uniform mat4 modelMatrix;
uniform mat4 LightVPMatrix;
uniform mat3 normalMatrix;


void main(){
	InterpolatedColor = VertexColor;
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	pixelPosition = vec3(modelMatrix * vec4(VertexPosition, 1.0f));
	InterpolatedNormal = normalMatrix * VertexNormal;
	InterpolatedTexCoord = VertexTexCoord;
	PixelPositionLightSpace = LightVPMatrix * vec4(pixelPosition, 1.0);
}