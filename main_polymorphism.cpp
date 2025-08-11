#include "polymorphism.h"

int main()
{
    	srand(time(0));  //seed the random number generator

    	int numPlayers;

	do{
    		cout << "Enter the number of players: ";
    		cin >> numPlayers;
		if(numPlayers <= 0){
        		cout << "Invalid number of players, please enter only positive numbers above 0" << endl;
    		}
	}while(numPlayers <= 0);

    	int gooseIndex = rand() % numPlayers;

    	Container container(numPlayers);

    	for (int i = 0; i < numPlayers; i++){
        	if (i == gooseIndex){
            		container.set(i, new Goose());
		}else{
            		container.set(i, new Duck());
		}
    	}

    	cout << "\nRandom Goose index: " << gooseIndex << endl;
    	cout << "Looking for the Goose...\n" << endl;

    	for (int i = 0; i < numPlayers; i++){
        	Player* p = container.get(i);
        	p->typeToRun();

        	if (i == gooseIndex){
            		cout << "\nThe Goose has been found! Game over.\n" << endl;
            		break;
        	}
    	}

    	return 0;
}

