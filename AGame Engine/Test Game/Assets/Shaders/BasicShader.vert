#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

out vec2 UV;
out vec3 Normal_worldspace;
out vec3 EyeDirection_worldspace;

uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;
uniform vec3 CameraPosition;	//camera position in world space

void main(){
	gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);
	
	Normal_worldspace = (M * vec4(vertexNormal_modelspace, 0)).xyz;

	EyeDirection_worldspace = CameraPosition - (M * vec4(vertexPosition_modelspace, 1)).xyz;
	
	UV = vertexUV;
}