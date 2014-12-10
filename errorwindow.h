#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H
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




using namespace std;
class ErrorWindow : public QWidget{
          Q_OBJECT
          public:
          ErrorWindow();
		 
	
         public slots:
         void tryagainPressed();
         

          private:
          QPushButton *tryagainButton;
		
};
#endif

