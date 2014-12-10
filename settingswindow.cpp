#include "settingswindow.h"

SettingsWindow::SettingsWindow(Netflix *n){
	this->n = n; //initialize netflix class
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Settings"));

     User *newUser = n->AllUsers->find(n->returnID())->second;

	mainLayout->addWidget(new QLabel ("Current Address: "));
		string address = newUser->returnAddress();
		 QString address2 = QString::fromStdString(address);

		addresstitle = new QLabel(address2); //to display current title
		mainLayout->addWidget(addresstitle); 
	mainLayout->addWidget(new QLabel ("-----------------------"));

		mainLayout->addWidget(new QLabel ("Current Credit Card Number: "));

		int cc = newUser->returnccnum();

		stringstream ss;
		ss << cc;
		string ccnum = ss.str();
		//string ccnum = newUser->returnccnum();
		 QString ccnum2 = QString::fromStdString(ccnum);
		ccnumtitle = new QLabel(ccnum2); //to display current title
		mainLayout->addWidget(ccnumtitle); 
	mainLayout->addWidget(new QLabel ("-----------------------"));

     changeAddressButton = new QPushButton ("Change Address"); //the ampersand means that alt-Q will work
	 changeccnumButton = new QPushButton("&Change Credit Card Number");
     changePasswordButton = new QPushButton("&Change Password");
	quitButton = new QPushButton("Quit");
     
     connect(changeAddressButton,SIGNAL(clicked()),this,SLOT(addressPressed())); //connect functionalities to events
  connect(changeccnumButton, SIGNAL(clicked()), this, SLOT(ccnumPressed()));
   connect(changePasswordButton, SIGNAL(clicked()), this, SLOT(passwordPressed()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quitPressed()));
     buttonLayout->addWidget(changeAddressButton);
	 buttonLayout->addWidget(changeccnumButton);
     buttonLayout->addWidget(changePasswordButton);
	buttonLayout->addWidget(quitButton);
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}


void SettingsWindow::addressPressed(){
	AddressWindow *a = new AddressWindow(n);
	a->show();
    //open a change address window
}

void SettingsWindow::ccnumPressed(){
	CcnumWindow *c = new CcnumWindow(n);
	c->show();
    //open a change ccnum window
}

void SettingsWindow::passwordPressed(){
	PasswordWindow *p = new PasswordWindow(n);
	p->show();
    //open a change password window
}

void SettingsWindow::quitPressed(){
    close();
}



