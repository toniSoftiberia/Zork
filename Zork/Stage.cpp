#include "Stage.hpp"
#include "Switch.hpp"
#include "Light.hpp"
#include "Weapon.hpp"
#include "Container.hpp"
#include <iostream>

Stage::Stage(){
	_score = 0;
	_desc_mode = NONE;
		
	_sheriff = new Guy(50, 2, 5, 20);

	//LEVEL1
	Room** rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};//NORTH 0, EAST 1, SOUTH 2, WEST 3, UP 4, DOWN 5, IN 6, OUT 7
	Room* asmblr = new Room("HOME MODULE", "You can see the module with which you've come to the planet. ", 1, rooms, -1, 0, new Object*[10]);
	_start = _position = asmblr;

	Object* object1 = new Switch("Interruptor",100, 0,NULL);
	Object** objs = new Object*;
	objs[0] = object1;
	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, NULL, asmblr, NULL, NULL, NULL, NULL};
	Room* asmblr2 = new Room("CONTROL TOWER", "You see the control tower, that did not give you the OK when you arrived. You can see a cabin on top. ", 1, rooms, UP, 1, objs);
	asmblr->setDirection(asmblr2, EAST);
	asmblr2->setHideDesc("You see an interruptor");

	object1 = new Light("Lantern", 2, 1, 5);
	Object* object2 = new Switch("CardReader", 100, 0, "AccesCard");
	objs = new Object*[2];
	objs[0] = object1;
	objs[1] = object2;
	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, NULL, NULL, NULL, asmblr2, NULL, NULL};
	Room* asmblr3 = new Room("TOWER CABINE", "You are in the cabin of the control tower, there is no nadue here. ", 1, rooms, -1, 2, objs);
	asmblr2->setDirection(asmblr3, UP);
	asmblr3->setHideDesc("You see an slot in the PC");

	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, asmblr, NULL, NULL, NULL, NULL, NULL};
	asmblr3 = new Room( "CRATER", "You are in a large crater probably caused by a large meteorite. In the north you can see an abandoned module. ", 1, rooms, -1, 0, new Object*[10]);
	asmblr->setDirection(asmblr3, NORTH);

	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, asmblr2, asmblr3, NULL, NULL, NULL, NULL};
	asmblr = new Room( "ENTRANCE", "You are in the esplanade that leads to the entrance to the shelter. ", 1, rooms, EAST, 0, new Object*[10]);
	asmblr2->setDirection(asmblr, NORTH);
	asmblr3->setDirection(asmblr, EAST);

	object1 = new Object("AccesCard", 1, 1);
	objs = new Object*[1];
	objs[0] = object1;
	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, asmblr3, NULL, NULL, NULL, NULL, NULL};
	asmblr2 = new Room("ABANDONATED MODULE", "There is an abandoned module, it seems to take a lot of time here. ", 0, rooms, -1, 1, objs);
	asmblr3->setDirection(asmblr2, NORTH);
	
	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, asmblr, asmblr2, NULL, NULL, NULL, NULL};
	asmblr3 = new Room( "DUNES", "These surrounded by dunes , east some ruts can be seen. In the west you can see an abandoned module. ", 1, rooms, -1, 0, new Object*[10]);
	asmblr2->setDirection(asmblr3, EAST);
	asmblr->setDirection(asmblr3, NORTH);

	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, NULL, asmblr3, NULL, NULL, NULL, NULL};
	asmblr = new Room("PLUTON ROVER", "In the bottom of a crater you spot a stuck vehicle. ", 1, rooms, -1, 0, new Object*[10]);
	asmblr3->setDirection(asmblr, EAST);

	object1 = new Light("LedLantern", 2, 1, 10);
	object2 = new Weapon("Lightsaber", 5, 1, 10);
	Object* object3 = new Container("GloveCompartment", 100, 1, object2);
	objs = new Object*[2];
	objs[0] = object1;
	objs[1] = object3;
	rooms = new Room*[NUM_DIRECTIONS]{NULL, NULL, NULL, NULL, NULL, NULL, NULL, asmblr};
	asmblr2 = new Room("ROVER", "You are in the rover, it is very sophisticated. ", 1, rooms, -1, 2, objs);
	asmblr->setDirection(asmblr2, IN);

