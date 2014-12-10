#include "passwordwindow.h"

PasswordWindow::PasswordWindow(Netflix *n){
	this->n = n; //initialize netflix class
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("You have chosen to change your password."));
     password = new QLineEdit; 
     QFormLayout *fl = new QFormLayout;
     fl->addRow("Change to: ", password); //allow someone to type in their login info
     mainLayout->addLayout(fl);
     
     quitButton = new QPushButton ("&Quit"); //the ampersand means that alt-Q will work
	 submitButton = new QPushButton("&Submit");
     
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
   connect(submitButton, SIGNAL(clicked()), this, SLOT(submitPressed()));
     buttonLayout->addWidget(submitButton);
     buttonLayout->addWidget(quitButton);
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void PasswordWindow::submitPressed(){
    std::string submittedpass = password->text().toStdString();
		submittedpass = md5(submittedpass);
		User *temp = new User;
     	temp = n->AllUsers->find(n->returnID())->second; //try to find ID in User Map
		temp->setPassword(submittedpass);
close();
}



void PasswordWindow::quitPressed(){
    close();
}



