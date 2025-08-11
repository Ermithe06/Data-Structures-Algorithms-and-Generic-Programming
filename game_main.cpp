#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() 
{
	srand(time(nullptr));

	Player player1;
	int min = 1, max = 10;

	int numOfMoves;

	Coins coins[10];
	PowerUp powerUps[2];

	bool collectedCoins[10] = {false};

	bool collectedPowerUps[2] = {false};	

	bool cannotCollect = false;

	do
	{	
		cout << "Choose a move:" << endl;
		cout << "W. Move Up" << endl;
		cout << "A. Move Left" << endl;
		cout << "S. Move Down" << endl;
		cout << "D. Move Right" << endl;
		char choice;
		cin >> choice;
		numOfMoves = pow(2, player1.getPowerUpCount());

		switch(choice) 
		{
			case 'A':
			case 'a':
			if(player1.getXCoord() - numOfMoves >= min)
			{
				for(int i = 0; i < numOfMoves; i++)
				{ 
					player1.moveLeft();
				}
			}else{                                  
                        	player1.setXCoord(min);
                	}

			break;
			case 'W':
			case 'w':
			if(player1.getYCoord() + numOfMoves <= max)
			{
				for(int i = 0; i < numOfMoves; i++)
                                {
					player1.moveUp();
				}
			}else{                                  
                        	 player1.setYCoord(max);
                	}
                
			break;
			case 'S':
			case 's':
			if(player1.getYCoord() - numOfMoves >= min)
			{
				for(int i = 0; i < numOfMoves; i++)
                                {
					player1.moveDown();
				}
			}else{
                        	 player1.setYCoord(min); 
                	}

			break;
			case 'D':
			case 'd':
			if(player1.getXCoord() + numOfMoves <= max)
			{
				for(int i = 0; i < numOfMoves; i++)
                                {
					player1.moveRight();
				}
			}else{
				player1.setXCoord(max);
			}

			break;
			default:
			cout << "Sorry, I don't understand" << endl;
		}

		cout << "Current location: (" << player1.getXCoord() << ", " << player1.getYCoord() << ")" << endl;
	
		for(int i = 0; i < 10; i++)
		{
			if(collectedCoins[i] == false && player1.getXCoord() == coins[i].getXCoord() && player1.getYCoord() == coins[i].getYCoord()) 
			{
				player1.pickUpCoin();
				collectedCoins[i] = true;
		 		cout << "(" << player1.getXCoord() << ", " << player1.getYCoord() << ") Coins:" << player1.getCoinCount() << endl;
			}
		}

		for(int i = 0; i < 2; i++)
                {
                        if(collectedPowerUps[i] == false && player1.getXCoord() == powerUps[i].getXCoord() && player1.getYCoord() == powerUps[i].getYCoord())
                        {
                                player1.pickUpPowerUp();
                                collectedPowerUps[i] = true;
                                cout << "(" << player1.getXCoord() << ", " << player1.getYCoord() << ") PowerUp:" << player1.getPowerUpCount() << endl;
                        }
                }

	cout << "Remaining coins:";
        bool remainingCoins = false;

        for (int i = 0; i < 10; i++)
        {
            int MovesFromCoinX = abs(player1.getXCoord() - coins[i].getXCoord());
            int MovesFromCoinY = abs(player1.getYCoord() - coins[i].getYCoord());

                if (MovesFromCoinX % numOfMoves != 0 || MovesFromCoinY % numOfMoves != 0)
                {
			cannotCollect = true;
                    	cout << " (" << coins[i].getXCoord() << ", " << coins[i].getYCoord() << ") CANNOT BE COLLECTED" << endl;
                }
	    	if (collectedCoins[i] == false)
        	{
                remainingCoins = true;
                cout << endl << "(" << coins[i].getXCoord() << ", "
                     << coins[i].getYCoord() << ")" << endl;
            }
        }
        if (remainingCoins == false) 
	{
		cout << " No more coins" << endl;
	}

	cout << "Remaining powerups:";
        bool remainingPowerUps = false;

        for (int i = 0; i < 2; i++)
        {
            if (collectedPowerUps[i] == false)
            {
                remainingPowerUps = true;
                cout << endl << "(" << powerUps[i].getXCoord() << ", "
                     << powerUps[i].getYCoord() << ")" << endl;
            }
        }

        if (remainingPowerUps == false) 
	{	
		cout << " No more powerups" << endl;
        }

		}while(player1.getCoinCount() < 10 && cannotCollect == false);

	if(cannotCollect == true)
	{
		cout << "You lost, better luck next time" << endl;
	}else
	cout << "You win!" << endl;
}
