#include<iostream>
#include "viewratingswindow.h"
#include<sstream>
using namespace std;
ViewRatingsWindow::ViewRatingsWindow( Netflix *n){
	this->n = n; //initialize netflix class
	//this->trytofind = trytofind;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Your Ratings"));
	 map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
	if(it!=n->AllUsers->end()){
		 for (map<Movie*, int>::iterator rat = (*it).second->returnRatings()->begin(); rat!= (*it).second->returnRatings()->end(); ++rat){
			string movietitle = (*rat).first->getTitle();
			QString ratedtitle2 = QString::fromStdString(movietitle); //to display current queue title
		
			QLabel *ratedtitle = new QLabel(ratedtitle2);
			QHBoxLayout *ratingsLayout = new QHBoxLayout;
			ratingsLayout->addWidget(ratedtitle);
			stringstream ss;
			ss << (*rat).second;
			string str = ss.str();
			//string s = string(itoa((*rat).second));
			QString rating2 = QString::fromStdString(str);
			QLabel *rating = new QLabel(rating2);
			ratingsLayout->addWidget(rating);
			mainLayout->addLayout(ratingsLayout);
		}
	}
	else{
		cout << "no ratings" << endl;
	}
	
     modButton = new QPushButton ("&Modify Ratings"); //the ampersand means that alt-Q will work
	 quitButton = new QPushButton("&I want to keep this rating");
     
     connect(modButton,SIGNAL(clicked()),this,SLOT(modPressed())); //connect functionalities to events
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
 
     buttonLayout->addWidget(modButton);
	 buttonLayout->addWidget(quitButton);

     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void ViewRatingsWindow::modPressed(){
	//RateWindow *r = new RateWindow(temp, n);
    //r->show();
	close();
}

void ViewRatingsWindow::quitPressed(){
    std::cout << "cancel was pressed" << std::endl;
    close();
}

