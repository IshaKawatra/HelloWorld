#include <iostream>
#include "user.h"
//#include "queue.h"
//#include "movie.h"
//#include "./lib/projset.h"
//#include "./lib/projmap.h"
using namespace std;
	
	User::User(){ };

   	User::User(string ID, string name){
		this->ID = ID;
		this->name = name;
		this->rental = NULL;
		//Queue<Movie*> *userQueue = new Queue<Movie*>;
		//userQueue = NULL;
	}  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User::User(const User & other){
		this->name = other.name;
		this->ID = other.ID;
	} // copy constructor

    User::~User(){ 
		}          // destructor

    string User::getID () const{
		return this->ID;    // returns the ID associated with this user
	}

    string User::getName () const{
		return this->name;
	}  // returns the name associated with this user

	queue<Movie*> * User::movieQueue (){
		return &userQueue;
	}
      /* returns a pointer to the user's movie queue.
         This is the easiest way to ensure that you can modify the queue.
         (If you return by reference, that's also possible, but you'd need
         to be very careful not to invoke any deep copy constructors or
         assignments. A pointer is thus safer.) */

    void User::rentMovie (Movie *m){
		if(rental==NULL && rentalhelper == ""){
			rental = m;
		}	
		else{
			//cout << "User already has a movie rented. " << endl;
		}
	}
      /* sets the user's currently rented movie to m.
         If the user already has a movie checked out, then it does nothing.
         (So no overwriting the current movie.) */

	map<Movie*, int>* User::returnRatings(){
		return &ratings;
	}


    Movie* User::currentMovie (){
		if(rental == NULL){
			return NULL;
		}
		else{
			return rental;
		}
	}
      /* returns the user's current checked out movie.
         Returns NULL if the user has no movie checked out. */


void User::setCharges(int charges){
	this->totalcharges = charges;
}

	void User::setAddress(string address){
	this->address = address;
}

	void User::setccnum(int ccnum){
	this->ccnum = ccnum;
}
	void User::setPassword(string password){
	this->password = password;
	}

	string User::returnPassword(){
		return password;
	}
	
	int User::returnCharges(){
		return totalcharges;
}
	//returns user's total current charges

	string User::returnAddress(){
	return address;
}
	//returns user's current address

	int User::returnccnum(){
	return ccnum;
}
	//returns map of user's credit card numbers and charges on each one
  

