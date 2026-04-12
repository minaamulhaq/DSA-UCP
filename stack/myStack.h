#include "stack.h"
template<class T>
class myStack:public stack<T>{
    public:
    void push(T);
    void pop();
    T top();
    bool isEmpty();
    bool isFull();
    void display();
    myStack(int);
    myStack(const myStack<T>& other);
};
template<class T>
void myStack<T>::display(){
    
    for(int i=0; i<this->currentSize; i++){
        cout << this->arr[i] << endl;
    }
}

template<class T>
T myStack<T>::top(){
       if(!isEmpty()){
        T value = this->arr[this->currentSize-1];
        return value;
       }else{
        throw runtime_error("Stack is empty");
       }
   
}



template<class T>
void myStack<T>::pop(){
    if(!isEmpty()){
        this->currentSize--;
        // cout << "Value is "<<  this->arr[this->currentSize] << endl;     
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
myStack<T>::myStack(const myStack<T>& other) : stack<T>(other.maxSize)
{
    this->currentSize = other.currentSize;

    // Allocate new memory
    this->arr = new T[this->maxSize];

    // Copy elements
    for(int i = 0; i < this->currentSize; i++)
    {
        this->arr[i] = other.arr[i];
    }
}
template<class T>
bool myStack<T>::isEmpty(){
    return this->currentSize == 0;
}

template<class T>
myStack<T>::myStack(int s):stack<T>(s){}