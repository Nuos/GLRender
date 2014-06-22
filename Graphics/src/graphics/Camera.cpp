#include "Camera.h"
#include <glm/gtx/transform.hpp>

namespace graphics
{
	Camera::Camera() :
		m_position(0.0f, 0.0f, 0.0f),
		m_direction(0.0f, 1.0f, 0.0f),
		m_right(0.0f, 0.0f, 1.0f),
		m_up(0.0f, 1.0f, 0.0f)
	{
	}

	Camera::~Camera()
	{
	}

	Vector3 Camera::position()
	{
		return m_position;
	}

	Vector3 Camera::direction()
	{
		return m_direction;
	}

	Vector3 Camera::right()
	{
		return m_right;
	}

	Vector3 Camera::up()
	{
		return m_up;
	}

	Matrix4 Camera::projMatrix()
	{
		return m_projMatrix;
	}

	Matrix4 Camera::viewMatrix()
	{
		return m_viewMatrix;
	}

	void Camera::update(float deltaTime)
	{

	}

	void Camera::updateProjectionMatrix(int width, int height)
	{
		m_projMatrix = glm::perspective(60.0f, float(width) / float(height), 0.01f, 10000.0f);
	}

	void Camera::updateViewMatrix()
	{
		m_right = glm::cross(m_direction, Vector3(0, 1, 0));
		m_right = glm::normalize(m_right);
		m_up = glm::cross(m_right, m_direction);
		m_up = glm::normalize(m_up);
		m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, m_up);
	}
}
