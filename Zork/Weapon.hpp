#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
#include "Object.hpp"
using namespace std;

class Weapon : public Object {
	int _damage;
public:
	Weapon(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int damage);

	~Weapon();

	const int& getDamage();


};
#endif //WEAPON_H