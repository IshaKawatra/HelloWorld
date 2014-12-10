#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
//#include "lib/projset.h"
#include<set>
//#include "lib/projset.cpp"
//#include "lib/projmapImpl.h"
//#include "movieImpl.h"


using namespace std;

class Movie {
  public: 

	string title;
	int price;
	set <string> keywords;
	
    Movie (string title);       // constructor for a movie with the given title

    Movie (const Movie & other);  // copy constructor

    ~Movie ();                  // destructor

    string getTitle () const;   // returns the title of the movie

    void addKeyword (string keyword); 
      /* Adds the (free-form) keyword to this movie.
         If the exact same keyword (up to capitalization) was already
         associated with the movie, then the keyword is not added again. */

	void setPrice(int price);


    set<string> getAllKeywords () const;
      /* Returns a set of all keywords associated with the movie. */

  private:
	 // you get to decide what goes here
};


#endif
