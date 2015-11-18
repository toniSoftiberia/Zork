#include <iostream>
#include <string>
#include "Reader.hpp"
#include "Stage.hpp"

int main(void)
{	
	char orden[255];
	int total_palabras = 0;
	Stage *mapa = NULL;
	Reader *reader = new Reader();
	
	cout << "Wellcome to Spase Sheriff:" << std::endl;
	cout << "Realise 18/11/2015" << std::endl << std::endl;
	
	while (strcmp(orden, "q") != 0 && strcmp(orden, "quit") != 0){
		mapa = new Stage();
		strcpy_s(orden, "keep going");

		cout << "Just get pluton, you've received an alert from here and you have to go investigate" << std::endl << std::endl;

		cout << mapa->getStart()->getName() << endl;
		cout << mapa->getStart()->getDesc(mapa->getMode()) << endl;
		
		int total_palabras;
		const char ** lista_palabras;
		while (strcmp(orden,"r")!=0 && strcmp(orden,"restart")!=0 && strcmp(orden,"q")!=0 && strcmp(orden,"quit")!=0 ){
			cout << "Waiting for order:" << std::endl;
			cin.getline(orden, sizeof orden);
			
			if (strcmp(orden, "g") != 0)
				lista_palabras = reader->getWords(orden, total_palabras);
			reader->executeOrder(mapa, lista_palabras, total_palabras);
			cout << std::endl;
		}
		
		delete mapa; 
		cout << string(50, '\n');
	}
	
	cout << "Exiting Space Sheriff" << std::endl;
	cout << "I hope you enjoyed" << std::endl;
	system("PAUSE");
}
