#include <iostream>
#include "Array.h"
using namespace std;

// Flag = 1; Ascending
void SelectionSort(int A[], int n, bool flag = false) {
	for (int i = 0; i < n; i++) {
		int f = A[i], pos = i;
		for (int j = i + 1; j < n; j++)
			if ( (flag && A[j] < f) || (!flag && A[j] > f) ) {
				f = A[j];
				pos = j;
			}
		A[pos] = A[i];
		A[i] = f;	
	}
}

int main() {
	int A[50], n, flag;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	cout<<"1. Ascending 2. Descending    : ";
	cin>>flag;
	SelectionSort(A, n, flag % 2);
	OutputArray(A, n);
}