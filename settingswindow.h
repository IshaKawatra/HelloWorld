#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
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
#include "addresswindow.h"
#include "ccnumwindow.h"
#include<sstream>
#include "passwordwindow.h"



using namespace std;
class SettingsWindow : public QWidget{
          Q_OBJECT
          public:
          SettingsWindow(Netflix *n); //constructor
		 
	
         public slots: //slots
         void addressPressed();
         void ccnumPressed();
		  void passwordPressed();
		void quitPressed();
         

          private:
          QPushButton *changeAddressButton; //buttons
		  QPushButton *changeccnumButton;
		  QPushButton *changePasswordButton;
		  QPushButton *quitButton;
		  QLabel *ccnumtitle;
		  QLabel *addresstitle;
			
		  Netflix *n;
		
};
#endif

