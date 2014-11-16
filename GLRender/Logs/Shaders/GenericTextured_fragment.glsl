#version 400



in vec2 f_uv;
in vec3 f_normal;
uniform vec3 v_color = vec3(1.0,1.0,1.0);
uniform sampler2D t_color;
uniform float v_roughness = float(1.0);
uniform sampler2D t_roughness;
uniform float v_metallicity = float(1.0);
uniform sampler2D t_metallicity;
layout (location = 0) out vec4 g_color;
layout (location = 1) out vec4 g_normal;
void main(void)
{
	vec3 d = texture(t_color, f_uv).rgb * v_color;
	float r = texture(t_roughness, f_uv).r * v_roughness;
	float m = texture(t_metallicity, f_uv).r * v_metallicity;

	g_color = vec4(d, r);
	g_normal = vec4(f_normal, m);
}