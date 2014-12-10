#include "netflix.h"

Netflix::Netflix(char* argv[]){
	this->loginid = ""; //keep track of who's logged in
	populate(argv);	
}

Netflix::~Netflix() {  //read in all users and movies
	string userfile2= "./data/" + outputfilename;
	ofstream endfile;
	endfile.open(userfile2.c_str(), ios::out);
	for(map<string, User*>::iterator print = AllUsers->begin(); print!=AllUsers->end(); ++print){
		endfile << "BEGIN " << (*print).first << endl;
		endfile << "NAME: " << (*print).second->getName() << endl;
		if((*print).second->rentalhelper!=""){
			endfile << "MOVIE: " << (*print).second->rentalhelper << endl;
		}
		endfile << "CCNUM: " << (*print).second->returnccnum() << endl;
		endfile << "ADDRESS: " << (*print).second->returnAddress() << endl;
		endfile << "CHARGE: " << (*print).second->returnCharges() << endl;
		endfile << "PASSWORD: "<< (*print).second->returnPassword() << endl;
		if(!(*print).second->movieQueue()->empty()){
			endfile << "BEGIN QUEUE" << endl;
			while(!(*print).second->movieQueue()->empty()){
				endfile << (*print).second->movieQueue()->front()->getTitle() << endl;
				(*print).second->movieQueue()->pop();
			}
			endfile << "END QUEUE" << endl;
		}
		
		endfile << "END" << endl;
	}
}

string Netflix::returnID(){
	return loginid;
}

void Netflix::setID(std::string newID){
	loginid = newID;
}

/*void Netflix::loginmenu(){
	
}*/


	//QT STUFF GOES HERE -->>> login window 
	//connect to an instance of a class for each function --> each class needs a .h file and a .cpp file

