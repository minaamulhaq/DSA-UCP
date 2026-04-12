#include "myStack.h"
#include<string>
// Scenario – Stack Overflow & Underflow 
// • Imagine a student putting books on a small table: 
// o If the table is already full and the student tries to place another book → Stack Overflow. 
// o If the table is empty and the student tries to remove a book → Stack Underflow. 
// • Demonstrate these situations by creating a program that deliberately causes overflow and 
// underflow and prints clear error messages. 
int main(){
    myStack<string> table(3);
    table.push("Book 1");
    table.push("Book2");
    table.push("Book3");
    table.push("Book4");
    table.display();
    table.pop();
    cout << table.top()<<endl;
    table.pop();
    table.pop();
    return 0;
}