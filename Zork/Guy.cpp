#include <iostream>
#include <string>
#include "Guy.hpp"
#include "Light.hpp"

Guy::Guy(const int& live, const int& damage, const int& lucky, const int& carry) 
	: Creature(live,damage,lucky){
		_sp = carry;
		_num_objects = 0;
		_inventory = new Object*[10];
	}

Guy::~Guy(){
		for (int i = 0; i<_num_objects; ++i)
			delete _inventory[i];
		delete[] _inventory;
	}

void Guy::showInventory(){
		cout << "Objects in inventory: " << endl;
		for (int i = 0; i<_num_objects; ++i)
			cout << "- " << _inventory[i]->getName() << endl;
		delete[] _inventory;
	}

void Guy::showDiagnostic(){
		if (_lp < 10){
			cout << "You are screwed! " << endl;
		}
		else if (_lp < 20){
			cout << "You are right, but you could be better" << endl;
		}
		else if (_lp < 30){
			cout << "You are right" << endl;
		}
		else{
			cout << "You are full-fledged energy! " << endl;
		}
	}

const int Guy::sayHi(const char* location){
	int res = 0;
	if (strcmp(location, "BUNKER") == 0){
		cout << "You say: Now you can go, there is no threat outside. " << endl;
		cout << "Supervisor says: Thanks Sheriff " << endl;
		res=100;
	}
	else{
		cout << "You say: hello! " << endl;
		cout << "Nothing happends" << endl;
	}
	return res;
}

	void  Guy::setLive(const int& points){
		_lp += points;
	}

	const int Guy::haveLightOn(){
		int res = 0;
		for (int i = 0; i < _num_objects; ++i)
			if (_inventory[i]->getType() == LIGHT)
				res = ((Light*)_inventory[i])->isOn();
		return res;
	}

	void Guy::addObject(Object* item){
		if (item != NULL){
			_inventory[_num_objects] = item;
			++_num_objects;
		}
	}