void Netflix::populate(char* argv[]){
	AllUsers = new map <string, User*>;
    AllMovies = new map<string, Movie*>;
    KeyLookUp = new map<string, set<Movie*> >;
	string filename;
	filename = argv[1];
	ifstream inputfile;
	inputfile.open(filename.c_str());
	if(inputfile.fail()){
		cout << "Incorrect file name. Please run the program again." << endl;
	}
	else{
	}
	stringstream ss;
	string userfile;
	getline(inputfile, userfile);
	ss << userfile;
	ss >> userfile;
	outputfilename = userfile;
	string moviefile;
	getline(inputfile, moviefile);
	ss << moviefile;
	ss >> moviefile;
	inputfile.close();


	//READ IN MOVIES
	ifstream movieinput;
	string fileofmovies2= "./data/" + moviefile;
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
			//cout << "title is " << title << endl;
			Movie *newMovie = new Movie(title); //create new movie with that title
			AllMovies->insert( std::pair<string,Movie*>(title,newMovie) );
			map<string, Movie*>::iterator help = AllMovies->find(title);
			//cout << "movie title is " << AllMovies->find(title)->second->getTitle() << endl;
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
						map<string, set<Movie*> >::iterator it = KeyLookUp->find(keyword);
						if(it!=KeyLookUp->end()){
							//cout << "add keyword error" << endl;
						}
						else{
							set<Movie*> setofmovies;
							setofmovies.insert(newMovie);
							KeyLookUp->insert( std::pair<string,set<Movie*> >(keyword, setofmovies) );
							//KeyLookUp->find(keyword)->second.insert(newMovie); //add that movie to the set that corresponds to that keyword
							
						}
						
					}
					catch(NoSuchElementException &e){
						set<Movie*> *temp = new set<Movie*>;
						temp->insert(newMovie);
//						KeyLookUp->add(keyword, *temp); //add that keyword and movie (to the set of) to keylookup
						KeyLookUp->insert( std::pair<string,set<Movie*> >(keyword,*temp) );				
						delete temp; //deallocate
					}
				}
				else if (command2 == "PRICE:"){
					int price;
					string str;
					for(int i = 6; i < nextline.length(); i++){
						str+= nextline[i];
					}
					istringstream ( str ) >> price;
					newMovie->setPrice(price);
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


	//READ IN USERS
	ifstream userinput;
	string fileofusers2= "./data/" + userfile;
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
			AllUsers->insert(std::pair<string,User*>(ID,newUser) );
			//AllUsers->add(ID, newUser);
			//cout << "this user's movie is " << 
			bool keepgoing = true;
			while(keepgoing){
				getline(userinput, nextline);
				string command2;
				stringstream s1;
				s1 << nextline;
				s1 >> command2;	
				//cout << "next command is " << command2 << endl;
				if(command2 == "BEGIN"){
					string command22;
					s1 >> command22;
					//cout << command2 << " " << command22 << endl;
					if(command22 == "QUEUE"){
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
								//cout << AllMovies->find(title)->
								map<string, Movie*>::iterator it = AllMovies->find(title);
								if(it!=AllMovies->end()){
									//Movie *temp = n->AllMovies->find(newUser->rentalhelper)->second;
									newUser->movieQueue()->push(AllMovies->find(title)->second);
								}
							}
						}
					}
					else if (command22 == "RATINGS"){
						bool flag = true;
						while(flag){
							getline(userinput, lastline);
							int rating = lastline[0];
							string ratingtitle;
							for(int i = 2; i < lastline.length(); i++){
										ratingtitle+=lastline[i];
							}
							if(ratingtitle == "END RATINGS"){
								flag = false;
							}
							else{
								//find the movie
								map<string, Movie*>::iterator it = AllMovies->find(ratingtitle);
								if(it!=AllMovies->end()){
									//Movie *temp = n->AllMovies->find(newUser->rentalhelper)->second;
									Movie* ratedmovie = AllMovies->find(ratingtitle)->second;
									//newUser->returnRatings()->add(ratedmovie, rating);
									newUser->returnRatings()->insert( std::pair<Movie*,int>(ratedmovie,rating) );
								}
								else{
									cout << "rating error" << endl;
								}
							}
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
				else if (command2 == "ADDRESS:"){
					string address = "";
					int z = findfirstletter(nextline, 9); //find where title begins
					for(int i = z; i < nextline.length(); i++){
					address+=nextline[i];
					}
					command = "";
					address = converttolower(address); //convert to lowercase for future use
					newUser->setAddress(address);
				}
				else if (command2 == "CHARGE:"){
					int charges = 0;
					string str;
					int z = findfirstletter(nextline, 8); //find where title begins
					for(int i = z; i < nextline.length(); i++){
					str+=nextline[i];
					}
					istringstream ( str ) >> charges;
					command = "";
					newUser->setCharges(charges);
				}
				else if (command2 == "PASSWORD:"){
					string password = "";
					int z = findfirstletter(nextline, 10); //find where title begins
					for(int i = z; i < nextline.length(); i++){
					password+=nextline[i];
					}
					//string realpassword;
					//realpassword = md5(password);
					command = "";
					newUser->setPassword(password);
				}
				else if (command2 == "CCNUM:"){
					int ccnum = 0;
					string str;
					int z = findfirstletter(nextline, 6); //find where title begins
					for(int i = z; i < nextline.length(); i++){
					str+=nextline[i];
					}
					istringstream ( str ) >> ccnum;
					command = "";
					newUser->setccnum(ccnum);
				}
				else if (command2 == "END"){
					keepgoing = false;
				}
				else{
					keepgoing = false;
				}
			
			}
		}	
	} 

}




int Netflix::findfirstletter(string input, int a){ //finds where to start reading keyword or title
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

string Netflix::converttolower(string input){ //changes entire string to lowercase
	for (int i = 0; i < input.length(); i++){
		input[i]= tolower(input[i]);
	}
	return input;
}

string Netflix::convertback(string input){ //correctly capitalizes string
	input[0] = toupper(input[0]);
	for (int i = 1; i < input.length(); i++){
		if(input[i] == ' '){
			input[i+1] = toupper(input[i+1]);
		}
	}
	return input;
}


