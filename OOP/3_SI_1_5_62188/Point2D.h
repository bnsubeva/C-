#pragma once
#include<iostream>
#include<math.h>
#include"pch.h"
class Point2D
{
private:
	double x;
	double y;
public:
	Point2D();
	~Point2D();
	Point2D(const Point2D& point);
	Point2D &operator=(const Point2D& point);
	void setPoint2D(double X, double Y);
	double getX() const;
	double getY()const;
	double getDistanceTo(const Point2D& point) const;


};
