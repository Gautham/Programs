#include <iostream>
#include "Array.h"
using namespace std;

int Left(int i) {
	return (2*i + 1);
}

int Right(int i) {
	return (2*i + 2);
}

int Parent(int i) {
	return (i - 1) / 2;
}

void MaxHeapify(int A[], int n, int i) {
	int l = Left(i), r = Right(i);
	int max = i;
	if (l < n && A[l] > A[max]) max = l;
	if (r < n && A[r] > A[max]) max = r;
	if (max != i) {
		A[i] += A[max];
		A[max] = A[i] - A[max];
		A[i] -= A[max];
		MaxHeapify(A, n, max);
	}
}

void BuildMaxHeap(int A[], int n) {
	for (int i = n/2; i >= 0; i--) MaxHeapify(A, n, i);
}


void HeapSort(int A[], int n) {
	BuildMaxHeap(A, n);
	for (int i = n - 1; i > 0; i--, n--) {
		A[i] += A[0];
		A[0] = A[i] - A[0];
		A[i] -= A[0];
		MaxHeapify(A, n - 1, 0);
	}
}



int main() {
	int A[50], n;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	HeapSort(A, n);
	OutputArray(A, n);
}