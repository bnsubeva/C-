#pragma once
#include"Entity.h"
#include"Player.h"
#include<vector>
class Environment {
private:
	static Environment* instance;
	std::vector<Entity*> entities;
public:
	static Environment* getInstance();
	void add(Entity* entity);
	static Environment* getInstance();
	Entity* getAt(int index) const;
	void removeAt(int index);
	void generateEntities(int number);
	void destroyEntities();
};