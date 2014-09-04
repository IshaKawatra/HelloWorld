#include <iostream> 
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
bool is_both_space (char a, char b);


int main (int argc, char* argv[]){
  ifstream readFile;
  string filename = argv[1];
  string line;
  string line2;
  int count = 0;
  int numLines = 0;
  readFile.open(filename.c_str()); //read in file
  getline(readFile, line); //examine first line
  int words[line[1]]; //create array of words with size given in first line

  for (int i = 0; i <= line[1]+2; i++){
  	getline(readFile, line2); //examine next line
  	for (int x = 0; x <= int(line2.length()); x++){
		line2.erase(unique(line2.begin(), line2.end(), is_both_space), line2.end()); //erase unnecessary spaces   
		if (isspace(line2[x])){ //if character is a space, add to count
      			count++;
  		}
	}
  	words[i] = count; //adds the amt of words in each line to an array
  	count = 0;
  }
  for (int p = line[1]+2; p >= 0; p--){
	cout << words[p]+1 << endl; //prints array of words backwards
  }
  return count;
  readFile.close(); //close file
  cin.get();
  return 0;
}

bool is_both_space(char a, char b) //eliminates extra spaces between words so that there's only one
{
return isspace(a) && isspace(b);
}
