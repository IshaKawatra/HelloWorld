#include<iomanip>
//#include<Qtgui>

#include <exception>
#include<iostream>
#include "newuserwindow.h"

NewUserWindow::NewUserWindow(Netflix *n){
	 this->n = n;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Please enter an ID you'd like to use. "));
     login = new QLineEdit;
	 name = new QLineEdit;
     QFormLayout *fl = new QFormLayout;
     fl->addRow("Login: ", login);
	 fl->addRow("Name: ", name);
     mainLayout->addLayout(fl);
     
     confirmButton = new QPushButton ("&Confirm"); //the ampersand means that alt-Q will work
	 cancelButton = new QPushButton("&Cancel");
     buttonLayout->addWidget(confirmButton);
	 buttonLayout->addWidget(cancelButton);
     connect(confirmButton,SIGNAL(clicked()),this,SLOT(confirmPressed()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelPressed()));
     
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}

void NewUserWindow::confirmPressed(){
    std:: string loginName = login->text().toStdString();
    std:: string nameName = name->text().toStdString();
	try{
		n->AllUsers->at(loginName); //try to find ID in user map
		ErrorWindow *e = new ErrorWindow;
		e->show();
			
	}
	catch(NoSuchElementException &r){ 
			std::cout << "ID creation successful! " << std::endl;
			User *newUser = new User(loginName, nameName);
			//n->AllUsers->add(loginName, newUser);
			n->AllUsers->insert( std::pair<string,User*>(loginName,newUser) );
			cout << "did i get here?" << endl;
			n->setID(loginName);
			SearchWindow *l = new SearchWindow(n);
			cout << "wooootttttt" << endl;
			l->show();
			close();
		}

}


void NewUserWindow::cancelPressed(){
    std::cout << "cancel was pressed" << std::endl;
    close();
}


/*void NewUserWindow::closeEvent(QCloseEvent *event){
          std:: cout << "Bye bye" << std::endl;
          event->accept();
}*/
