#version 400



layout (location = 0) in vec3 position;
layout (location = 2) in vec3 normal;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 world;
uniform mat4 world_it;
out vec3 f_normal;
out vec3 f_worldPos;
void main(void)
{
	f_normal = (world_it * vec4(normal, 0.0)).xyz;
	vec4 worldPos = world * vec4(position, 1.0);
	f_worldPos = worldPos.xyz;
	gl_Position = proj * view * worldPos;
}
