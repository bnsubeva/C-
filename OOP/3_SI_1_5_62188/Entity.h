#pragma once
#include"Point2D.h"
#include"point3D.h"
typedef std::string string;
namespace  foo {
	enum class Type
	{
		player,
		NFC2,
		mob
	};
}
class Entity {
private:
	int id;
	static int current_id;
	char* name;
	Point2D* location;
	Point3D* location2;
	public:
	Entity();
	Entity(const Entity& entity);
	Entity& operator=(const Entity& entity);
	virtual ~Entity();
	virtual bool isAlive () const ;
	Point2D* getLocation(const Entity& entity);
	double getDistanceTo2D(const Entity& entity) const ;
	double getDistanceTo(const Entity& entity) const;
	void moveTo(const Point2D& new_location);
	void moveTo(const Entity& entity);
	 

};
int  Entity::current_id;