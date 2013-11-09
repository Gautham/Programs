#include <iostream>
#include "Array.h"
using namespace std;

// Flag = 1; Ascending
void BubbleSort(int A[], int n, bool flag = false) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if ((flag && A[j] > A[j + 1]) || (!flag && A[j] < A[j + 1])) {
				A[j] += A[j + 1];
				A[j + 1] = A[j] - A[j + 1];
				A[j] -= A[j + 1];
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
	BubbleSort(A, n, flag % 2);
	OutputArray(A, n);
}