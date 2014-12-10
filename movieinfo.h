#ifndef MOVIEINFO_H
#define MOVIEINFO_H
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
#include "movie.h"
#include<QFormLayout>
#include "searchwindow.h"




using namespace std;
class MovieInfoWindow : public QWidget{
          Q_OBJECT
          public:
          MovieInfoWindow(Movie* m); //constructor
		 
	
         public slots:
         void closePressed(); //slots
         

          private:
          QPushButton *closeButton; //button
		  Movie *m; //current movie
		
};
#endif

