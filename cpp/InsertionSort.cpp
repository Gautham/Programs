#include <iostream>
#include "Array.h"
using namespace std;

// Flag = 1; Ascending
void InsertionSort(int A[], int n, bool flag = false) {
	for (int i = 1; i < n; i++) {
		int p = A[i], j;
		for (j = i - 1; j >= 0 && ((flag && A[j] > p) || (!flag && A[j] < p)); j--) A[j + 1] = A[j];
		A[j + 1] = p;
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
	InsertionSort(A, n, flag % 2);
	OutputArray(A, n);
}