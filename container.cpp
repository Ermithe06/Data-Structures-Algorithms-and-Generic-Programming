#include "container.h"

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

ostream& operator<<(ostream& o, const Container& c) {
    for (int i = 0; i < c.numTasks; i++) {
        if (c.tasks[i].getTitle() != "") {
            o << c.tasks[i] << endl;
        }
    }
    return o;
}

Container::Container() {
	numTasks = 0;
    	maxTasks = 2;
    	tasks = new Task[maxTasks];
}

Container::~Container() {
    	delete[] tasks;
}

Container::Container(const Container& c) {
    	numTasks = c.numTasks;
    	maxTasks = c.maxTasks;
    	tasks = new Task[maxTasks];
    	
	for (int i = 0; i < numTasks; i++) {
        	tasks[i] = c.tasks[i];
	}
}

Container& Container::operator=(const Container& c) {
    	if (this != &c) {
        	delete[] tasks;
        	numTasks = c.numTasks;
        	maxTasks = c.maxTasks;
        	tasks = new Task[maxTasks];

        	for (int i = 0; i < numTasks; i++) {
            		tasks[i] = c.tasks[i];
        	}
    	}
    return *this;
}

void Container::grow() {
    	maxTasks += 2;
    	Task* temp = new Task[maxTasks];
    	
	for (int i = 0; i < numTasks; i++) {
        	temp[i] = tasks[i];
    	}

    	delete[] tasks;
    	tasks = temp;
}

void Container::add(const Task& newTask) {
    	if (numTasks == maxTasks) {
		grow();
	}
    	tasks[numTasks++] = newTask;
}

void Container::update(const string& title) {
    	int index = -1;
    
	for (int i = 0; i < numTasks; i++) {
        	if (tasks[i].getTitle() == title) {
            	index = i;
            	break;
        	}
    	}

    	if (index == -1) {
        	cout << "Task not found" << endl;
        	return;
    	}

    	char userChoice;
    	cout << "Update type: (M)ark complete or (C)hange DueDate: ";
    	cin >> userChoice;

    	if (userChoice == 'm' || userChoice == 'M') {
        	tasks[index].setIsCompleted(true);
        	cout << "Marked as complete" << endl;
    	} else if (userChoice == 'c' || userChoice == 'C') {
        	string newDue;
        	
		cout << "Enter new due date: ";
        	cin >> newDue;
        	tasks[index].setDueDate(newDue);
        	cout << "Due date updated" << endl;
    	}
}

void Container::remove(const string& title) {
    	int index = -1;

    	for (int i = 0; i < numTasks; i++) {
        	if (tasks[i].getTitle() == title) {
            		index = i;
            		break;
        	}
    	}

    	if (index == -1) {
        	cout << "Task not found" << endl;
        	return;
    	}

    	for (int i = index; i < numTasks - 1; i++) {
        	tasks[i] = tasks[i + 1];
    	}
    	
	numTasks--;
    	cout << "Task deleted" << endl;
}

void Container::print() const {
	if (numTasks == 0) {
        	cout << "No tasks" << endl;
        	return;
    	}

    	for (int i = 0; i < numTasks; i++) {
        	if (tasks[i].getTitle() != "") {
            		cout << tasks[i] << endl;
        	}
    	}
}


