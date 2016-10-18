#version 330 core

in vec2 UV;
in vec3 Normal_worldspace;
in vec3 EyeDirection_worldspace;
in vec3 LightDirection_worldspace;

uniform sampler2D diffuseTexture;
uniform vec3 LightDirection = vec3(0.5, -0.5, 1);
uniform vec4 Color = vec4(1.0, 1.0, 1.0, 1.0);
uniform vec4 AmbientColor = vec4(0.2, 0.2, 0.2, 1.0);
uniform vec4 RimColor = vec4(1.0, 0.0, 0.0, 1.0);

void main(){
	vec3 n = normalize(Normal_worldspace);
	vec3 l = normalize(LightDirection);
	float cosTheta = clamp(dot(n, -l), 0, 1);
	
	vec3 E = normalize(EyeDirection_worldspace);
	vec3 R = reflect(l, n);
	float cosAlpha = clamp(dot(E, R), 0, 1);
	
	float cosB = clamp(dot(E, n), 0, 1);

	vec3 diffuseCol = vec3(1, 1, 1) * cosTheta;
	vec3 specCol = vec3(1, 1, 1) * cosTheta * pow(cosAlpha, 5);
	vec3 rimColor = RimColor.rgb * 1 * pow((1 - cosB), 9) * 15;

	vec4 col = vec4(diffuseCol, 1.0) + vec4(specCol, 1.0) + vec4(AmbientColor.rgb, 1.0) + vec4(rimColor.rgb, 1.0);
	col *= texture(diffuseTexture, UV);
	gl_FragColor = col;
}