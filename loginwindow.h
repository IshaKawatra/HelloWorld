#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
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
class LoginWindow : public QWidget{
          Q_OBJECT
          public:
          LoginWindow(Netflix *n); //constructor
		 
	
         public slots: //slots
         void loginPressed();
         void quitPressed();
		  void newuserPressed();
         

          private:
          QPushButton *quitButton; //buttons
		  QPushButton *loginButton;
		  QPushButton *newuserButton;
          QLineEdit *login;
		  QLineEdit *password;
		  Netflix *n;
		
};
#endif

