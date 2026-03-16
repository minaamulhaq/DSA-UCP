#include "myStack.h"
int main(){
    myStack<int> obj(5);
    obj.push(5);
    obj.push(10);
    obj.push(9);
    obj.push(4);
    obj.push(2);
    obj.push(2);
    obj.display();
    obj.pop();
    obj.display();
    cout <<"Value on top "<< obj.top()<<endl;
    obj.pop();
    obj.pop();
    obj.pop();
  
    obj.display();

    return 0;
}