#ifndef VIEWRATINGSWINDOW_H
#define VIEWRATINGSWINDOW_H
#include "netflix.h"
//#include "netflix.cpp"
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<iostream>
#include<QObject>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QApplication>
#include<QLabel>
#include<iostream>
#include<QString>
#include <QCloseEvent>

#include<QFormLayout>

//#include "searchwindow.h"
//#include "newuserwindow.h"
//#include "errorwindow.h"
#include "modratewindow.h"

#include "movie.h"
#include "user.h"


using namespace std;
class ViewRatingsWindow : public QWidget{
          Q_OBJECT
          public:
          ViewRatingsWindow(Netflix *n); //constructor
		 
	
         public slots: //slots
         void modPressed();
         void quitPressed();
		 
         

          private:
          QPushButton *modButton; //buttons
		  QPushButton *quitButton;
		  Netflix *n;

		
};
#endif

