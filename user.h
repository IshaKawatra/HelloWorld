#ifndef USER_H
#define USER_H
#include <iostream>
#include "movie.h"
//#include "./lib/queue.h"
#include<queue>
#include<map>
//#include "userImpl.h"
//#include "userImpl.h"

using namespace std;
class User {
  public:

	User();
	string ID;
	string name;
	string rentalhelper;

    User (string ID, string name);  
    /* constructor that generates a user with the given name and ID.
       While multiple users may have the same name, the ID should be unique
       (e.g., an e-mail address), so that users can log in with it. */

    User (const User & other); // copy constructor

    ~User ();            // destructor

    string getID () const;    // returns the ID associated with this user

    string getName () const;  // returns the name associated with this user
	
	queue<Movie*> * movieQueue (); 
      /* returns a pointer to the user's movie queue.
         This is the easiest way to ensure that you can modify the queue.
         (If you return by reference, that's also possible, but you'd need
         to be very careful not to invoke any deep copy constructors or
         assignments. A pointer is thus safer.) */
	map<Movie*, int>* returnRatings();
	//returns map of ratings

    void rentMovie (Movie *m);
      /* sets the user's currently rented movie to m.
         If the user already has a movie checked out, then it does nothing.
         (So no overwriting the current movie.) */

    Movie* currentMovie ();
      /* returns the user's current checked out movie.
         Returns NULL if the user has no movie checked out. */

	void setCharges(int charges);
	void setAddress(string address);
	void setccnum(int ccnum);
	void setPassword(string password);
	
	int returnCharges();
	//returns user's total current charges

	string returnAddress();
	//returns user's current address

	string returnPassword();
	int returnccnum();
	//returns map of user's credit card numbers and charges on each one
	
  private:
    queue<Movie*> userQueue;
	Movie* rental;
	map<Movie*, int> ratings;
	string password;
	string address;
	int ccnum;
	int totalcharges;
	
};

#endif
