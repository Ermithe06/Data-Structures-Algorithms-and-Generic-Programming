#include "task.h"

void Add(Task*& tasks, int& numTasks, int& maxTasks);
void Update(Task* tasks, int numTasks);
void Delete(Task*& tasks, int& numTasks);
void Print(Task* tasks, int numTasks);

int main() {
    int numTasks = 0, maxTasks = 2;
    Task* tasks = new Task[maxTasks];
    Task t;
    char selection = '\0';

    do {
        cout << "Task Menu: " << endl;
        cout << "A. Add Task" << endl;
        cout << "U. Update Task" << endl;
        cout << "D. Delete Task" << endl;
        cout << "P. Print out the list of tasks" << endl;
        cout << "Q. Quit" << endl;
        cin >> selection;
        
        switch(selection) {
            case 'a':
            case 'A': {
                Add(tasks, numTasks, maxTasks);
                break;
            }
                
            case 'u':
            case 'U':
                Update(tasks, numTasks);
                break;
            
            case 'd':
            case 'D':
                Delete(tasks, numTasks);
                break;
            
            case 'p':
            case 'P':
                Print(tasks, numTasks);
                break;
            
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Not an option, choose from menu" << "\n";
                break;
        }
    } while(selection != 'q' && selection != 'Q');
    delete [] tasks;

    return 0;
}

void Add(Task*& tasks, int& numTasks, int& maxTasks){
  if(numTasks == maxTasks) {
                maxTasks += 2;
                Task* temp = new Task[maxTasks];
                for (int i = 0; i < numTasks; i++) {
                        temp[i] = tasks[i];
                }
                delete[] tasks;
                tasks = temp;
        }
        
        Task newTask;  
        cin >> newTask;
        tasks[numTasks] = newTask;
        numTasks++;
}

void Update(Task* tasks, int numTasks) {
    string title;
    cout << "Enter the title of the task to update: ";
    cin >> title;
    
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

void Delete(Task*& tasks, int& numTasks){
    cout << "Enter the task to be deleted: ";
    string title;
    cin >> title;
    int index = -1;

    for(int i = 0; i < numTasks; i++) {
        if(tasks[i].getTitle() == title) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout << "Task not found" << endl;
        return;
    }

    for(int i = index; i < numTasks-1; i++) {
        tasks[i] = tasks[i+1];
    }
    numTasks--;
    cout << "Task deleted" << endl;
}

void Print(Task* tasks, int numTasks){
    if (numTasks == 0) {
        cout << "No tasks" << endl;
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].getTitle() != ""){
		cout << tasks[i] << endl << endl;
	}
    }
}

