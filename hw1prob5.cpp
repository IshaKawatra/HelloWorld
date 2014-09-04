#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
int main (int argc, char* argv[]){
  string filename; 
  ifstream inputfile;
  filename = argv[1];
  inputfile.open(filename.c_str()); //read in file
  string STRING1;
  getline(inputfile,STRING1); 
  stringstream s1;		
  s1 << STRING1; //use string stream to parse first line for information
  int numBuckets, numCommands;
  s1 >> numBuckets >> numCommands;
  int** buckets = new int*[numBuckets]; //dynamically allocate array of buckets
  for (int l = 0; l < numBuckets; l++)
	{buckets[l] = NULL;}
  int empty[numBuckets]; //allocate array to determine if empty or full
  for (int l = 0; l < numBuckets; l++)
	{empty[l] = 0;}
  string STRING2;
  int bucketsize[numBuckets];
  for (int f = 0; f < numCommands; f++) //go through each command
  {
	getline(inputfile, STRING2); 
	stringstream ss; //use string stream to parse next line	
	ss << STRING2;
	string command;
	int whichbucket, howmany;
	ss >> command >> whichbucket;
	if(command == "PUT"){ //if it directs to fill the bucket
		if (whichbucket <= numBuckets){
			if (empty[whichbucket-1]==0){	
				ss >> howmany;
				bucketsize[whichbucket] = howmany;	
				*(buckets+whichbucket) = new int[howmany];
				for (int n = 0; n < howmany; n++){
					ss >> buckets[whichbucket][n];
					}
				empty[whichbucket-1] = 1; //empty array indices are off by one			
				}
			else{ 
				cout << "Error: bucket isn't empty" << endl;
				}
		}
		else
			{cout << "Error" << endl;}
	}
	else if(command == "OUTPUT"){ //if it directs to output contents of bucket
		if ((whichbucket <= numBuckets) && (whichbucket > 0) && (empty[whichbucket-1] == 1))	
		{	
			for (int c = 0; c < bucketsize[whichbucket]; c++){
				
				cout << buckets[whichbucket][c] << " ";
			}
			cout << endl;
		}
		else if ((whichbucket <= numBuckets) && (whichbucket > 0) && (empty[whichbucket-1] == 0))
		{
			cout << "Error: bucket is empty" << endl;
		} 
		else
		{
			cout << "Error: bucket does not exist" << endl;
		}
	}
	else if (command == "EMPTY") //if it directs to empty a bucket
	{
		if (whichbucket <= numBuckets)
		{			
			(empty[whichbucket-1]) = 0;
			delete [] buckets[whichbucket];
		}
		else
		{
			cout << "Error" << endl;
		}
			
		}		
  }
for (int l = 0; l < numBuckets; l++){
	delete [] buckets[l];
}
delete [] buckets;
return 0;

}
			
	
  
