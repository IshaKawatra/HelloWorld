#include "loginwindow.h"

LoginWindow::LoginWindow(Netflix *n){
	this->n = n; //initialize netflix class
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Welcome to CS104 Flix"));
     login = new QLineEdit; 
	 password = new QLineEdit;
     QFormLayout *fl = new QFormLayout;
     fl->addRow("Login: ", login); //allow someone to type in their login info
	 fl->addRow("Password: ", password);
     mainLayout->addLayout(fl);
     
     quitButton = new QPushButton ("&Quit"); //the ampersand means that alt-Q will work
	 newuserButton = new QPushButton("&Create New User");
     loginButton = new QPushButton("&Login");
     
     connect(loginButton,SIGNAL(clicked()),this,SLOT(loginPressed())); //connect functionalities to events
  connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
   connect(newuserButton, SIGNAL(clicked()), this, SLOT(newuserPressed()));
     buttonLayout->addWidget(loginButton);
	 buttonLayout->addWidget(newuserButton);
     buttonLayout->addWidget(quitButton);
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void LoginWindow::loginPressed(){
    std::string loginName = login->text().toStdString();
	std::string pass = password->text().toStdString();
	map<string, User*>::iterator it = n->AllUsers->find(loginName);
	if(it!=n->AllUsers->end()){
		User *temp = new User;
     	temp = n->AllUsers->find(loginName)->second; //try to find ID in User Map
		cout << "password stored is " << temp->returnPassword() << endl;
		if(temp->returnPassword() == md5(pass)){
				n->setID(loginName);
				close();
			  	SearchWindow *s = new SearchWindow(n); //search window pops up
				s->show();
		}
		else{
			ErrorWindow *f = new ErrorWindow(); //error window pops up
			f->show();
		}
		
	}
	else { 	
		ErrorWindow *l = new ErrorWindow(); //error window pops up
			l->show();
	}
}

void LoginWindow::newuserPressed(){
	close();
   NewUserWindow *u = new NewUserWindow(n); //new user window pops up
    u->show();
}

void LoginWindow::quitPressed(){
    close();
}



