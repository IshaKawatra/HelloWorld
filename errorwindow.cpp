#include<iomanip>
//#include<Qtgui>

#include <exception>
#include<iostream>
#include "errorwindow.h"

ErrorWindow::ErrorWindow(){
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
	 mainLayout->addWidget(new QLabel ("ERROR: Please enter a different login ID."));
     tryagainButton = new QPushButton ("&Try Again"); //the ampersand means that alt-Q will work
     mainLayout->addWidget(tryagainButton);
     connect(tryagainButton,SIGNAL(clicked()),this,SLOT(tryagainPressed()));
     setLayout(mainLayout);

}

void ErrorWindow::tryagainPressed(){
	close();

}


