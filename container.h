#include<string>
#include<iostream>
using namespace std;

class Task{
	friend ostream& operator<<(ostream& o, const Task& t);
	friend istream& operator>>(istream& i, Task& t);

private:
	string title;
	string description;
	string dueDate;
	bool isCompleted;

public:
	string getTitle() const;
	void setTitle(string title);
	string getDescription() const;
	void setDescription(string description);
	string getDueDate() const;
	void setDueDate(string dueDate);
	bool getIsCompleted () const;
	void setIsCompleted(bool isCompleted);

	Task();
};

class Container{
	friend ostream& operator<<(ostream& o, const Container& c);
	private:
		Task* tasks;
		int numTasks, maxTasks;

		void grow();
		
	public:
		Container();
		~Container();
		
		//Container a = b;
		Container(const Container& c);

		//Container b;
		// Container a = b;
		//a = b;
		//a.operator=(b);
		Container& operator=(const Container& c);
		
		void add(const Task& newTask);
		void update(const string& title);
		void remove(const string& title);
		void print() const;
};
