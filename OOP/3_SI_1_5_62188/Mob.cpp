#include"Mob.h"
Mob::Mob()
{
	damage = 0;
	health = 0;
}
void Mob::setDamage(int Damage)
{
	damage = Damage;
}
void Mob::setHealth(int Health)
{
	health = Health;
}
int Mob::getDamage() const
{
	return damage;
}
int Mob::getHealth() const
{
	return health;
}
void Mob::attack(const Mob& other)
{
	if (getDistanceTo(other) < 5)
	{
		health = health - other.damage;
	}
	 
}
bool Mob::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}