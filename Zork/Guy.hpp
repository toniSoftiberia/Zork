#ifndef GUY_H
#define GUY_H
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Object.hpp"

#define CONTAINER 0
#define LOCATION 1
#define FOOD 2
#define LIGHT 3 
#define WEAPON 4
#define SWITCH 5

using namespace std;

class Guy : public Creature{

	int _sp;//carry points
	int _num_objects;
	Object** _inventory;

public:
	Guy(const int& live, const int& damage, const int& lucky, const int& carry);

	~Guy();

	void showInventory();

	void showDiagnostic();

	const int sayHi(const char* location);

	void setLive(const int& points);

	const int haveLightOn();

	void addObject(Object* item);
};
#endif //PERSONA_H