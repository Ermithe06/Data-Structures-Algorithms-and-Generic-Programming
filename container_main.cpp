#include "container.h"

int main() {
    Container c;
    char selection = '\0';

    do {
        cout << "Task Menu: " << endl;
        cout << "A. Add Task " << endl;
        cout << "U. Update Task" << endl;
        cout << "D. Delete Task" << endl;
        cout << "P. Print out the list of tasks" << endl;
        cout << "Q. Quit" << endl;
        cin >> selection;

        switch (selection) {
            case 'a':
            case 'A': {
                Task t;
                cin >> t;
                c.add(t);
                break;
            }
            case 'u':
            case 'U': {
                string title;
                cout << "Enter title of task to update: ";
                cin >> title;
                c.update(title);
                break;
            }
            case 'd':
            case 'D': {
                string title;
                cout << "Enter title of task to delete: ";
                cin >> title;
                c.remove(title);
                break;
            }
            case 'p':
            case 'P':
                cout << c;
                break;
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Invalid option, make a new selection" << endl;
                break;
        }
    } while (selection != 'q' && selection != 'Q');

    return 0;
}

