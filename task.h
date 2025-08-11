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

