#include "Camera.h"

Camera::Camera(double width, double height)
	:
	 wFov(width,height)
{
}


Camera::~Camera()
{
}

Vec2d Camera::getFov()
{
	return wFov;
}

void Camera::adjustFov(double w, double h)
{
	if (wFov._x > w) wFov._x = w;
	if (wFov._y > h) wFov._y = h;
}
