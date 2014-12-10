//#include "projmap.h"
#include <iostream>
#include<string>
#include <sstream>
#include "nosuch.h"
//#include<exception>

using namespace std;
template <class keyType, class valueType>
Map<keyType, valueType>::Map(){ //constructor
	head = NULL;
	current = NULL;
	
}

template <class keyType, class valueType>
Map<keyType, valueType>::Map(const Map<keyType, valueType> &other){
	if(other.head !=NULL){
		for(MapItem<keyType, valueType> *p = other.head; p !=NULL; p=p->next){
			this->add(p->key, p->value);
		}
	}
}
template <class keyType, class valueType> //OPERATOR has to delete existing memory
Map<keyType, valueType> &Map<keyType, valueType>::operator= (const Map<keyType, valueType> &other){
	//For loop that deletes or removes all items in this
	MapItem<keyType, valueType> *temp;
	for(MapItem<keyType, valueType> *p = this->head; p !=NULL; p=temp){
		temp = p->next;
		delete p;	
	}

	for(MapItem<keyType, valueType> *p = other.head; p !=NULL; p=p->next){
		this->add(p->key, p->value);
	}
	return *this;
}
	
/*template <class keyType, class valueType>
void Map<keyType, valueType>::first(){
	if (head!=NULL){
		this->current =this->head;
	}
	else{ 
		throw NoSuchElementException( );}
		
}

template <class keyType, class valueType>
void Map<keyType, valueType>::next(){
	if ((current->next)!=NULL){
	this->current=this->current->next;
	}
	else{ 
		throw NoSuchElementException( );}
}
	

template <class keyType, class valueType>
const keyType Map<keyType, valueType>::getCurrentKey(){
	return this->current->key;
}*/

template <class keyType, class valueType>
const MapItem<keyType, valueType>* Map<keyType, valueType>::getHead(){
	return this->head;
}

/*template <class keyType, class valueType>
const MapItem<keyType, valueType>* Map<keyType, valueType>::getCurrentItem(){
	return this->current;
}

template <class keyType, class valueType>
const valueType Map<keyType, valueType>::getCurrentValue(){
	return this->current->value;
}*/





template <class keyType, class valueType>
Map<keyType, valueType>::~Map(){ //destructor deallocates pointers
	int sizemap;
	sizemap = this->size();
	MapItem<keyType, valueType> *p = head;
		while(p->next!=NULL){
			p=p->next; //find the last pair in the list
		}
	while(sizemap > 0){
		p = head->next;
		delete head; 
		head = p;
		sizemap--;
	}
	//delete head;
	delete p;
  }

template <class keyType, class valueType>
int Map<keyType, valueType>::size() const{
  int count = 0;
  for(MapItem<keyType, valueType> *p = head; p !=NULL; p=p->next){ //go through each item in map, for each one add to count
	count++;
  }
  return count;
}
		

template <class keyType, class valueType>
  void Map<keyType, valueType>::add(const keyType &key, valueType &value){ 
	MapItem<keyType, valueType> *newItem = new MapItem<keyType, valueType>; //create new map item
	newItem->key = key;
	newItem->value = value; //initialize its values
	newItem->next = NULL;
	if (head == NULL){
		head = newItem;
		head->prev = NULL;
	}
	else{
	 //CHECK TO SEE IF ALREADY THERE ---- if it is, then delete it
		MapItem<keyType, valueType> *p = head;
		while(p->next!=NULL){
			p=p->next; //find the last pair in the list
		}
		 //add new pair to end of list
		p-> next = newItem;
		newItem->prev = p;
		p = newItem;
		newItem->next = NULL;
	}
  }

template <class keyType, class valueType>
  void Map<keyType, valueType>::remove(keyType key){
	//bool succ = false;
	try{
	valueType val = this->get(key); //check to see if key already exists
	//if (succ == true){
	  for(MapItem<keyType, valueType> *p = head; p !=NULL; p=p->next){
		if(p->key == key){ //go through each pair in map, find desired key
		  p->prev->next = p->next; //redirect pointers 
		  p->next->prev = p->prev;
		  delete p;	//deallocate desired pointer
		}
	  }
	}
	catch (NoSuchElementException &d){
		cout << "No element found. " << endl;
	}
}


template <class keyType, class valueType>
valueType &Map<keyType, valueType>::get(const keyType &key) {
	bool success = false;	
	for(MapItem<keyType, valueType> *p = head; p !=NULL; p=p->next){ //go through every pair in list, if you find desired key, change value of success and return its value
		if(p->key == key){
			success = true;
			return p->value;
		}
	}
	if (success == false){
		throw NoSuchElementException();}
  }
	
template <class keyType, class valueType>
bool Map<keyType, valueType>::contains(const keyType &key) {
	bool success = false;	
	for(MapItem<keyType, valueType> *p = head; p !=NULL; p=p->next){ //go through every pair in list, if you find desired key, change value of success and return its value
		if(p->key == key){
			success = true;
			//return success;
		}
	}
	return success;
  }
//check to see if something is contained or not --> used to avoid try/catch statements, since i was running into an error in Qt with them

template <class keyType, class valueType>
  void Map<keyType, valueType>::merge(const Map<keyType, valueType> & other){
	MapItem<keyType, valueType> *d = head; //create new item 
	if (d !=NULL){ //if its not empty
	while(d->next !=NULL){  //find the last pair
		d=d->next;
	}
	for(MapItem<keyType, valueType> *p = other.head; p !=NULL; p=p->next){
		add(d->key, d->value); //go through every pair in other map and add them to end of current one
	}
  }
}





