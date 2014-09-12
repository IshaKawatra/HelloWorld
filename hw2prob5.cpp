#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <cstring>


using namespace std;

int sumnums(int allNums[], int size);

int main (int argc, char* argv[]){
  const int ITERATE = 1000;
  int outNum = 0;
  stringstream s1(argv[2]);
  s1 >> outNum;
  clock_t start, finish;
  clock_t start2, finish2;
  double dur;
  double dur2;
  ifstream inputfile;
  string filename;
  filename = argv[1];
  inputfile.open(filename.c_str());
  stringstream ss;
  string firstline;
  getline(inputfile, firstline);
  ss << firstline;
  int numNums;
  ss >> numNums;
  int sum = 0;
  int* allNums = new int[numNums];
  
  for (int i = 0; i < numNums; i++){
	string nextLine;
    getline(inputfile, nextLine);
    stringstream s2;
    int nextNum;
    s2 << nextLine;
    s2 >> nextNum;
    allNums[i] = nextNum;
  }
  cout << "iteratively we do this: " << endl;
  start = clock();
  for (int d = 0; d < outNum; d++){
	sum = 0;
	for (int l = 0; l < numNums; l++){
    sum+= allNums[l];
  	}
  }
  
  finish = clock();
	cout << sum << endl;
  dur = (double)(finish-start);
  dur/= (CLOCKS_PER_SEC);
  cout << "elapsed iterative seconds: " << scientific << dur << endl;

  cout << "recursively we do this: " << endl;
  int recursiveSum = 0;
  start2 = clock();
  for (int p = 0; p < outNum; p++){
  	recursiveSum= sumnums(allNums, numNums);}
  
  finish2 = clock();
	cout << recursiveSum << endl;
  dur2 = (double)(finish-start);
  dur/= (CLOCKS_PER_SEC*ITERATE);
  cout << "elapsed recursive seconds: " << scientific << dur2 << endl;
  return 0;
}

  int sumnums(int allNums[], int size){
	if (size == 1){
		return allNums[0];
	}
	else{
		return allNums[0] + sumnums(allNums+1, size-1);
	}
  }
