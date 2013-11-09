#include <iostream>
#include "Array.h"
using namespace std;

int BinarySearch(int A[], int n, int E) {
	int p = 0, q = n - 1;
	for (int mid = (p + q) / 2; p <= q; mid = (p + q) / 2) {
		if (A[mid] > E) q = mid - 1;
		else if (A[mid] < E) p = mid + 1;
		else return mid;
	}
	return -1;
}

int main() {
	int A[50], n, E;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	cout<<"Element To Search For : ";
	cin>>E;
	cout<<BinarySearch(A, 5, E)<<endl;
}
