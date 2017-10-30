#version 330

in vec3 InterpolatedColor;
in vec3 pixelPosition;
in vec3 InterpolatedNormal;

out vec4 FragColor;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 cameraPosition;

void main()
{
	vec3 ambient = 0.1f*lightColor;//vec3(1.0f,1.0f,1.0f);
	vec3 L = normalize(lightPosition - pixelPosition);
	vec3 diffuse = max(dot(InterpolatedNormal,L), 0.0f) * lightColor;

	vec3 R = normalize(reflect(-L,normalize(InterpolatedNormal)));
	vec3 V = normalize(cameraPosition-pixelPosition);
	vec3 specular = 0.5f * pow(max(dot(V, R),0.0f),64) * lightColor;

	vec3 phong = (ambient + diffuse + specular) * InterpolatedColor;
	FragColor = vec4(phong, 1.0f);
	//FragColor = vec4(ambient, 1.0f);

}