#include <iostream>
#include "Array.h"
using namespace std;

void Merge(int A[], int p, int r) {
	int B[100];
	int i = p, q = (p + r) / 2, j = q + 1, k = p;
	for (; i <= q && j <= r; k++) {
		if (A[i] <= A[j]) B[k] = A[i++];
		else B[k] = A[j++];
	}
	while (i <= q) B[k++] = A[i++];
	while (j <= r) B[k++] = A[j++];
	k--;
	while (k >= p) { A[k] = B[k]; k--; }
}


// Flag = 1; Ascending

void MergeSort(int A[], int p, int r, bool flag = false) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, r);
	}
}

int main() {
	int A[50], n;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	MergeSort(A, 0, n - 1);
	OutputArray(A, n);
}