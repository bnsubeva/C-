#include"Entity.h"
#include"Point2D.h"
#include"point3D.h"
#include"pch.h"
Entity::Entity()
{ 
	name = new char[1];
	name[0] = '\0';
    current_id = 1;
}
Entity::Entity() : id(current_id++)
{

}
  
 Entity::Entity(const Entity& entity)
 {
	 int size = strlen(entity.name);
	 name = new char[size + 1];
	 strcpy(name,  entity.name);
	 entity.current_id = 1;
 }
 Entity& Entity::operator=(const Entity& entity)
 {
	 if (this != &entity)
	 {
		 delete[] name;
		 int size = strlen(entity.name);
		 name = new char[size + 1];
		 strcpy(name, entity.name);
		 current_id = entity.current_id;
	 }
	 return *this;
 }
 Entity::~Entity()
 {
	 delete[] name;
 }
 bool Entity::isAlive() const {
	 return true;
 }
 Point2D* Entity::getLocation(const Entity& other)
 {
	 Point2D* newlocation;
	 newlocation = other.location;
	 return newlocation;
 }
 double Entity::getDistanceTo2D(const Entity& other) const
 {
	 Point2D* CashThisTo2D = dynamic_cast<Point2D*>(this->location);
	 Point2D* CastTo2D = dynamic_cast<Point2D*>(other.location);
	 double distance;
	 if (CastTo2D != nullptr&&CashThisTo2D != nullptr)
	 {
		 distance = this->location->getDistanceTo(*(other.location));
	 }
	 else
	 {
		 distance = this->location->getDistanceTo(*(other.location));
	 }
	 return distance;

 }
 double Entity::getDistanceTo(const Entity& other) const
 {
	 Point3D* CashThisTo3D = dynamic_cast<Point3D*>(this->location2);
	 Point3D* CastTo3D = dynamic_cast<Point3D*>(other.location2);
	 double distance;
	 if (CastTo3D != nullptr&&CashThisTo3D != nullptr)
	 {
		 distance = this->location->getDistanceTo(*(other.location2));
	 }
	 else
	 {
		 distance = this->location->getDistanceTo(*(other.location2));
	 }
	 return distance;

 }
 void Entity::moveTo(const Entity& entity)
 {
	 location = entity.location;
 }