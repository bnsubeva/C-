#pragma once
#include"Entity.h"
#include"Mob.h"
class Player : public Entity
{
 private:
	foo::Type player;
	int damage;
	int health;
public:
	Player();
	bool isAlive();
	void setDamage(int Damage);
	void setHealth(int Health);
	int getDamage() const;
	int getHealth() const;
	void attack( const Player& other);
	void attack(const Mob& other);
};