#include"Point3D.h"
Point3D::Point3D()
{
	z = 1;
}
Point3D::~Point3D()
{
	std::cout << "\n the destructor was called" << std::endl;
}
Point3D::Point3D(const Point3D& point)
{
	z = point.z;
}
Point3D & Point3D::operator=(const Point3D& point)
{
	if (this != &point)
	{
		z = point.z;
	}
	return *this;
}
void Point3D::setPoint3D(double Z)
{
	z = Z;
}
double Point3D::getZ() const
{
	return z;
}
double Point3D::getDistanceTo(const Point3D& point) {  
	return  sqrt((getX() -point.getX()) * (getX() - point.getX()) +
		(getY() - point.getY()) * (getY() - point.getY()) +
		(getZ() - point.getZ()) * (getZ() - point.getZ()));
}