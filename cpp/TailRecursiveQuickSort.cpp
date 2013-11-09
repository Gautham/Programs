#include <iostream>
#include "Array.h"
using namespace std;



// Flag = 1; Ascending
int Partition(int A[], int p, int r, int flag) {
	int x = A[r], i = p - 1;
	for (int j = p; j < r; j++) {
		if ((flag && A[j] <= x) || (!flag && A[j] >= x)) {
			if (++i != j) {
				A[i] += A[j];
				A[j] = A[i] - A[j];
				A[i] -= A[j];
			}
		}
	}
	if (++i != r) {
		A[i] += A[r];
		A[r] = A[i] - A[r];
		A[i] -= A[r];
	}
	return i;
}

void QuickSort(int A[], int p, int r, bool flag = false) {
	while (p < r) {
		int q = Partition(A, p, r, flag);
		QuickSort(A, p, q - 1, flag);
		p = q + 1;
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
	QuickSort(A, 0, n - 1, flag % 2);
	OutputArray(A, n);
}