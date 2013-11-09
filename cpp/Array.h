#include <iostream>
using namespace std;

#ifndef ARRAYS
#define ARRAYS
void InputArray(int A[], int n) {
	for (int i = 0; i < n; i++) cin>>A[i];
}

void OutputArray(int A[], int n) {
	for (int i = 0; i < n; i++) cout<<A[i]<<"  ";
}
#endif 
