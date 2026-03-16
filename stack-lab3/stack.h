#include<iostream>
using namespace std;
template<class T>
class stack{
protected:
    int currentSize;
    int maxSize;
    T*arr;
public:
    virtual void push(T) = 0;
    virtual void pop() = 0;
    virtual T top()= 0;
    virtual bool isEmplty() = 0;
    virtual bool isFull() = 0;
    stack(int);
    ~stack();

    
};
template<class T>
stack<T>::stack(int s){
    this->currentSize = 0;
    this->maxSize = s;
    this->arr = new T[s];
}
template<class T>
stack<T>::~stack(){
    delete [] this->arr;
}