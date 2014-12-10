#ifndef RATEWINDOW_H
#define RATEWINDOW_H
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





using namespace std;
class RateWindow : public QWidget{
          Q_OBJECT
          public:
          RateWindow(Movie* trytofind, Netflix *n); //constructor
		 
	
         public slots: //slots
         void ratePressed();
         void quitPressed();
		 
         

          private:
          QPushButton *rateButton; //buttons
		  QPushButton *quitButton;
          QLineEdit *rating;
		  Netflix *n;
		  Movie *trytofind;
		
};
#endif

