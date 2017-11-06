#version 330

in vec3 InterpolatedColor;
in vec3 pixelPosition;
in vec3 InterpolatedNormal;
in vec2 InterpolatedTextCoord;

out vec4 FragColor;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 cameraPosition;
uniform sampler2D DiffuseTexture;
uniform sampler2D DiffuseTexture2;

void main()
{
	vec3 ambient = 0.1f*lightColor;
	vec3 L = normalize(lightPosition - pixelPosition);
	vec3 diffuse = max(dot(InterpolatedNormal,L), 0.0f) * lightColor;

	vec3 R = normalize(reflect(-L,normalize(InterpolatedNormal)));
	vec3 V = normalize(cameraPosition-pixelPosition);
	vec3 specular = 0.5f * pow(max(dot(V, R),0.0f),64) * lightColor;
	//vec3 phong = (ambient + diffuse + specular)*InterpolatedColor;
	
	vec4 texA =  texture2D(DiffuseTexture, InterpolatedTextCoord);
 	vec4 texB = texture2D(DiffuseTexture2, InterpolatedTextCoord);
 	vec4 mixOne = mix(texA,texB, 0.4);
	vec3 phong = (ambient+diffuse+specular) *mixOne;
	FragColor = vec4(phong , 1.0f);

}