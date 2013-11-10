#include <iostream>
#include <math.h>
#include "Array.h"
using namespace std;

// Flag = 1; Ascending
void InsertionSort(int A[], int n, int pos, bool flag = false) {
	for (int i = 1; i < n; i++) {
		int p = (int)(A[i] / pow(10, pos - 1)) % 10, q = A[i], j;
		for (j = i - 1; j >= 0 && ((flag && (int)(A[j] / pow(10, pos - 1)) % 10 > p) || (!flag && (int)(A[j] / pow(10, pos - 1)) % 10 < p)); j--) A[j + 1] = A[j];
		A[j + 1] = q;
	}
}

void RadixSort(int A[], int n, bool flag) {
	int max = A[0], d = 0;
	for (int i = 1; i < n; i++) if (A[i] > max) max = A[i];
	while (max > 0) { max /= 10; d++; }
	for (int i = 1; i <= d; i++) InsertionSort(A, n, i, flag);
}

int main() {
	int A[50], n, flag;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	cout<<"1. Ascending 2. Descending    : ";
	cin>>flag;
	RadixSort(A, n, flag % 2);
	OutputArray(A, n);
}