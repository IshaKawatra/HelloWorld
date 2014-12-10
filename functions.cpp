/*
void readUsers(string fileofusers){
	ifstream userinput;
	string fileofusers2= "./data/" + fileofusers;
	userinput.open(fileofusers2.c_str());
	if(userinput.fail()){
		cout << "Incorrect user file." << endl;
	}
	else{
	}
	while(!userinput.eof()){
		string firstline, command1;
		getline(userinput, firstline);
		stringstream ss;
		ss << firstline;
		ss >> command1;
		string ID, namecom, fname, lname, title, secondline, nextline, lastline;
		if(command1 == "BEGIN"){
			ss >> ID;
			string command;
			command = "";
			getline(userinput, secondline);
			stringstream s1;
			s1 << secondline;
			s1 >> namecom>> fname >> lname;
			string fullname;
			fullname = fname + " " + lname;
			User *newUser = new User(ID, fullname);
			AllUsers->add(ID, newUser);
			
			bool keepgoing = true;
			while(keepgoing){
				getline(userinput, nextline);
				string command2;
				stringstream s1;
				s1 << nextline;
				s1 >> command2;	
				//cout << "next command is " << command2 << endl;
				if(command2 == "BEGIN"){
					bool flag = true;
					while(flag){
						getline(userinput, lastline); 
						title = "";
						int y = findfirstletter(lastline, 0); //find where keyword begins
						for(int i = y; i < lastline.length(); i++){
								title+=lastline[i];
						}
						if(title == "END QUEUE"){
							flag = false;
						}
						else{
							title = converttolower(title); //convert to lower case for future use
							newUser->movieQueue()->enqueue(AllMovies->get(title));
						}
					}
				}
				else if (command2 == "MOVIE:"){
					string movietitle = "";
					int z = findfirstletter(nextline, 6); //find where title begins
					for(int i = z; i < nextline.length(); i++){
					movietitle+=nextline[i];
					}
					command = "";
					movietitle = converttolower(movietitle); //convert to lowercase for future use
					newUser->rentalhelper = movietitle;
				}
				else if (command2 == "END"){
					keepgoing = false;
				}
				else{
					keepgoing = false;
				}
			
			}//what is this
		}	
	} 
}
	

void readMovies(string fileofmovies){
	ifstream movieinput;
	string fileofmovies2= "./data/" + fileofmovies;
	movieinput.open(fileofmovies2.c_str());
	if(movieinput.fail()){
		cout << "Incorrect movie file name" << endl;
	}
	else{
	}
	
	while(!movieinput.eof()){
		string firstline, command1;
		getline(movieinput, firstline);
		stringstream ss;
		ss << firstline;
		ss >> command1;
		string title, keyword, nextline, lastline;
		if(command1 == "BEGIN"){
			string command;
			title = "";
			int z = findfirstletter(firstline, 6); //find where title begins
			for(int i = z; i < firstline.length(); i++){
				title+=firstline[i];
			}
			command = "";
			title = converttolower(title); //convert to lowercase for future use
			Movie *newMovie = new Movie(title); //create new movie with that title
			AllMovies->add(title, newMovie);
			//cout << "this movie's title is " << newMovie->getTitle() << endl;
			
			bool keepgoing = true;
			while(keepgoing){
				getline(movieinput, nextline);
				string command2;
				stringstream s1;
				s1 << nextline;
				s1 >> command2;
				if(command2 == "KEYWORD:"){
					keyword = "";
					int y = findfirstletter(nextline, 9); //find where keyword begins
					for(int i = y; i < nextline.length(); i++){
							keyword+=nextline[i];
					}
					keyword = converttolower(keyword); //convert to lower case for future use
					newMovie->addKeyword(keyword);
					try{
						KeyLookUp->get(keyword).add(newMovie); //add that movie to the set that corresponds to that keyword
					}
					catch(NoSuchElementException e){
						Set<Movie*> *temp = new Set<Movie*>;
						temp->add(newMovie);
						KeyLookUp->add(keyword, *temp); //add that keyword and movie (to the set of) to keylookup
						delete temp; //deallocate
					}
				}
				else if (command2 == "END"){
					keepgoing = false;
					//delete newMovie; //deallocate
				}
				else{
					keepgoing = false;
					//delete newMovie; //deallocate
				}
			}
			
		}	
	} //end while loop
}
	

void mainmenu(){
	int choice;
	cout << "Please type the number of the action you would like to take: " << endl;
	cout << "1. Log in " << endl;
	cout << "2. Create a new user " << endl;
	cout << "3. Quit " << endl;	
	cin >> choice;
	
	if (choice == 1){
		login();
	}
	else if (choice == 2){
		createUser();
	}
	else if (choice == 3){
		cout << "Thank you for using Netflix! Goodbye! " << endl;
	}
}



void login(){
	bool check = true;
	while(check){	
	cout << "Please enter your login ID: ";
	string userID;
	cin >> userID;
	try{
		User *helpme = AllUsers->get(userID); //try to find ID in User Map
		check = false;
		helpme->rentMovie(AllMovies->get(helpme->rentalhelper));
		string helptitle = AllMovies->get(helpme->rentalhelper)->getTitle();
		cout << "Successful login! " << endl << endl;
		search(helpme);
	}
	catch(NoSuchElementException &d) { 
		check = true;		
		cout << "Incorrect ID. Please try again. ";}
	}
	
}

void createUser(){
	bool check = true;
	string userID;
	while(check){
		cout << "Please enter an ID you would like to use: ";
		cin >> userID;
		try{
			User *temp = AllUsers->get(userID); //try to find ID in user map
			cout << "This ID has already been taken. Please try again." << endl;
			
		}
		catch(NoSuchElementException &d) { 
			check = false;		 //if not found, create new user below
			cout << "ID creation successful! " << endl;}
	}
	string name;
	cout << "Please enter your name: ";
	getline (cin, name);
	getline (cin, name);
	cout << "Thank you. An account has been created for you. " << endl << endl;
	User *newUser = new User(userID, name);
	AllUsers->add(userID, newUser);
	search(newUser);
}

void search(User* newUser){
	cout << "Current checked out movie: " << endl << endl;
	try{
		displaymovie(AllMovies->get(newUser->rentalhelper));
	}
	catch(NoSuchElementException &r){
		cout << "No movie checked out. " << endl;
	}
	cout << "Please type the number of the action you would like to take: " << endl;
	cout << "1. Search for a movie by title " << endl;
	cout << "2. Search for a movie by keyword " << endl;
	cout << "3. Return the current movie " << endl;
	cout << "4. View Queue " << endl;
	cout << "5. Logout " << endl;
	int num;
	cin >> num;
	if (num == 5){
		mainmenu();
	}
	else if (num == 3){
		if(newUser->rentalhelper!=""){
			newUser->rentMovie(NULL);
			newUser->rentalhelper = "";
			cout << "Movie rental is returned! " << endl << endl;
		}
		else{
			cout << "No movie rented. " << endl << endl;
		}
		search(newUser);
	}
	else if (num == 4){
		viewQueue(newUser);
	}
	else if (num == 1){
		bool check = true;
		while(check){
			cout << "Please enter a title to search for: ";
			string title;
			getline(cin, title);
			getline(cin, title);
			string searchtitle = converttolower(title); 
			//make sure you make this all lowercase and check it
			try{
				Movie *temp = AllMovies->get(searchtitle);
				displaymovie(temp);
				cout << "1. Add movie to queue " << endl;
				cout << "2. Return to menu " << endl;
				int l; 
				cin >> l;
				if (l == 1){
					newUser->movieQueue()->enqueue(temp);
					cout << "Movie successfully added to your queue" << endl;
					check = false;
					search(newUser);
				}
				else{
					check = false;
					search(newUser);
				}
			}
			catch (NoSuchElementException &d){
				cout << "Title wasn't found, try again. You'll have to enter the name twice." << endl;} 
		}
	}
	else if (num == 2){
		cout << "Please enter a keyword to search for: ";
		string keyword;
		getline(cin, keyword);
		getline(cin, keyword);
		string searchkeyword = converttolower(keyword); //convert searched keyword into lowercase
		try{
			Set<Movie*>* keyMovies = new Set<Movie*>;
			*keyMovies = KeyLookUp->get(searchkeyword); //create set of movie pointers related to that keyword
			int size = KeyLookUp->get(searchkeyword).sizeset();
			cout << "There are " << size << " movies that match this keyword. " << endl << endl;
			Set<Movie*>::Iterator samplemovie = keyMovies->begin();
			
			displaymovie(*samplemovie);	//display first movie-- this used to be samplemovie
			bool flag = true;
			int choice;
			for(int i = 0; i < size; i++){
				while(flag){
				if(size > 1){ 
					cout << "1. Next Movie " << endl;
					cout << "2. Add movie to queue " << endl;
					cout << "3. Return to menu " << endl << endl;
					cin >> choice;
					if(choice==1){
						++samplemovie;
						displaymovie(*samplemovie); 
						cout << endl;
						size--;
					}
					else if (choice ==3){
						flag = false;
						search(newUser);
					}
					else if (choice == 2){
						newUser->movieQueue()->enqueue(*samplemovie);
						cout << "Movie successfully added to your queue" << endl;
					}
				}
				else { //display until there are no more matching movies
					cout << "1. Add movie to queue " << endl;	
					cout << "2. Return to menu " << endl << endl;
					
					int c;
					cin >> c;
					if (c == 1){
						newUser->movieQueue()->enqueue(*samplemovie);
						cout << "Movie successfully added to your queue" << endl;
					}
					else{
						flag = false;
						search(newUser);
					}
				}
			}
		  }
		delete keyMovies;
		//delete samplemovie;
		}
		catch(NoSuchElementException &e){
			Movie *temp = AllMovies->get(searchkeyword);
			displaymovie(temp);
			cout << "1. Add movie to queue " << endl;
			cout << "2. Return to menu " << endl;
			int l; 
			cin >> l;
			if (l == 1){
				newUser->movieQueue()->enqueue(temp);
				cout << "Movie successfully added to your queue" << endl;
				//check = false;
			}
			else{
				search(newUser);
			}	
			search(newUser);
		}
		catch (NoSuchElementException &f){ 
			cout << "No such key word found. " << endl << endl;
			search(newUser); 
		}
	}
	else { 
		cout << "Incorrect entry." << endl;
		search(newUser);
	} 
}



		
void displaymovie(Movie* temp){
	string temptitle = temp->getTitle();
	cout << convertback(temptitle) << endl; //print title
	Set<string> moviekeys = temp->getAllKeywords(); //create set of keywords related to that movie
	try{
		
		for(Set<string>::Iterator itmoviekeys = moviekeys.begin(); itmoviekeys!=moviekeys.end(); ++itmoviekeys){
			cout << convertback(*itmoviekeys) << endl; //print out current keyword in set
		}	
	}
	catch (NoSuchElementException &e) {} 
	cout << endl << endl;
}

int findfirstletter(string input, int a){ //finds where to start reading keyword or title
	bool found = false;
	int i = a;
		while(!found && input[i] != '\n'){
			if(input[i] == ' '){
				found = false;
				i++;
			}
			else{
				found = true;
				return i;
			}
		}
}

string converttolower(string input){ //changes entire string to lowercase
	for (int i = 0; i < input.length(); i++){
		input[i]= tolower(input[i]);
	}
	return input;
}

string convertback(string input){ //correctly capitalizes string
	input[0] = toupper(input[0]);
	for (int i = 1; i < input.length(); i++){
		if(input[i] == ' '){
			input[i+1] = toupper(input[i+1]);
		}
	}
	return input;
}

			
		

void viewQueue(User* newUser){
	try{	
	cout << endl << "The first movie in your queue is: " << endl;
	Movie* firstmovie = newUser->movieQueue()->peekFront();	
	displaymovie(firstmovie);
	cout << "Please type the number of the action you would like to take:" << endl;
	cout << "1. Order movie" << endl;
	cout << "2. Remove movie from queue" << endl;
	cout << "3. Move movie to back of queue" << endl;
	cout << "4. Return to user menu" << endl;
	int choice;
	cin >> choice;
	if (choice == 1){
		if(newUser->rentalhelper == ""){
			newUser->rentMovie(firstmovie);
			newUser->rentalhelper=firstmovie->getTitle();
			cout << "you have successfully ordered the above movie!" << endl;
			newUser->movieQueue()->dequeue();
			search(newUser);
		}
		else{
			cout << "You must return your current rental before ordering another movie. " << endl;
			viewQueue(newUser);
		}
	}
	else if (choice == 2){
		newUser->movieQueue()->dequeue();
		cout << "Successfully removed movie from queue. " << endl << endl;
		viewQueue(newUser);
	}
	else if (choice == 3){
		newUser->movieQueue()->enqueue(firstmovie);
		newUser->movieQueue()->dequeue();
		viewQueue(newUser);
	}
	else if (choice ==4){
		search(newUser);
	}
	}
	catch(NoSuchElementException g){
		cout << "Empty Queue " << endl << endl;
		search(newUser);
	}
}

void writefile(string userfile){
	string userfile2= "./data/" + userfile;
	ofstream endfile;
	endfile.open(userfile2.c_str(), ios::out);
	for(Map<string, User*>::Iterator print = AllUsers->begin(); print!=AllUsers->end(); ++print){
		endfile << "BEGIN " << (*print).first << endl;
		endfile << "NAME: " << (*print).second->getName() << endl;
		if((*print).second->rentalhelper!=""){
			endfile << "MOVIE: " << (*print).second->rentalhelper << endl;
		}
		if(!(*print).second->movieQueue()->isEmpty()){
			endfile << "BEGIN QUEUE" << endl;
			while(!(*print).second->movieQueue()->isEmpty()){
				endfile << (*print).second->movieQueue()->peekFront()->getTitle() << endl;
				(*print).second->movieQueue()->dequeue();
			}
			endfile << "END QUEUE" << endl;
		}
		endfile << "END" << endl;
	}
	
}		




if (n->AllMovies->contains(newUser->rentalhelper)){
	 	Movie *temp = new Movie(n->AllMovies->get(newUser->rentalhelper)->getTitle());
	 	cout << "WOT ABOUT HEREEEE" << endl;
     	string temptitle = temp->getTitle();
	 	QString temptitle2 = QString::fromStdString(temptitle);
		rentaltitle = new QLabel(temptitle2);
		//private variable needs to be constructed here, declared in .h
		mainLayout->addWidget(rentaltitle);
	}
	else{
		mainLayout->addWidget(new QLabel ("No movie rented."));
	}





*/



