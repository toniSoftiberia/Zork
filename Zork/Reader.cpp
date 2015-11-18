#include "Reader.hpp"

int Reader::isDirection(const char* &orden) {
		int res = -1;

		if (strcmp(orden, "north") == 0 || strcmp(orden, "n") == 0) {
			res = NORTH;
		}
		else if (strcmp(orden, "south") == 0 || strcmp(orden, "s") == 0) {
			res = SOUTH;
		}
		else if (strcmp(orden, "east") == 0 || strcmp(orden, "e") == 0) {
			res = EAST;
		}
		else if (strcmp(orden, "west") == 0 || strcmp(orden, "w") == 0) {
			res = WEST;
		}
		else if (strcmp(orden, "up") == 0 || strcmp(orden, "u") == 0) {
			res = UP;
		}
		else if (strcmp(orden, "down") == 0 || strcmp(orden, "d") == 0) {
			res = DOWN;
		}
		else if (strcmp(orden, "in") == 0 || strcmp(orden, "into") == 0) {
			res = IN;
		}
		else if (strcmp(orden, "out") == 0) {
			res = OUT;
		}

		return res;
	}


	void Reader::executeSimpleAction(Stage* mapa, const char* &orden) {

		if (strcmp(orden, "inventory") == 0 || strcmp(orden, "i") == 0) {
			mapa->getSheriff()->showInventory();
		}
		else if (strcmp(orden, "diagnostic") == 0) {
			mapa->getSheriff()->showDiagnostic();
		}
		else if (strcmp(orden, "hi") == 0 || strcmp(orden, "hello") == 0) {
			const char * loc = (mapa->getPosition()->getName()).c_str();
			mapa->addScore(mapa->getSheriff()->sayHi(loc));
		}
		else if (strcmp(orden, "restart") == 0) {
			mapa->restart(orden);
		}
		else if (strcmp(orden, "examine") == 0) {
			mapa->examine();
		}
		else if (strcmp(orden, "quit") == 0 || strcmp(orden, "q") == 0) {
			mapa->quit(orden);
		}
		else if (strcmp(orden, "vervose") == 0) {
			mapa->vervose();
		}
		else if (strcmp(orden, "superbrief") == 0) {
			mapa->superbrief();
		}
		else if (strcmp(orden, "score") == 0) {
			mapa->showScore();
		}//look
		else {
			cout << "This is not an order " << endl;
		}
	}

	int Reader::isObject(Stage* mapa, const char* & orden, int type) {
		int res = 1;

		//buscar entre los objetos de la sala

		return res;
	}

	int Reader::isItem(Stage* mapa, const char* & orden, int type) {
		int res = 1;

		//buscar entre los objetos del inventario

		return res;
	}


	int Reader::executeCompostActionDouble(Stage* mapa, const char** &orden, const int total_palabras) {
		int res = -1;

		if (strcmp(orden[0], "go") == 0 || (strcmp(orden[0], "climb") == 0 && (strcmp(orden[1], "up") == 0 || strcmp(orden[1], "down") == 0))) {//climb (up/down) (location)
			int dir = isDirection(orden[1]);
			if (dir != -1){
				mapa->move(isDirection(orden[1]));
				res = 0;
			}
			else{
				cout << "You can't move to " << orden[1] << endl;
				res = 0;
			}
		/*else if (strcmp(orden[0], "open") == 0) {//open (container/location)
		if (isObject(mapa, orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "close") == 0) {//close (container/location)
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "move") == 0 ) {//move (object)
		if (esObjeto(orden[1],6))
		res = 4;
		}else if (strcmp(orden[0], "drop") == 0) {//drop(item)
		if (esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "break") == 0) {//break (object)
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "eat") == 0) {//eat item
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "drink") == 0) {//drink item
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "examine") == 0) {//examine(object / item / location)
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "read") == 0) {//read(object / item legible)
		if (esObjeto(orden[1], 6) || esItem(orden[1], 6))
		res = 3;
		}else if (strcmp(orden[0], "save") == 0) {//save(name)
		if (total_palabras == 2)
		res = 3;
		}else if (strcmp(orden[0], "restore") == 0) {//restore(name)
		if (total_palabras == 2)
		res = 3;
		*/
		}else if (strcmp(orden[0], "get") == 0 || strcmp(orden[0], "take") == 0 || strcmp(orden[0], "pick") == 0 ) {//get / take / pick 
			if (strcmp(orden[1], "all") == 0){
				int elems = mapa->getPosition()->getNumObjects();
				for (int i = 0; i < elems; ++i)
					mapa->getSheriff()->addObject(mapa->getPosition()->obtainObject(i));
				cout << "All objects taked" << endl;
				res = 0;
			}
			else if (isObject(mapa, orden[1], 6)) {
				Object * toAdd = mapa->getPosition()->getObject(orden[1]);
				mapa->getSheriff()->addObject(toAdd);
			}
		}
		else {
			cout << "This is not an order " << endl;
		}

		return res;
	}

	int Reader::executeCompostActionTriple(Stage* mapa, const char** &orden, const int total_palabras) {
		int res = -1;

		if (strcmp(orden[0], "turn") == 0) {//turn (on/off) (control)
			if (strcmp(orden[1], "on") == 0 || strcmp(orden[1], "off") == 0)
				if (isObject(mapa,orden[2], 6))
					res = 3;
		}else if ((strcmp(orden[0], "pick") == 0 && strcmp(orden[1], "up") == 0)) {// pick up[all](objet)
			if (strcmp(orden[2], "all") == 0){
				res = 3;
			}
			else if (isObject(mapa,orden[2], 6)){
			
			}
		}
		else {
			cout << "This is not an order " << endl;
		}
		
		return res;
	}

	int Reader::executeCompostActionFourth(Stage* mapa, const char** &orden, const int total_palabras) {
		int res = -1;

		if (strcmp(orden[0], "put") == 0) {//put (item) in (container)
			if (isItem(mapa,orden[1], 6))
				if (strcmp(orden[2], "in") == 0)
					if (isObject(mapa, orden[3], 6) || isItem(mapa, orden[3], 6))
						res = 3;
		}else if (strcmp(orden[0], "attack") == 0 || strcmp(orden[0], "kill") == 0) {//attack / kill(creature) with(attack object)
			if (isItem(mapa, orden[1], 6))
				if (strcmp(orden[2], "with") == 0)
					if (isObject(mapa, orden[3], 6) || isItem(mapa, orden[3], 6))
						res = 3;
		}
		else {
			cout << "This is not an order " << endl;
		}

		return res;
	}

	int Reader::executeCompostActionFifth(Stage* mapa, const char** &orden, const int total_palabras) {
		int res = -1;
				 
		if (strcmp(orden[0], "turn") == 0) {//turn (on/off) (control) [with (object / item)]
			if (strcmp(orden[1], "on") == 0 || strcmp(orden[1], "off") == 0)
				if (isObject(mapa, orden[2], 6))
					res = 3;
		}else if ((strcmp(orden[0], "pick") == 0 && strcmp(orden[1], "up") == 0)) {//get / take / pick / pick up[all](objet)
			if (isObject(mapa, orden[2], 6))
				if (strcmp(orden[3], "with")==0)
					if (isObject(mapa, orden[4], 6) || isItem(mapa, orden[4], 6))
						res = 3;
		}
		else {
			cout << "This is not an order " << endl;
		}
		return res;
	}

	void Reader::executeOrder(Stage* mapa,const char** &orden, const int total_palabras) {

		if (total_palabras == 0)
			cout << "There is no order " << endl;
		else if (total_palabras == 1){
			int simple_order = isDirection(orden[0]);
			if (simple_order != -1){
				mapa->move(simple_order);
			}
			else {
				executeSimpleAction(mapa, orden[0]);
			}
		}
		else if (total_palabras == 2){
			executeCompostActionDouble(mapa, orden, total_palabras);
		}
		else if (total_palabras == 3){
			//executeCompostActionTriple(mapa, orden, total_palabras);
			cout << "This is not an order " << endl;
		}
		else if (total_palabras == 4){
			//executeCompostActionFourth(mapa, orden, total_palabras);
			cout << "This is not an order " << endl;
		}
		else if (total_palabras == 5){
			//executeCompostActionFifth(mapa, orden, total_palabras);
			cout << "This is not an order " << endl;
		}
		else{
			cout << "This is not an order " << endl;
		}
	}

	const char** Reader::getWords(char* orden, int &totalPalabras) {
		char lista_palabras[MAX_PALABRAS][20];
		char** plista_palabras = new char*;
		totalPalabras = -1;
		if (strlen(orden) > 0){
			for (int i = 0; ++totalPalabras < 10; ++i){
				int j = -1;
				for (; orden[i] != ' ' && orden[i] != '\0'; ++i){
					lista_palabras[totalPalabras][++j] = tolower(orden[i]);
				}
				lista_palabras[totalPalabras][++j] = '\0';
				if (orden[i] == '\0')
					break;
			}
		}
		++totalPalabras;

		if (totalPalabras != 0){
			*plista_palabras = new char[totalPalabras];
			for (int i = 0; i < totalPalabras; ++i){
				plista_palabras[i] = new char[strlen(lista_palabras[0]) + 1];
				strcpy_s(*(plista_palabras + i), strlen(lista_palabras[i]) + 1, lista_palabras[i]);
			}
		}

		return const_cast<const char **>(plista_palabras);
	}