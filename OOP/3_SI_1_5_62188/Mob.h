#pragma once
#include"Entity.h"
#include"Player.h"
class Mob:public Entity {

private:
	foo::Type mob;
	int damage;
	int health;
public:
	Mob();
	void setDamage(int Damage);
	void setHealth(int Health);
	int getDamage() const;
	int getHealth() const;
	bool isAlive();
	void attack(const Mob& other);
};