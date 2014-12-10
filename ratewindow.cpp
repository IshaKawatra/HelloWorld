#include<iostream>
#include "ratewindow.h"

RateWindow::RateWindow(Movie* trytofind, Netflix *n){
	this->n = n; //initialize netflix class
	this->trytofind = trytofind;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Please rate this movie from 1 to 5:"));
     rating = new QLineEdit;
     QFormLayout *fl = new QFormLayout;
     fl->addRow("Rating: ", rating); //allow someone to type in their rating
     mainLayout->addLayout(fl);
     
     rateButton = new QPushButton ("&Submit Rating"); //the ampersand means that alt-Q will work
	 quitButton = new QPushButton("&I don't want to rate this movie");
     
     connect(rateButton,SIGNAL(clicked()),this,SLOT(ratePressed())); //connect functionalities to events
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
 
     buttonLayout->addWidget(rateButton);
	 buttonLayout->addWidget(quitButton);

     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void RateWindow::ratePressed(){
    std::string rat = rating->text().toStdString();
	int numb;
	istringstream (rat) >> numb;
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			 User *newUser = n->AllUsers->find(n->returnID())->second;
			//newUser->returnRatings()->add(trytofind, numb);
			newUser->returnRatings()->insert( std::pair<Movie*,int>(trytofind,numb) );
			std::cout<< "movie rating is " << numb << std::endl;
			close();
		}
		else{
			cout << "rate pressed error" << endl;
		}
}



void RateWindow::quitPressed(){
    close();
}



