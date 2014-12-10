#include<iostream>
#include "chargewindow.h"
#include<sstream>
using namespace std;
ChargeWindow::ChargeWindow( Netflix *n){
	this->n = n; //initialize netflix class
	//this->trytofind = trytofind;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("This rental costs "));
	 map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
	if(it!=n->AllUsers->end()){
		 map<string, Movie*>::iterator it2 = n->AllMovies->find((*it).second->rentalhelper);
				if(it2!=n->AllMovies->end()){
				Movie *temp = n->AllMovies->find((*it).second->rentalhelper)->second;
				 int price = temp->price;
				stringstream ss;
				ss << price;
				string str = ss.str();
				 QString tempprice = QString::fromStdString(str);
				QLabel *rentalprice = new QLabel(tempprice); //to display current title
				mainLayout->addWidget(rentalprice);
				 mainLayout->addWidget(new QLabel ("This charge will be added to your total charges on your card. Your total charges are now: "));
				 int charges = (*it).second->returnCharges();
				stringstream s1;
				s1 << charges;
				string str1 = s1.str();
				 QString tempcharges = QString::fromStdString(str1);
				QLabel *newcharges = new QLabel(tempcharges); //to display current title
				mainLayout->addWidget(newcharges);
				
		}
	}
	else{
		cout << "no ratings" << endl;
	}
	
     okButton = new QPushButton ("&Okay"); //the ampersand means that alt-Q will work
     
     connect(okButton,SIGNAL(clicked()),this,SLOT(okPressed())); //connect functionalities to events
 
     buttonLayout->addWidget(okButton);

     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}



void ChargeWindow::okPressed(){
    std::cout << "cancel was pressed" << std::endl;
    close();
}

