
#include <iostream>
//#include "mapImpl.h"
#include<iterator>
#include<vector>
//#include "projset.h"
//#include"mergesort.h"

using namespace std;
template <class T>
Set<T>::Set(){  // constructor for a new empty set
}

template <class T> 
Set<T>::Set(const Set<T> &other){ //deep copy constructor
	internalStorage = other.internalStorage;
}


template <class T> //OPERATOR has to delete existing memory
Set<T> &Set<T>::operator= (const Set<T> &other){
	internalStorage = other.internalStorage;
	return *this;
}	



template <class T>	
Set<T> Set<T>::setUnion(const Set<T> & other) const{
	/*vector<T> *thisvec = new vector<T>;
	for(Set<T>::Iterator it = this->begin(); it!=this->end(); ++it){
		thisvec->push_back(*it);
	}
	vector<T> *othervec = new vector<T>;
	for(Set<T>::Iterator it2 = other.begin(); it2!=other->end(); ++it2){
		othervec->push_back(*it2);
	}
	MergeSort::sort(thisvec);
	MergeSort::sort(othervec);
	vector<T> *a = new vector<T>;
	int i = 0, j = 0;
	while(i < thisvec.size() && j < othervec.size()){
		if(thisvec[i] ==othervec[j]){
			a->push_back(thisvec[i]);
			i++;
			j++;
		}
		else if (thisvec[i] >othervec[j]){
			a->push_back(othervec[j]);
			j++;
		}
		else {
			i++;
		}
	}
	Set<T> returned;
	for(int i = 0; i < a.size(); i++){
		returned->add(a[i]);
	}
	return returned;
	
	/*Set<T> *s = new Set<T>;
	*s = this;
	Map<T, int> *othermap = new Map<T, int>;
	*othermap = other.internalStorage;
	for(MapItem<T, int> *p = othermap->getHead(); p !=NULL; p=p->next){
		s->add(p->key);
	}
	return *s;*/
}
	

template <class T> //fix this
Set<T> Set<T>::setIntersection(const Set<T> & other) const{
	/*vector<T> *thisvec = new vector<T>;
	for(Set<T>::Iterator it = this->begin(); it!=this->end(); ++it){
		thisvec->push_back(*it);
	}
	vector<T> *othervec = new vector<T>;
	for(Set<T>::Iterator it2 = other.begin(); it2!=this->end(); ++it2){
		othervec->push_back(*it2);
	}
	MergeSort::sort(thisvec);
	MergeSort::sort(othervec);
	vector<T> *a = new vector<T>;
	 
	int i = 0, j = 0;
	while (i < thisvec->size() && j < othervec->size()){
		if(thisvec[i] > othervec[j]){
			j++;
		}
		else if (othervec[j] > thisvec[i]){
			i++;
		}
		else{
			a->push_back(thisvec[i]);
			i++;
			j++;
		}
	}
	Set<T> *returned = new Set<T>;
	for(int i = 0; i < a->size(); i++){
		returned->add(a[i]);
	}
	return returned;
	/*Set<T> *s = new Set<T>;
	Map<T, int> *othermap = new Map<T, int>;
	*othermap = other.internalStorage;
	for(const MapItem<T, int> *p = othermap->getHead(); p !=NULL; p=p->next){
		/*for(const MapItem<T, int> *d = *(this.internalStorage.getHead()); d !=NULL; d=d->next){
			if(d->key == p->key){
				s.add(d->key);
			}
		}
		if (this.contains(p->key)){
			s.add(p->key);
		}
	}
	return *s;*/
}



template <class T>    
Set<T>::~Set(){
	//delete this->internalStorage;
	/*MapItem<T,int> *p;
	MapItem<T, int> *d = p->next;
	while(d!=NULL){
		delete p;
		d = d->next;
	}
	delete d; //check this*/
  } // destructor

template <class T>
int Set<T>::sizeset () const{ // returns the number of elements in the set
  	return internalStorage.size();

}



template <class T>
void Set<T>::add (T item){
		internalStorage.add(item,item);
      /* Adds the item to the set.
         If the item is already in the set, it should do nothing.
      */
}
	
template <class T>
void Set<T>::remove (const T &item){
		internalStorage.remove(item);
    } 
		
     /* Removes the item from the set.
        If the item was not in the set, it should do nothing. */

template <class T>
bool Set<T>::contains (const T &item) const{
	//SetItem<T> *newItem = new SetItem<T>;
		//newItem->sItem = item;	
	//SetItem<T> *newItem = new SetItem(item);
	bool succ = false;
	int n = internalStorage.get(item, succ);
	if (succ == true){
		return true;
	}
	else{
		return false;
	}
}
     /* Returns whether the item is in the set. */
template <class T>
Map<T, int> Set<T>::getIS() const{
	return internalStorage;
}
	

template <class T>
void Set<T>::merge (const Set<T> & other){
	this->internalStorage.merge(other.getIS());

}	
     /* Adds all elements of other to this set. 
        However, will not create duplicates, i.e., it ignores elements
        already in the set. */



