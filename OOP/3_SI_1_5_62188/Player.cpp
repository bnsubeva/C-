#include"Player.h"
Player::Player()
{
	damage = 0;
	health = 0;
}
void Player::setDamage(int Damage)
{
	damage = Damage;
 }
void Player::setHealth(int Health)
{
  health=Health;
}
int Player::getDamage() const
{
	return damage;
}
int Player::getHealth() const
{
	return health;
}
void Player::attack(const Player& other)
{
	if (getDistanceTo(other) < 5)
	{
		health = health - other.damage;
	}
}
void Player::attack(const Mob& other)
{
	if (getDistanceTo(other) < 5)
	{
		health = health - other.Mob::getDamage();
	}
}
