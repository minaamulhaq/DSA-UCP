#include <iostream>
#include "myStack.h"   // your stack
#include<string>
using namespace std;

// stack for directories
myStack<string> pathStack(100);

// cd folderName
void cd(string folder) {
    pathStack.push(folder);
    cout << "Entered: " << folder << endl;
}

// cd ..
void cdBack() {
    if (!pathStack.isEmpty()) {
        cout << "Going back from: " << pathStack.top() << endl;
        pathStack.pop();
    } else {
        cout << "Already at root directory\n";
    }
}

// pwd (print working directory)
void pwd() {
    if (pathStack.isEmpty()) {
        cout << "/ (root)\n";
        return;
    }

    cout << "Current Path: /";

    // TEMP stack to reverse order
    myStack<string> temp(100);

    // move to temp to reverse
    while (!pathStack.isEmpty()) {
        temp.push(pathStack.top());
        pathStack.pop();
    }

    // print and restore
    while (!temp.isEmpty()) {
        string folder = temp.top();
        temp.pop();

        cout << folder << "/";

        pathStack.push(folder); // restore original stack
    }

    cout << endl;
}

// MAIN
int main() {

    cd("home");
    cd("user");
    cd("documents");
    pwd();        // /home/user/documents/

    cdBack();
    pwd();        // /home/user/

    cd("downloads");
    pwd();        // /home/user/downloads/

    cdBack();
    cdBack();
    pwd();        // /home/

    cdBack();
    cdBack();     // already root

    pwd();        // /

    return 0;
}