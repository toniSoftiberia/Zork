#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
using namespace std;

class Creature {
protected:
	int _lp;//live points
	int _dp;//damage points
	int _kp;//lucky points

public:
	Creature(const int& live,const int& damage,const int& lukky);

	~Creature();
};
#endif //CREATURE_H