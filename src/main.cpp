/**
 * @file main.cpp
 * @brief This is an implementation of merge search 
 * @details This is taken from the book open data sources and edited to use base C++ code.
 * @author Lee Beckermeyer
 * @date 4/18/2021
 */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int printVec(vector<int> a){
    int* pos = a.data();
    for (int i = 0; i < a.size(); i++){
      cout << *pos++ << " ";
    };
    cout << endl;
    return(0);
}

int compare(int &x, int &y) {
	if (x < y) return -1;
	if (y < x) return 1;
	return 0;
}

void merge(vector<int> &a0, vector<int> &a1, vector<int> &a) {
  int i0 = 0, i1 = 0;
  for (int i = 0; i < a.size(); i++) {
    if (i0 == a0.size())
      a[i] = a1[i1++];
    else if (i1 == a1.size())
      a[i] = a0[i0++];
    else if (compare(a0[i0], a1[i1]) < 0)
      a[i] = a0[i0++];
    else
      a[i] = a1[i1++];
  }
}

vector<int> mergeSort(vector<int> &a) {
  if (a.size() <= 1) return(a);
  vector<int> a0;
  vector<int> a1;
  for (int i = 0; i < a.size(); i++){
      if (i < a.size()/2){
          a0.push_back(a[i]);
      }
      else {
          a1.push_back(a[i]);
      };
    }
  mergeSort(a0);
  mergeSort(a1);
  merge(a0, a1, a);
  return(a);
} 

int main(int, char**) {
    vector<int> vec = {13,8,5,2,4,0,6,9,7,3,12,1,10,11};//only works with exponents of 2 currently.
    cout << "before: ";
    printVec(vec);
    mergeSort(vec);
    cout << "after: ";
    printVec(vec);
}