/*	
	//LEVEL2
	//DOG HOLE
	//DESTORNILLADOR
	asm = new Room( "HANGAR", "You are in the hangar , you can see different types of vehicles and ships. In one wall there Counterbore .", 1, rooms, -1, 0, new Object*[10]);
	asm2 = new Room( "ROOM", "You are in the room see beds and wardrobes. Each bed has a label with a name.", 1, rooms, -1, 0, new Object*[10]);
	//REJILLA
	//	- OPEN REJILLA WITH DES
	//	- GET PIPELINE FROM REJILLA
	asm3 = new Room( "GIM", "You are in the gym , you can see a lot of workout machines", 1, rooms, -1, 0, new Object*[10]);
	//Box
	//	-OPEN BOX
	//  -BOMBILLA
	asm4 = new Room( "STORE", "These in stock , there are many disorderly and apparently broken boxes.", 1, rooms, -1, 0, new Object*[10]);
	//LINTERNA
	asm = new Room( "HALL", "You are in the hall, it looks like a pretty friendly site", 1, rooms, -1, 0, new Object*[10]);
	//PLUTONCOLA
	asm2 = new Room( "LIVING ROOM", "You are in the living room , there are several sofas and many screens", 1, rooms, -1, 0, new Object*[10]);
	//PUT BOMBILLA IN LAMP
	//TOY
	//LINTERNA
	asm3 = new Room( "BACKYARD", "You are in the recreation room , there are toys and swings everywhere, there is a lamp without bulb", 1, rooms, -1, 0, new Object*[10]);
	//CONTROL PANEL
	asm4 = new Room( "SUPERVISOR ROOM", "These supervisor in the room , there is a large armchair with many screens", 1, rooms, -1, 0, new Object*[10]);
	//BAT
	asm = new Room( "GUARDHOUSE", "These guard post , there are many weapons, but all are in glass cases", 1, rooms, -1, 0, new Object*[10]);
	//SLURM
	//BEANS
	asm2 = new Room( "DINING AREA", "You are in the room, no bad food on the tables", 1, rooms, -1, 0, new Object*[10]);
	//KNIFE
	asm3 = new Room( "KITCHEN", "Upon entering the kitchen, a strong smell of decay envelops you. You do not think there is anything to serve", 1, rooms, -1, 0, new Object*[10]);
	//PANEL
	// - PUT DESTORNILLADOR IN SLOT
	asm4 = new Room( "MACHINE ROOM", "Estas en la sala de prueba", 1, rooms, -1, 0, new Object*[10]);

	//LEVEL3
	asm = new Room( "ENTRANCE", "These elongated in a small room and ending in a door", 1, rooms, -1, 0, new Object*[10]);
	asm2 = new Room( "WAITING ROOM", "You are in the waiting room , there is nothing in this room except a few banks", 1, rooms, -1, 0, new Object*[10]);
	asm3 = new Room( "BUNKER", "The bunker is full of people , among them is the supervisor.", 1, rooms, -1, 0, new Object*[10]);
	*/

	//delete asm

	//delete room
}

Stage::~Stage(){

}

Room * Stage::getStart(){
	return _start;
}

Room * Stage::getPosition(){
	return _position;
}

Guy* Stage::getSheriff(){
	return _sheriff;
}

void Stage::move(const int& dir){
	if (_position->getDirection(dir) != NULL){
		if (dir == _position->isClosed()){
			cout << "This door is closed " << endl;
		}
		else{
			_position = _position->getDirection(dir);
			cout << _position->getName() << endl;
			if (_position->getLight() == 1 || _sheriff->haveLightOn() == 1){
				if (_desc_mode != SUPERBRIEF){
					cout << _position->getDesc(_desc_mode) << endl;
				}
				if (_position->getLight() == 1)
					_position->showObjects();
			}
			else{
				cout << "You can not see anything, it is too dark " << endl;
			}
		}
	}else{
		if (_level == EXTERIOR){
			cout << "It is not a good idea to get away from the base " << endl;
		}else{
			cout << "There is a wall there " << endl;
		}
	}
}

void Stage::restart(const char* &orden){
	string anstmp;

	cout << "Are you sure you want to restart? ";
	cin >> anstmp;
	const char* tmp = anstmp.c_str();

	if (strcmp(anstmp.c_str(), "yes") != 0){
		orden = "keep going";
	}
	else{
		cout << "Restarting" << endl;
	}
}

void Stage::quit(const char* &orden){
	string anstmp;

	cout << "Are you sure you want to quit? ";
	cin >> anstmp;
	const char* tmp = anstmp.c_str();

	if (strcmp(anstmp.c_str(), "yes") != 0){
		orden = "no";
	}
	else{
		cout << "Exiting" << endl;
	}
}

void Stage::superbrief(){
	if (_desc_mode == SUPERBRIEF){
		_desc_mode = NONE;
		cout << "Superbrief mode off " << endl;
	}else{
		_desc_mode = SUPERBRIEF;
		cout << "Superbrief mode on " << endl;
	}
}

void Stage::vervose(){
	if (_desc_mode == VERBOSE){
		_desc_mode = NONE;
		cout << "Verbose mode off " << endl;
	}else{
		_desc_mode = VERBOSE;
		cout << "Verbose mode on " << endl;
	}
}	

void Stage::addScore(const int& score){
	_score += score;
}

void Stage::showScore(){
	cout << "Your score is: " << _score << endl;
}

const int& Stage::getMode(){
	return _desc_mode;
}

void Stage::examine(){
	_position->setObjectsVisibles();
	char show[150];
	strcpy_s(show, sizeof(char[150]), _position->getHideDesc().c_str());
	if (strcmp(show, " ")==0)
		strcpy_s(show, sizeof(char[150]), "You don't see anything special. ");
	cout << show << endl;
}