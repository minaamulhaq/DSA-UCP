// Create a program to reverse a string using a stack. 
// • Example: Input → "Hello" , Output → "olleH". 
// • Scenario: Think of writing letters on paper and then reading them back in reverse 
// order.
/*
 Solution : I am goin to use the stack for this 
 1 : Input in a string from user 
 2 : find the length of string 
 3 : push the value in to the stack an dwhen the  value pop back the string becomes reverse 
 Note : I know this is not good method for reversing a string but i am exporing this only to show the aplication of stack
*/

#include"../myStack.h"
#include<string>
int main(){
    string input;
    cout << "Enter a String Input :";
    getline(cin, input);
    int size = input.length();
    
    myStack<char> obj(size+1);

    for(int i=0;i<size; i++){
        obj.push(input[i]);
    }
    for(int i = 0; i<size; i++){
        input[i] = obj.top();
        obj.pop();
    }
    cout << "Reversed String :"<< input<<endl;
    return 0;
}