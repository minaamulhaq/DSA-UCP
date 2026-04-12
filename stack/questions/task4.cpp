#include <iostream>
#include "myStack.h"   // your stack class
using namespace std;

string text = "";

// Create stacks
myStack<char> undoStack(100);
myStack<char> redoStack(100);

// TYPE operation
void type(char x) {
    text += x;
    undoStack.push(x);

    // clear redo stack
    while (!redoStack.isEmpty()) {
        redoStack.pop();
    }

    cout << "Typed: " << x << endl;
}

// UNDO operation
void undo() {
    if (!undoStack.isEmpty()) {
        char ch = undoStack.top();
        undoStack.pop();

        // remove from text
        text.pop_back();

        redoStack.push(ch);

        cout << "Undo: " << ch << endl;
    } else {
        cout << "Nothing to undo\n";
    }
}

// REDO operation
void redo() {
    if (!redoStack.isEmpty()) {
        char ch = redoStack.top();
        redoStack.pop();

        text += ch;
        undoStack.push(ch);

        cout << "Redo: " << ch << endl;
    } else {
        cout << "Nothing to redo\n";
    }
}

// DISPLAY STATE
void displayState() {
    cout << "\nCurrent Text: " << text << endl;

    cout << "Undo Stack:\n";
    undoStack.display();

    cout << "Redo Stack:\n";
    redoStack.display();

    cout << "---------------------\n";
}

// MAIN
int main() {
    type('a');
    displayState();

    type('b');
    displayState();

    type('c');
    displayState();

    undo();
    displayState();

    undo();
    displayState();

    redo();
    displayState();

    type('d');
    displayState();

    cout << "\nFinal Text: " << text << endl;

    return 0;
}