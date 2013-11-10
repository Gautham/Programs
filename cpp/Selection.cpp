#include <iostream>
#include "Array.h"
using namespace std;



// Flag = 1; Ascending
int Partition(int A[], int p, int r) {
	int x = A[r], i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
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

int Select(int A[], int p, int r, int i) {
	if (p == r) return A[p];
	int q = Partition(A, p, r);
	int k = q - p + 1;
	if (i == k) return A[q];
	else {
		if (i < k) return Select(A, p, q - 1, i);
		else return Select(A, q + 1, r, i);
	}
}

int main() {
	int A[50], n, i;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	cout<<"Input i    : ";
	cin>>i;
	cout<<Select(A, 0, n - 1, i);
}