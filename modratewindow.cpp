#include<iostream>
#include "modratewindow.h"
#include "ratewindow.h"


ModRateWindow::ModRateWindow(Movie* trytofind, Netflix *n){
	this->n = n; //initialize netflix class
	this->trytofind = trytofind;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Would you like to change your previous rating for this movie?"));

     
     modButton = new QPushButton ("&Modify Rating"); //the ampersand means that alt-Q will work
	 quitButton = new QPushButton("&I want to keep this rating");
     
     connect(modButton,SIGNAL(clicked()),this,SLOT(modPressed())); //connect functionalities to events
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
 
     buttonLayout->addWidget(modButton);
	 buttonLayout->addWidget(quitButton);

     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void ModRateWindow::modPressed(){
	//RateWindow *r = new RateWindow(temp, n);
    //r->show();
	close();
}



void ModRateWindow::quitPressed(){
    close();
}



