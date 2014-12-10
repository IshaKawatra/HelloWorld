#include<iomanip>
//#include<Qtgui>

#include <exception>
#include<iostream>
#include "searchwindow.h"




using namespace std;
SearchWindow::SearchWindow(Netflix *n) {
	this->n = n;
     QHBoxLayout *buttonLayout = new QHBoxLayout; //the H means horizontal!!
	 map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			 User *newUser = n->AllUsers->find(n->returnID())->second;
		
			 QVBoxLayout *mainLayout = new QVBoxLayout; //the V means vertical
			mainLayout->addWidget(new QLabel ("Your Current Movie"));
			try{
				 cout << "this user's movie is " << newUser->rentalhelper << " end" <<endl;
				map<string, Movie*>::iterator it2 = n->AllMovies->find(newUser->rentalhelper);
				if(it2!=n->AllMovies->end()){
				Movie *temp = n->AllMovies->find(newUser->rentalhelper)->second;
				 string temptitle = temp->getTitle();
				 QString temptitle2 = QString::fromStdString(temptitle);
				rentaltitle = new QLabel(temptitle2); //to display current title
				mainLayout->addWidget(rentaltitle); 
				}	
				else{
					cout << "didn't find it" << endl;
				} 
			}
			catch(NoSuchElementException &i){
				mainLayout->addWidget(new QLabel("No movie rented."));
			}  
			returnmovieButton = new QPushButton ("&Return Current Movie"); //the ampersand means that alt-Q will work
			mainLayout->addWidget(returnmovieButton);
			connect(returnmovieButton,SIGNAL(clicked()),this,SLOT(returnmoviePressed()));	
			mainLayout->addWidget(new QLabel ("Your Movie Queue"));
			if(!newUser->movieQueue()->empty()){  
				string queuetitle = newUser->movieQueue()->front()->getTitle();
				QString queuetitle2 = QString::fromStdString(queuetitle); //to display current queue title
				frontqueue = new QLabel(queuetitle2);
				mainLayout->addWidget(frontqueue);	
			}
			else{
				mainLayout->addWidget(new QLabel("No movies in queue."));
			}
			rentmovieButton = new QPushButton("&Rent Movie");
			deletemovieButton = new QPushButton("&Delete Movie from Queue");
			movemovieButton = new QPushButton("&Move Movie to Back");
			 buttonLayout->addWidget(rentmovieButton);
			 buttonLayout->addWidget(deletemovieButton);
			 buttonLayout->addWidget(movemovieButton);
			 connect(rentmovieButton,SIGNAL(clicked()),this,SLOT(rentmoviePressed())); //connecting functionality to events
			connect(deletemovieButton, SIGNAL(clicked()), this, SLOT(deletemoviePressed()));
			connect(movemovieButton, SIGNAL(clicked()), this, SLOT(movemoviePressed()));
			 mainLayout->addLayout(buttonLayout); //nesting layouts
			 searched = new QLineEdit;
			searchtitleButton = new QPushButton("&Search by Title");
			searchkeyButton = new QPushButton("&Search by Keyword");
			viewratingsButton = new QPushButton("View All My Ratings");
			settingsButton = new QPushButton("Settings");

			QHBoxLayout *secondbuttonLayout = new QHBoxLayout; //the H means horizontal!!
			secondbuttonLayout->addWidget(searchtitleButton);
			secondbuttonLayout->addWidget(searchkeyButton);
			secondbuttonLayout->addWidget(viewratingsButton);
			secondbuttonLayout->addWidget(settingsButton);
	
			connect(searchtitleButton,SIGNAL(clicked()),this,SLOT(searchtitlePressed()));
			connect(searchkeyButton, SIGNAL(clicked()), this, SLOT(searchkeyPressed()));
			connect(viewratingsButton, SIGNAL(clicked()), this, SLOT(viewratingsPressed()));
			connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsPressed()));
			 QFormLayout *fl = new QFormLayout;
			 fl->addRow("Search: ", searched); //search box
			 mainLayout->addLayout(fl);
			 mainLayout->addLayout(secondbuttonLayout);
			logoutButton = new QPushButton("&Logout");
			connect(logoutButton, SIGNAL(clicked()), this, SLOT(logoutPressed()));	
			mainLayout->addWidget(logoutButton);
			 setLayout(mainLayout);
			show();
		}
	else{
		cout << "couldn't find user" << endl;
	}

}

void SearchWindow::settingsPressed(){
	SettingsWindow *q = new SettingsWindow(n);
	q->show();
	//close();
	//open a settings window here
}



void SearchWindow::logoutPressed(){
	delete n;
	close();
	//hide();
}


