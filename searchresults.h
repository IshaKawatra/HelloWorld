#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H
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
#include<iostream>
#include "user.h"
#include "movie.h"
#include "lib/projset.h"
#include "searchwindow.h"
#include "netflix.h"
#include "movieinfo.h"

using namespace std;
class SearchResults : public QWidget{
          Q_OBJECT
		  friend class SearchWindow; //so that we can call update function
          public:
          SearchResults(std::string searched, Netflix *n);

          public slots: //slots
          void nextmoviePressed();
          void addmoviePressed();
		  void backPressed();
		  void movieinfoPressed();
			void closeEvent(QCloseEvent *event);
         
		  signals:
		  void dialogClosed(); //signals


          private:
          QPushButton *nextmovieButton;
		  QPushButton *addmovieButton; //buttons 
		  QPushButton *backButton;
		  QPushButton *movieinfoButton;
		  Netflix *n;
		  QLabel *firstfound;
		  set<Movie*> *foundmovies; //create set of movies that match search term
		  set<Movie*>::iterator foundit; //to iterate through all found movies
		  Movie *viewed; //keep track of which one is being viewed
};

//#include "searchresults.cpp"
#endif
