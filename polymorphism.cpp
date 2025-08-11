#include "polymorphism.h"

Player::Player(){
}
Duck::Duck() : Player(){
}
void Duck::typeToRun(){ 
	cout << "Duck" << endl; 
}

Goose::Goose() : Player(){
}
void Goose::typeToRun(){ 
	cout << "Goose" << endl; 
}

Container::Container(int n) : size(n)
{
    	players = new Player*[size];
}

Container::Container(const Container& other) : size(other.size)
{
    	players = new Player*[size];
    	for (int i = 0; i < size; i++)
    	{
        	if (dynamic_cast<Goose*>(other.players[i])){
            	players[i] = new Goose(*dynamic_cast<Goose*>(other.players[i]));
        	}else{
            		players[i] = new Duck(*dynamic_cast<Duck*>(other.players[i]));
    		}
	}
}

Container& Container::operator=(const Container& other)
{
    	if (this != &other)
    	{
        	for (int i = 0; i < size; i++){
            		delete players[i];
		}
        	delete[] players;

        	size = other.size;
        	players = new Player*[size];
        	for (int i = 0; i < size; i++){
            		if (dynamic_cast<Goose*>(other.players[i])){
                		players[i] = new Goose(*dynamic_cast<Goose*>(other.players[i]));
            		}else{
                		players[i] = new Duck(*dynamic_cast<Duck*>(other.players[i]));
        		}
		}
    	}
    return *this;
}

Container::~Container()
{
    	for (int i = 0; i < size; i++){
        	delete players[i];
    	}
	delete[] players;
}

void Container::set(int index, Player* p){
    	players[index] = p;
}

Player* Container::get(int index) const{
    	return players[index];  
}

int Container::getSize() const{
    	return size;
}