void SearchWindow::updateRentedMovie(){ 
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
	if(it!=n->AllUsers->end()){
		User *newUser = n->AllUsers->find(n->returnID())->second;
		cout << "1" << endl;
		QString rentaltitle2 = QString::fromStdString(newUser->rentalhelper); //is a string, convert to QLabel
		cout << "2" << endl;
		//cout << "rental helper is " << newUser->rentalhelper << endl;
		rentaltitle->setText(rentaltitle2);
		cout << "3" << endl;
	}
	else{
		cout << "update rented movie error"<<endl;
	}
}

void SearchWindow::updateQueueMovie(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
	if(it!=n->AllUsers->end()){
			User *newUser = n->AllUsers->find(n->returnID())->second;
			if(!newUser->movieQueue()->empty()){
			QString queuetitle2 = QString::fromStdString(newUser->movieQueue()->front()->getTitle()); //is a string, convert to QLabel
			frontqueue->setText(queuetitle2);
			}
			else{
			QString queuetitle3 = QString::fromStdString("");
			frontqueue->setText(queuetitle3);
		}
	}
	else{
		cout << "error" << endl;
	}
	
}

void SearchWindow::returnmoviePressed(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			 User *newUser = n->AllUsers->find(n->returnID())->second;
			if(newUser->rentalhelper!=""){
					Movie* temp = n->AllMovies->find(newUser->rentalhelper)->second;
						map<Movie*, int>::iterator it = newUser->returnRatings()->find(temp);
						if(it!=newUser->returnRatings()->end()){
							int t;
							t=newUser->returnRatings()->find(temp)->second;
							ModRateWindow *m = new ModRateWindow(temp, n);
							m->show();
						}
						else{
							RateWindow *r = new RateWindow(temp, n);
							r->show();
						}
						//cout << "this movie already has a rating" << endl;			
			}
			else{
				cout << "No movie rented. " << endl << endl;
			}
		newUser->rentMovie(NULL);
		newUser->rentalhelper = "";
		cout << "Movie rental is returned! " << endl << endl;
		updateRentedMovie(); //update the screen
		}
		else{
			cout << "return movie error" << endl;
		}
}
void SearchWindow::rentmoviePressed(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
	if(it!=n->AllUsers->end()){
		User *newUser = n->AllUsers->find(n->returnID())->second; //find appropriate logged in user
		if(!newUser->movieQueue()->empty()){
			Movie* firstmovie = newUser->movieQueue()->front();
			int newcharges = newUser->returnCharges() + firstmovie->price; //update charges
			newUser->setCharges(newcharges);	
			newUser->rentMovie(firstmovie);
			newUser->rentalhelper=firstmovie->getTitle();
			newUser->movieQueue()->pop();
			cout << "Movie was rented!" << endl;
			updateRentedMovie(); //update the screen
			cout << "updated rented movie" << endl;
			updateQueueMovie();
			cout << "updated queue" << endl;
			ChargeWindow *c = new ChargeWindow(n);
			c->show();
		}
		else{
			cout << "nothing in queue" << endl;
		}
	}
	else{
		cout << "rent movie error" << endl;
	}
}

void SearchWindow::deletemoviePressed(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			User *newUser = n->AllUsers->find(n->returnID())->second;
			if(!newUser->movieQueue()->empty()){
				 newUser->movieQueue()->pop();
				 cout << "Movie was deleted!" << endl;
				 updateQueueMovie(); //update screen
			}
			else{
				cout << "empty queue" << endl;
			}
		}
		else{
			cout << "delete movie error" << endl;
		}
}

void SearchWindow::movemoviePressed(){
	map<string, User*>::iterator it = n->AllUsers->find(n->returnID());
		if(it!=n->AllUsers->end()){
			 User *newUser = n->AllUsers->find(n->returnID())->second;
			Movie* firstmovie = newUser->movieQueue()->front();	
			newUser->movieQueue()->push(firstmovie);
			newUser->movieQueue()->pop();
			cout << "movie was moved to back!" << endl;
			updateQueueMovie(); //update screen
		}
		else{
			cout << "move movie error" <<endl;
		}
}
void SearchWindow::searchtitlePressed(){
    std:: string searched2 = searched->text().toStdString();
	//close();
	//hide();
    SearchResults *s = new SearchResults(searched2, n);
    s->show();
	connect(s,SIGNAL(dialogClosed()),this,SLOT(updateQueueMovie())); //adds movies to queue from child window above
}
void SearchWindow::searchkeyPressed(){
    std:: string searched2 = searched->text().toStdString();
	//close();
	//hide();
    SearchResults *s = new SearchResults(searched2, n);
    s->show();
	connect(s,SIGNAL(dialogClosed()),this,SLOT(updateQueueMovie()));
}

void SearchWindow::viewratingsPressed(){
	ViewRatingsWindow *v = new ViewRatingsWindow(n);
	v->show();
	}


