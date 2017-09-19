#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

uniform vec2 Resolution;

void main(){
	FragColor = vec4(InterpolatedColor, 1.0f);
	vec2 p = gl_FragCoord.xy/Resolution;
	vec2 q = p- vec2(0.5,0.5f);
	if(length(q)<0.25){
		discard;
	}
	/*
	vec2 p = gl_FragCoord.xy;
	vec2 center = vec2(200.0f,200.0f);
	vec2 q = center-p;
	if(sqrt(q.x*q.x +q.y*q.y)<100.0f){
		discard;
	}

	*/
}