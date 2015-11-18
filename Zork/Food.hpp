#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>
#include "Object.hpp"
#include "Guy.hpp"
using namespace std;

class Food : public Object{
	int _points;
public:
	Food(char* nombre, const unsigned int& peso, const unsigned int&  visible, const int points);

	~Food();

	void eat(Guy * sheriff);

};
#endif //FOOD_H