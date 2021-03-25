#include"Point2D.h"
Point2D::Point2D ()
{
	 x = 1;
	 y = 1;
}
Point2D::~Point2D()
{
	std::cout << "\n the destructor was called" << std::endl;
}
Point2D::Point2D(const Point2D& point)
{
	x = point.x;
	y = point.y;
}
Point2D & Point2D::operator=(const Point2D& point)
{
	if (this != &point)
	{
		x = point.x;
		y = point.y;
	}
	return *this;
}
void Point2D::setPoint2D(double X, double Y)
{
	x = X;
	y = Y;
}
 double Point2D::getX() const
{
	 return x;
}
 double Point2D::getY() const
 {
	 return y;
 }
 double Point2D::getDistanceTo(const Point2D& point) const
 {
	 const double x_diff = getX() -  point.getX();
	 const double y_diff = getY() -  point.getY();
	 return std::sqrt(x_diff * x_diff + y_diff * y_diff);
 }