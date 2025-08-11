#include "game.h"
#include <cstdlib>

	Player::Player() {
		xCoord = 1;
		yCoord = 1;
		coinCount = 0;
		powerUpCount = 0;
	}

	void Player::moveUp() {
		yCoord++;
	}

	void Player::moveDown() {
		yCoord--;
	}

	void Player::moveLeft() {
		xCoord--;
	}

	void Player::moveRight() {
		xCoord++;
	}

	int Player::getXCoord() const{
		return xCoord;
	}

	int Player::getYCoord() const {
		return yCoord;
	}

	void Player::setXCoord(int x){
		x = xCoord;
	}

	void Player::setYCoord(int y){
		y = yCoord;
	}

	void Player::pickUpCoin() {
		coinCount++;
	}

	int Player::getCoinCount() const{
		return coinCount;
	}

	int Player::getPowerUpCount() const{
		return powerUpCount;
	}

	Coins::Coins(){
                xCoord = rand() % 10 + 1;
                yCoord = rand() % 10 + 1;   
        }
		
	int Coins::getXCoord() const {
    		return xCoord;
	}

	int Coins::getYCoord() const {
    		return yCoord;
	}
	
	void Player::pickUpPowerUp() {
                powerUpCount++;
        }

	PowerUp::PowerUp(){ 
                xCoord = rand() % 10 + 1;
                yCoord = rand() % 10 + 1;
        }
                
        int PowerUp::getXCoord() const {
                return xCoord;
        }
                
        int PowerUp::getYCoord() const {
                return yCoord;
        }




