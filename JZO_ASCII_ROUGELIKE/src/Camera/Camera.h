#ifndef CAMERA_H
#define CAMERA_H
#include "../Utility/Vec2.h"
class Camera
{
public:
	Camera()=delete;
	Camera(double width, double height);
	~Camera();

public:
	Vec2d getFov();
	void adjustFov(double w, double h);
private:
	Vec2d wFov;
};

#endif