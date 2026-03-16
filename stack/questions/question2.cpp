// Question #2
/*
2. Check Balanced Parentheses 
• Explore how stacks can be used to check if parentheses are balanced. 
• Example: 
§ Input → "((a+b)*c)" → Balanced  
§ Input → "((a+b)" → Not Balanced  
§ Scenario: Like opening and closing brackets in math – each opening must have a 
matching closing. 
*/
// Solution 
/*
As We know the Number of starting bracket and closing brackets are equal 
if they are equal equation is balanced  other vised wquaton is not balnaced 
2: if closing bracket comes before starting bracket then equaiton is not balnced 
so for checking balancing 
step 1 push if the starting bracket comes ( ;
step 2:pop if the closing bracket comes ) ;
step 3:if stack is empty and closing bracket comes ) so the equation is not balnced
step 4:if after comoleting the loop if the stack remains empty so the eqation is balanced othervise not balnced
*/


#include"../myStack.h"
#include<string>

int main(){
    string input;
    cout << "Enter the Equation : ";
    getline(cin,input);
    int size = input.length();
    myStack<char> myObj(size+1);
    for(int i = 0; i<size; i++){
        char temp = input[i];
        if(temp=='('){
            myObj.push(temp);
        }else if(temp==')'){
            if(!myObj.isEmpty()){
                myObj.pop();
            }else{
                cout << "Equation is not balanced"<<endl;
                return 0;
            }
        }
    }
    if(myObj.isEmpty()){
        cout << "Equation is Balanced"<<endl;
    }else{
        cout << "Equation is not balanced"<<endl;
    }
    return 0;
}