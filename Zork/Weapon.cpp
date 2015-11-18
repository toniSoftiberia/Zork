#include "Weapon.hpp"

Weapon::Weapon(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int damage)
	: Object(nombre, peso, visible){
	_damage = damage;
	setType(WEAPON);

}

Weapon::~Weapon(){

}

const int& Weapon::getDamage(){
	return _damage;
}
