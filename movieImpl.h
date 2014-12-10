
#include <iostream>
#include "movie.h"
//#include "lib/projset.h"
//#include "lib/projsetImpl.h"
//#include "lib/projmap.h"
//#include "lib/projset.h"
//#include "lib/projmap.h"
//#include "lib/projset.h"
//#include "lib/projsetImpl.h"
	

using namespace std;
	Movie::Movie (string title){
		this->title = title; // constructor for a movie with the given title
	}

    Movie::Movie (const Movie & other){  // copy constructor
		this->title = other.title;
	}

    Movie::~Movie (){ }                 // destructor ---> DELETE MEMORY!!!

    string Movie::getTitle () const{
		return this->title;
	}   // returns the title of the movie

    void Movie::addKeyword (string keyword){
		keywords.add(keyword); 
      /* Adds the (free-form) keyword to this movie.
         If the exact same keyword (up to capitalization) was already
         associated with the movie, then the keyword is not added again. */
	}

    Set<string> Movie::getAllKeywords () const{
		return keywords;
      /* Returns a set of all keywords associated with the movie. */
	}


