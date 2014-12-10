#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H
#include "movie.h"
#include "user.h"
#include "netflix.h"
#include<iostream>
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
#include <QtGui> 
#include "modratewindow.h"
#include "ratewindow.h"
#include "searchresults.h"
#include "viewratingswindow.h"
#include "chargewindow.h"
#include "settingswindow.h"

using namespace std;

class SearchWindow : public QWidget{
          Q_OBJECT
          public:
          SearchWindow(Netflix *n); //constructor

          public slots:
		  void rentmoviePressed();
		  void movemoviePressed();//slots
		  void deletemoviePressed();
          void searchtitlePressed();
          void searchkeyPressed();
		  void returnmoviePressed();
		  void viewratingsPressed();
		void logoutPressed();
		void updateRentedMovie();
		void updateQueueMovie();
		void settingsPressed();
		  
         
		signals: //signals
		void dialogClosed();

          private:
          QPushButton *searchtitleButton;
		  QPushButton *searchkeyButton;   //buttons
		  QPushButton *returnmovieButton;
		  QPushButton *movemovieButton;
          QPushButton *logoutButton;
		  QPushButton *deletemovieButton;
		  QPushButton *rentmovieButton;
		  QPushButton *viewratingsButton;
		  QPushButton *settingsButton;
          QLineEdit *searched;
			Netflix *n;
	      QLabel *rentaltitle; //which movie is rented
		  QLabel *frontqueue; //which movie is at front of queue
};

#endif
