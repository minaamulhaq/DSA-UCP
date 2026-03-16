#include "stack.h"
template<class T>
class myStack:public stack<T>{
    public:
    void push(T);
    void pop();
    T top();
    bool isEmplty();
    bool isFull();
    void display();
    myStack(int);
};
template<class T>
void myStack<T>::display(){
    
    for(int i=0; i<this->currentSize; i++){
        cout << this->arr[i] << endl;
    }
}

template<class T>
T myStack<T>::top(){
       if(!isEmplty()){
        T value = this->arr[this->currentSize-1];
        return value;
       }else{
        throw runtime_error("Stack is empty");
       }
   
}



template<class T>
void myStack<T>::pop(){
    if(!isEmplty()){
        this->currentSize--;
        cout << "Value is "<<  this->arr[this->currentSize] << endl;
       
    }else{
        cout << "Stack is Empty"<<endl;
    }
}



template<class T>
void myStack<T>::push(T value){
    if(!isFull()){
        this->arr[this->currentSize] = value;
        this->currentSize++;
    }else{
        cout << "Stack is Full"<< endl;
    }
 }
template<class T>
bool myStack<T>::isFull(){
    return this->currentSize == this->maxSize-1;
}
template<class T>
bool myStack<T>::isEmplty(){
    return this->currentSize == 0;
}

template<class T>
myStack<T>::myStack(int s):stack<T>(s){}