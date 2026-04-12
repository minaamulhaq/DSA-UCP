#include <iostream>
#include "myStack.h"   // your file
using namespace std;

int main() {
    myStack<string> calls(5);   // stack of calls

    int choice;
    string name;

    do {
        cout << "\n--- Mobile Call Stack ---\n";
        cout << "1. New Call\n";
        cout << "2. End Call\n";
        cout << "3. Current Call\n";
        cout << "4. Check Empty\n";
        cout << "5. Display Calls\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter call name/number: ";
                cin >> name;
                calls.push(name);
                break;

            case 2:
                calls.pop();
                break;

            case 3:
                try {
                    cout << "Current Call: " << calls.top() << endl;
                } catch (exception &e) {
                    cout << e.what() << endl;
                }
                break;

            case 4:
                if (calls.isEmpty())
                    cout << "No active calls.\n";
                else
                    cout << "Calls are active.\n";
                break;

            case 5:
                cout << "Call Stack:\n";
                calls.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}