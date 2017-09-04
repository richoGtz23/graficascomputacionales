#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

void main()
{
	vec2 pixelPositionInWindow = gl_FragCoord.xy;
	if(pixelPositionInWindow.x >100 && pixelPositionInWindow.x<300 && pixelPositionInWindow.y>100 && pixelPositionInWindow<300){
		discard;
	}
}