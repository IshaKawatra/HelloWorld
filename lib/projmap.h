#ifndef MAP_H
#define MAP_H
#include<iterator> 
#include <iostream>
#include<string>
#include<cstring>


using namespace std;
template <class keyType, class valueType>
struct MapItem //create structure of each pair in a map
{
  keyType key;
  valueType value;
  MapItem<keyType,valueType> *prev, *next; //public pointers 
};

template <class FirstType, class SecondType> 
struct Pair {
   FirstType first;
   SecondType second;

   Pair (FirstType first, SecondType second)
      { this->first = first; this->second = second; }
   // we're very nice and give you this piece of difficult code for free :-P
};

template <class keyType, class valueType>
class Map
{
public:
  Map();
  Map (const Map<keyType, valueType> &other);
  ~Map(); //all functions
  Map<keyType, valueType> & operator= (const Map<keyType, valueType> &other);
  int size() const;
  //void first();
  //void next();
  const MapItem<keyType, valueType>* getHead();
  /*const MapItem<keyType, valueType>* getCurrentItem();
  const keyType getCurrentKey();
  const valueType getCurrentValue();*/
  void add(const keyType &key, valueType &value);
  void remove(keyType key);
  valueType &get(const keyType &key);
  void merge(const Map<keyType, valueType> & other);
  bool contains(const keyType &key);
  class Iterator{
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */
		 private:
			const Map<keyType, valueType> *whoIBelongTo;
			MapItem<keyType, valueType> *curr;
			Iterator(const Map<keyType, valueType> *m, MapItem<keyType, valueType> *p){
				whoIBelongTo = m; curr = p;
			}
			
         public:
			Iterator() { }
			~Iterator(){ }

			friend class Map<keyType, valueType>;
           Pair<keyType, valueType> operator* () const{
				return Pair<keyType, valueType>(curr->key, curr->value);
              // return the current (key, value) pair the iterator is at
			}
           Map<keyType,valueType>::Iterator operator++ (){
				curr = curr->next;
				return *this;
			}
              // advances the iterator (pre-increment)

           Map<keyType,valueType>::Iterator operator= (const Map<keyType,valueType>::Iterator & other){
				this->curr = other.curr;
				this->whoIBelongTo = other.whoIBelongTo;
				return *this;
			}
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Map<keyType,valueType>::Iterator & other) const{
				return (curr == other.curr && whoIBelongTo == other.whoIBelongTo);
			}
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Map<keyType,valueType>::Iterator & other) const{
				return (!this->operator==(other));
			}
              // returns whether this iterator is not equal to the other iterator
     };
	Map<keyType,valueType>::Iterator begin () const{
		return Map<keyType,valueType>::Iterator(this,head);
		}
       // returns an iterator initialized to the first element

     Map<keyType,valueType>::Iterator end () const{
		return Map<keyType,valueType>::Iterator(this, NULL);
		}
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */

  
private:
  MapItem <keyType, valueType> *head, *tail, *current; //private pointers
};

#include "projmapImpl.h"
#endif 
