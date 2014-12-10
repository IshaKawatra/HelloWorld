#ifndef MERGESORT_H
#define MERGESORT_H
#include<cmath>
#include<iostream>
#include<vector>
class MergeSort {
  public:
    template <class T>
     vector<T> sort(vector<T> a) {
		helper(a, 0, a.size()-1);
	}
	
      //sort code here

  private:
	template <class T>
	 vector<T> helper(vector<T>a, int l, int r){
		if (l < r){
			int m = floor((l+r)/2);
			sort(a, l, m);
			sort(a, m+1, r);
			merge(a, l, r, m);
		}
	}
	template <class T> 
	void merge(vector<T> a, int l, int r, int m){
		vector<T> temp;
		int i = l, j = m+1, k = 0;
		while (i <= m || j <= r){
			if(i <= m && (j>r || a[i] <= a[j])){
				temp.at(k) = a.at(i); i++; k++;
			}
			else{
				temp.at(k) = a.at(j); j++; k++;
			}
		}
		for(k = 0; k < r+1-l; k++){
			a.at(k+1) = temp.at(k);
		}
	}
};
#endif
