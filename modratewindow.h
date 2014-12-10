#ifndef MODRATEWINDOW_H
#define MODRATEWINDOW_H
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
#include "searchwindow.h"
#include "newuserwindow.h"
#include "ratewindow.h"
#include "errorwindow.h"



using namespace std;
class ModRateWindow : public QWidget{
          Q_OBJECT
          public:
          ModRateWindow(Movie* trytofind, Netflix *n); //constructor
		 
	
         public slots: //slots
         void modPressed();
         void quitPressed();
		 
         

          private:
          QPushButton *modButton; //buttons
		  QPushButton *quitButton;
          QLineEdit *rating;
		  Netflix *n;
		  Movie *trytofind;
		
};
#endif

