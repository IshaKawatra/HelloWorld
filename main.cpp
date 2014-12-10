#include <iostream>
#include <fstream>
#include <cstring>

#include "netflix.h"
#include "loginwindow.h"
//#include "searchwindow.h"
#include "./lib/projset.h"
#include<QApplication>

using namespace std;

int main(int argc, char* argv[]) {

//testing set intersection
/*Set<int> *test1 = new Set<int>;
int first1 = 1;
int first2 = 2;
int first3 = 3;
int first4 = 4;
int first6 = 6;
test1->add(first1);
test1->add(first2);
test1->add(first3);
test1->add(first4);
test1->add(first6);

Set<int> *test2 = new Set<int>;
int second2 = 2;
int second3 = 3;
int second6 = 6;
int second7 =7;
test2->add(second2);
test2->add(second3);
test2->add(second6);
test2->add(second7);

Set<int> result = test2->setIntersection(*test1);

for(Set<int>::Iterator it = result.begin(); it!=result.end(); ++it){
		cout << (*it) << " ";
}

*/
  Netflix *netflix = new Netflix(argv); //users and movies populated in database
  QApplication app(argc, argv);
	LoginWindow w(netflix); //open login window
	w.show();
  return app.exec();
}

