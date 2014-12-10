#ifndef PASSWORDWINDOW_H
#define PASSWORDWINDOW_H
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
#include "errorwindow.h"
#include "md5.h"



using namespace std;
class PasswordWindow : public QWidget{
          Q_OBJECT
          public:
          
		PasswordWindow(Netflix *n); //constructor
		 
	
         public slots: //slots
         void submitPressed();
         void quitPressed();
         

          private:
          QPushButton *submitButton; //buttons
		  QPushButton *quitButton;
			QLineEdit *password;
		  Netflix *n;
		
};
#endif

