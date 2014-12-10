#include<iostream>
#include<QLineEdit>
#include<iterator>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include <QPushButton>
#include<QLabel>
#include<iostream>
#include<QString>
#include<iterator>
#include <exception>

#include <QCloseEvent>
#include<QFormLayout>
//#include<Qtgui>
#include "searchresults.h"
#include "movieinfo.h"

using namespace std;
SearchResults::SearchResults(std::string searched, Netflix *n) {
	 this->n = n;
	 viewed = new Movie("");
	 foundmovies = new set<Movie*>; //initialize private variables
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
     QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
	 mainLayout->addWidget(new QLabel ("First movie found with searched term"));     
	//connect first movie in queue here
	map<string, Movie*>::iterator it = n->AllMovies->find(searched);
	if(it!=n->AllMovies->end()){
		Movie *temp = n->AllMovies->find(searched)->second;
		std::string temptitle = temp->getTitle();
		QString temptitle2 = QString::fromStdString(temptitle);
		firstfound = new QLabel(temptitle2); //view first  movie
	    mainLayout->addWidget(firstfound);
		foundmovies->insert(temp);
		foundit = foundmovies->begin(); 
		viewed = (*foundit);
		
	}
	else{
		set<Movie*>* keyMovies = new set<Movie*>;
		map<string, set<Movie*> >::iterator it = n->KeyLookUp->find(searched);
		if(it!=n->KeyLookUp->end()){
			*keyMovies = n->KeyLookUp->find(searched)->second; //create set of movie pointers related to that keyword
			set<Movie*>::iterator samplemovie = keyMovies->begin();
			movieinfoButton = new QPushButton("&Movie Info");
		 	connect(movieinfoButton,SIGNAL(clicked()),this,SLOT(movieinfobuttonPressed())); //to view the information of that specific movie --> note: DOES NOT WORK
			string sampletitle = (*samplemovie)->getTitle();
			QString sampletitle2 = QString::fromStdString(sampletitle);
			firstfound = new QLabel(sampletitle2);
			mainLayout->addWidget(firstfound);
			for(samplemovie = keyMovies->begin(); samplemovie != keyMovies->end(); ++samplemovie){
				Movie *newmovie = *samplemovie;
				foundmovies->insert(newmovie); //add movies to set of relevant movies
			} 
			foundit = foundmovies->begin();
			viewed = (*foundit);
		}
		else{
			mainLayout->addWidget(new QLabel ("No such movie found!"));
		}	
	}
	movieinfoButton = new QPushButton("&Movie Info");
     	connect(movieinfoButton,SIGNAL(clicked()),this,SLOT(movieinfoPressed()));
	nextmovieButton = new QPushButton ("&Next Movie"); //the ampersand means that alt-Q will work
     addmovieButton = new QPushButton("&Add to my Queue");
	 backButton = new QPushButton("&Return to Main Menu");
	 buttonLayout->addWidget(movieinfoButton);
     buttonLayout->addWidget(nextmovieButton);
     buttonLayout->addWidget(addmovieButton);
	 buttonLayout->addWidget(backButton);
     connect(nextmovieButton,SIGNAL(clicked()),this,SLOT(nextmoviePressed())); //connect functionalities to events
    connect(addmovieButton, SIGNAL(clicked()), this, SLOT(addmoviePressed()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(backPressed()));
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}

void SearchResults::movieinfoPressed(){
	MovieInfoWindow *i = new MovieInfoWindow(viewed);
	i->show(); //display movie information
}


//add functions here!!!
void SearchResults::nextmoviePressed(){
	cout << "got here " << endl;
    try{
			++foundit; //increment iterator
			cout << "title is " << (*foundit)->getTitle();
		}
	catch(NoSuchElementException &s){
		std::cout<<"error";
	}
	QString firstfound2 = QString::fromStdString((*foundit)->getTitle()); //is a string, convert to QLabel
	firstfound->setText(firstfound2); //update screen
}
void SearchResults::addmoviePressed(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			User *newUser = n->AllUsers->find(n->returnID())->second;
			newUser->movieQueue()->push(*foundit); //add movie to queue
		}
		else{
			cout << "add movie error" << endl;
		}
    
}

void SearchResults::backPressed(){
	//SearchWindow *d = new SearchWindow(n);
   // d->show();    //show new, updated search screen
	close();
}

//void createuserPressed()

void SearchResults::closeEvent(QCloseEvent *event){
			emit dialogClosed(); //emit signal
          std:: cout << "Bye bye" << std::endl;
          event->accept();
}
