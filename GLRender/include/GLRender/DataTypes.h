#pragma once

#include <GLRender/GLRender.h>

// STL
#include <string>
#include <memory>

// GLM
#include <glm/glm.hpp>
//#include <glm/gtc/quaternion.hpp>
//#include <glm/gtx/quaternion.hpp>

namespace glr
{
	typedef void* WindowHandle;
	typedef std::string string;
	typedef unsigned char uchar;
	typedef unsigned short ushort;
	typedef unsigned int uint;
	typedef glm::mat4 Matrix4;
	typedef glm::vec4 Vector4;
	typedef glm::vec3 Vector3;
	typedef glm::vec2 Vector2;
	typedef glm::ivec2 Point2;
	typedef glm::ivec3 Point3;
	//typedef glm::quat Quaternion;
}