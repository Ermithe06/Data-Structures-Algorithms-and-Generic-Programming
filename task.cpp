#include "task.h"

Task::Task(){
	title = "";
    	description = "";
    	dueDate = "";
    	isCompleted = false;
}

ostream& operator<<(ostream& o, const Task& t) {
    o << "Title: " << t.getTitle() << "\n";
    o << "Description: " << t.getDescription() << "\n";
    o << "Due Date: " << t.getDueDate() << "\n";

    o << "Completion status: ";
    if (t.getIsCompleted()) {
        o << "Completed";
    } else {
        o << "Need To Be Completed";
    }

    return o;
}

istream& operator>>(istream& i, Task& t) {
	string title, description, dueDate;
    	char isCompleted;

	cout << "Enter Title: ";
    	cin >> title;
    	t.setTitle(title);
	
	cout << "Enter description: ";
	i >> description;
	t.setDescription(description);

	cout << "Enter due date: ";
	i >> dueDate;
	t.setDueDate(dueDate);
	
	cout << "Is the task complete (Y/N): ";
	i >> isCompleted;

	if (isCompleted == 'Y' || isCompleted == 'y') {
    		t.setIsCompleted(true);
    		cout << "Completed" << endl;
	} else if (isCompleted == 'N' || isCompleted == 'n') {
    		t.setIsCompleted(false);
    		cout << "Need To Be Completed" << endl;
	} else {
    		cout << "Need to Be completed by default" << endl;
    		t.setIsCompleted(false);
}
	return i;
}

string Task::getTitle() const {
	return title;
}

string Task::getDescription() const {
        return description;
}

string Task::getDueDate() const {
        return dueDate;
}

bool Task::getIsCompleted() const {
	return isCompleted;
}

void Task::setTitle(string title) {
	this->title = title;
}

void Task::setDescription(string description) { 
        this->description = description;
}

void Task::setDueDate(string dueDate) { 
        this->dueDate = dueDate;
}

void Task::setIsCompleted(bool isCompleted) {
	this->isCompleted = isCompleted;
}
