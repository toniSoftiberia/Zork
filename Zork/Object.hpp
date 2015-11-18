#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <string>
#define CONTAINER 0
#define LOCATION 1
#define FOOD 2
#define LIGHT 3 
#define WEAPON 4
#define SWITCH 5
using namespace std;

class Object {
	char* _name;
	unsigned int _weight;
	unsigned int _visible;
	unsigned int _type;

public:
	Object(char* name, const unsigned int& weight, const unsigned int& visible);

	~Object();

	const char * getName();

	void setName(const char * name);

	const unsigned int& getWeigth();

	void setWeight(const unsigned int& weight);

	const unsigned int& getType();

	void setType(const unsigned int& type);

	const unsigned int& getVisible();

	void setVisible(const unsigned int& visible);


};
#endif //OBJECT_H