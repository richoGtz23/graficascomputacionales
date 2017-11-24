#version 330
 
 in vec3 InterpolatedColor;
 in vec3 InterpolatedNormal;
 in vec3 pixelPosition;
 in vec2 InterpolatedTexCoord;
 in vec4 PixelPositionLightSpace;
 
 
 uniform vec3 LightColor;
 uniform vec3 LightPosition;
 uniform vec3 CameraPosition;
 uniform sampler2D DiffuseTexture;
 uniform sampler2D DiffuseTexture2;
 uniform sampler2D ShadowMap;
 
 
 out vec4 FragColor;
 
 float IsPixelOccluded(vec4 fragPosLightSpace) 
 { 
 	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w; 
 	projCoords = (projCoords * 0.5 + 0.5);
 	float closestDepth = texture2D(ShadowMap, projCoords.xy).r; 
 	float currentDepth =  projCoords.z;
 	float shadow = currentDepth - 0.005f > closestDepth ? 1.0f : 0.0f;
 	return shadow;
 }
 
 void main()
 {
    vec3 ambient = 0.1f * LightColor;
 	vec3 L = normalize(LightPosition - pixelPosition);
 	vec3 R = normalize(reflect(-L,normalize(InterpolatedNormal)));
 	vec3 V = normalize(CameraPosition-pixelPosition);
 
 	vec3 diffuse = max(dot(normalize(InterpolatedNormal), L),0.0f) * LightColor;
 	vec3 specular = 0.5f * pow(max(dot(V, R),0.0f),256) * LightColor;
 	
 	vec4  texA =   texture2D(DiffuseTexture, InterpolatedTexCoord);
 
 	float shadow = IsPixelOccluded(PixelPositionLightSpace);
 	vec3 phong = (ambient + (1.0 - shadow) * (diffuse + specular)) * vec3(texA);
 
 	FragColor = vec4(phong, 1.0f);
 }