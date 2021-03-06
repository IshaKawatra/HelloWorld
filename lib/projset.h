#ifndef SET_H
#define SET_H
#include<iostream>
#include<vector>
#include<iterator>
#include "projmap.h"

using namespace std;

template <class T>
class Set
{
  public:
    Set ();  // constructor for a new empty set
	
	Set (const Set<T> &other);

    ~Set (); // destructor

    int sizeset () const; // returns the number of elements in the set

    void add (T item); 
      /* Adds the item to the set.
         If the item is already in the set, it should do nothing.
      */
	Set<T> & operator= (const Set<T> &other);
	//const T & getCurrent();
	/*T getCurrent();
	void next();
	void first();*/

	Set<T> setUnion(const Set<T> & other) const;

	Set<T> setIntersection(const Set<T> & other) const;
	
	Map<T, int> getIS() const;

    void remove (const T &item);
     /* Removes the item from the set.
        If the item was not in the set, it should do nothing. */

    bool contains (const T &item) const;
     /* Returns whether the item is in the set. */
    void merge (const Set<T> & other);
     /* Adds all elements of other to this set. 
        However, will not create duplicates, i.e., it ignores elements
        already in the set. */
	class Iterator {
         /* add any constructors that you feel will be helpful,
            and choose whether to make them public or private. */
		 private:
			
			const Set<T> *whoIBelongTo;
			//T curr;
			Iterator(const Set<T> *m){
				whoIBelongTo = m; 
			} ;
			class Map<T, T>::Iterator it;
         public:
			friend class Set<T>;
			Iterator(class Map<T, T>::Iterator mapit): it(mapit){ 
			}
			Iterator(){ }
			~Iterator(){ }
           T operator* () const{
				return ((*it).first);
			}
              // return the item the iterator is at

           Set<T>::Iterator operator++ (){
				++it;
				return *this;
			}
              // advances the iterator (pre-increment)

           Set<T>::Iterator operator= (const Set<T>::Iterator & other){
				this->it = other.it;
				return *this;
			}
              // assigns the other iterator to this iterator and returns this

           bool operator== (const Set<T>::Iterator & other) const{
				return (it == other.it && whoIBelongTo == other.whoIBelongTo);
			}
              // returns whether this iterator is equal to the other iterator

           bool operator!= (const Set<T>::Iterator & other) const{
				return (!this->it.operator==(other.it));
			}
              // returns whether this iterator is not equal to the other iterator

           /* Optionally, if you think that it makes your code easier to write,
              you may also overload other operators: */
     };

     Set<T>::Iterator begin () const{
			Set<T>::Iterator setbegin(internalStorage.begin());
			return setbegin;
	}
       // returns an iterator initialized to the first element

     Set<T>::Iterator end () const{
			Set<T>::Iterator setend(internalStorage.end());
			return setend;
	}
       /* returns an iterator initialized past the last element,
          to designate that the end of the map has been reached. */
  private:
    Map<T, T> internalStorage;
	
     

     /* If you like, you can add further data fields and private
        helper methods. */
};

#include "projsetImpl.h"
#endif
