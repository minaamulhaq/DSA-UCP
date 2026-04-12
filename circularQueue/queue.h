#include<iostream>
using namespace std;
template<class T>
class queue{
protected:
    int currentSize;
    int maxSize;
    T* arr;
public:
    virtual void enqueue(T) = 0;
    virtual void dequeue() = 0;
    virtual T top()= 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void display()= 0;
    queue(int);
    ~queue();

    
};
template<class T>
queue<T>::queue(int s){
    this->currentSize = 0;
    this->maxSize = s;
    this->arr = new T[s];
}
template<class T>
queue<T>::~queue(){
    delete [] this->arr;
}