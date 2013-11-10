#include <iostream>
#include "Array.h"
using namespace std;

// Flag = 1; Ascending
void CountingSort(int A[], int n, bool flag = false) {
	int B[50], C[50];
	for (int i = 0; i < 50; i++) B[i] = 0;
	for (int i = 0; i < 50 && i < n; i++) B[A[i]] = 1;
	for (int i = 1; i < n; i++) B[i] += B[i - 1];
	for (int i = 0; i < n; i++) C[i] = A[i];
	for (int i = n - 1; i >= 0; i--) {
		A[B[C[i]]] = C[i];
		B[C[i]] -= 1;
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
	CountingSort(A, n, flag % 2);
	OutputArray(A, n);
}