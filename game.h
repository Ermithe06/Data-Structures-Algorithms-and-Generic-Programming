class Player {
	public:
		Player();
		int getXCoord() const;
		void setXCoord(int x);
		int getYCoord() const;
		void setYCoord(int y);
		int getCoinCount() const;
		int getPowerUpCount() const;
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void pickUpCoin();
		void pickUpPowerUp();

	private:
		int xCoord;
		int yCoord;
		int coinCount;
		int powerUpCount;
};

class Coins {
	public:
		Coins();
		int getXCoord() const;
		int getYCoord() const;

	private:
		int xCoord;
		int yCoord;
};

class PowerUp {
	public:
		PowerUp();
		int getXCoord() const;
                int getYCoord() const;

        private:
                int xCoord;
                int yCoord;
};

