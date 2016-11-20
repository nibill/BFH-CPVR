// simple stfipify fragment shader color set1 (core profile)

#version 400 

vec4 stripify(in float intensity) 
{
	vec4 color;

	color = vec4(0.0, 0.0, sin(200.0 * intensity), 1.0);

	return(color);
}