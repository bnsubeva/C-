#pragma once
#include"Point2D.h"
class Point3D : public Point2D
{
private:
	double z;
	Point3D();
	~Point3D();
	Point3D(const Point3D& point);
	Point3D &operator=(const Point3D& point);
	void setPoint3D(double Z);
	double getZ() const;
	double  getDistanceTo(const Point3D& point);
};
