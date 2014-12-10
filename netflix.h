#ifndef NETFLIX_H
#define NETFLIX_H
#include<sstream>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <cstring>
#include <cctype>
#include <string>
#include "user.h"
#include<map>
#include<set>
#include "nosuch.h"
#include "md5.h"

using namespace std;
class Netflix {

	public:
	   map<string, User*> *AllUsers; // = new Map <string, User*>;
       map<string, Movie*> *AllMovies; //= new Map<string, Movie*>;
       map<string, set<Movie*> > *KeyLookUp; //= new Map<string, Set<Movie*> >;
		Netflix(char*argv[]);
		~Netflix();
		void populate(char* argv[]);
		//void readUsers(string fileofusers);
        //void loginmenu();
		void setID(std::string newID);
		//void readMovies(string fileofmovies);
	    string returnID();
		string converttolower(string input);
		string convertback(string input);
		int findfirstletter(string input, int a);
		//void searchmenu();
		//void searchresults();

   private:
	string loginid;
	string outputfilename;
};





//#include "netflix.cpp"
#endif


