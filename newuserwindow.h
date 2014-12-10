#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H
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
#include "errorwindow.h"

class NewUserWindow : public QWidget{
          Q_OBJECT
		  
          public:
          NewUserWindow(Netflix *n);

          public slots:
          void confirmPressed();
          void cancelPressed();
         

          private:
          QPushButton *confirmButton;
		  QPushButton *cancelButton;
          QLineEdit *login;
		  QLineEdit *name;
		  Netflix *n; 
};
#endif
