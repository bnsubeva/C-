#include"Environment.h"
Environment* Environment::instance = nullptr;
Environment* Environment::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Environment();
	}
	return instance;
}
void Environment::add(Entity* entity)
{
 
}
void Environment::destroyEntities()
{
	for (std::vector<Entity*>::iterator it =  entities.begin(); it != entities.end(); it++) {
		delete  *it;
	}
}