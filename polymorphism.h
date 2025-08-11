#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Base class
class Player
{
	public:
    		virtual void typeToRun() = 0; //pure virtual function
	protected: //only the Goose and Duck class has access
    		Player(); 
};

//Derived class, subclass of Player class
class Duck : public Player
{
	public:
    		Duck();
    		void typeToRun(); //
};

//Derived class, subclass of Player class
class Goose : public Player
{
	public:
    		Goose();
    		void typeToRun();
};

//container class to manage memory
class Container
{
	public:
    		Container(int n);
    		Container(const Container& other); 
    		Container& operator=(const Container& other); 
    		~Container();

    		void set(int index, Player* p);
    		Player* get(int index) const;  
    		int getSize() const;

	private:
    		Player** players;
    		int size;
};


