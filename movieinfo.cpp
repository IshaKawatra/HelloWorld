#include<iomanip>
//#include<Qtgui>
#include "movie.h"
#include <exception>
#include<iostream>
#include "movieinfo.h"

MovieInfoWindow::MovieInfoWindow(Movie *m){
	 this->m = m;
	 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 mainLayout->addWidget(new QLabel ("Please enter an ID you'd like to use. "));
     string temptitle = m->getTitle();
	 cout << "title is " << temptitle << endl;
     QString temptitle2 = QString::fromStdString(temptitle);
	  QLabel *movietitle = new QLabel(temptitle2);
		mainLayout->addWidget(movietitle);
		for (set<string>::iterator foundit = m->getAllKeywords().begin(); foundit != m->getAllKeywords().end(); ++foundit){
			string keyword = (*foundit);
			QString keyword2 = QString::fromStdString(keyword); //tried a for loop to display keywords..didn't work.
			QLabel *keywordlabel = new QLabel(keyword2);
			mainLayout->addWidget(keywordlabel);
		}
     closeButton = new QPushButton ("&Close"); //the ampersand means that alt-Q will work
	 buttonLayout->addWidget(closeButton);
     connect(closeButton,SIGNAL(clicked()),this,SLOT(closePressed())); //one button functioanlity
     
     mainLayout->addLayout(buttonLayout); //nesting layouts
     setLayout(mainLayout);

}

void MovieInfoWindow::closePressed(){
    close();

}

