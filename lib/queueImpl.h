#ifndef QUEUE_IMPL
#define QUEUE_IMPL
#include<iostream>
#include<exception>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include "emptyqueue.h"
//#include "queue.h"

template <class T>
Queue<T>::Queue(){ //constructor
	head = NULL;
	tail = NULL;
	size = 0;
	
}

template <class T>
Queue<T>::~Queue(){
	QueueItem<T> *iter = this->tail;
	while(size > 0)
	{
		iter = iter->prev;
		delete iter->next;
		size--;
	}
	delete iter;
	
 }

template <class T>
void Queue<T>::enqueue (const T & item){
		QueueItem<T> *temp = new QueueItem<T>;
		temp->item = item;
		
	if (this->isEmpty()){
		head = temp;
		tail = temp;
		//head->next = NULL;
	}
	else{
		tail->next = temp;
		temp->prev = tail;
		tail=temp;
		tail->next = NULL;
	}
	(this->size)++;
	//delete temp;
  }
      /* adds the item to the end of the queue.
         The same item may be added many times. */
template <class T>
void Queue<T>::dequeue (){
	if(this->isEmpty()){
		throw EmptyQueueException();
	}
	else{
		  if(size ==1){
			head = NULL;
			tail = NULL;
			(this->size)--;
		  }
		  else{
			  head = head->next; //redirect pointers 
			  delete head->prev;	//deallocate desired pointer
			  (this->size)--;
		  }
	}
}
      /* removes the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */
template <class T>
const T & Queue<T>::peekFront (){
	if(this->isEmpty()){
		throw EmptyQueueException();	//changed to emptyqueue exception
	}
	else{
		return head->item;
	}
}
      /* returns the front element of the queue. 
         Throws an EmptyQueueException when called on an empty queue.
         EmptyQueueException should inherit from std::exception. */
template <class T>
bool Queue<T>::isEmpty (){
	if(size==0){
		return true;
	}
	else{
		return false;
	}
}
      /* returns whether the queue is empty. */

#endif
