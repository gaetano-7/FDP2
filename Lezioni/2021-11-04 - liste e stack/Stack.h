//---------------------------------
// STACK DINAMICO
#ifndef STACK_H
#define STACK_H

#include "ListaT.h"
#include <assert.h>
#include<iostream>
using namespace std;
template <class T>
class Stack:protected List<T>
{
public:
	Stack():numElements(0) {}
	~Stack() { }
	bool push( const T& );
	void pop();
	T top(); 
	int size() const {return numElements;}
	using List<T>::empty; //Rende visibile empty di List
	bool full() const { return false; }

private:
 int numElements;

};

template <class T>
bool Stack<T>::push(const T& v)
{	
	List<T>::pushFront(v);
	++numElements;
	return true;
}

template <class T>
void Stack<T>::pop()
{
	assert(!empty());
	--numElements;
	T v;
	List<T>::popFront(v);
	return v;
	
}

template <class T>
T Stack<T>::top() 
{
	assert(!empty());
	//return List<T>::front()->value;
	T v=List<T>::front()->getValue();
	return v;
}

#endif
