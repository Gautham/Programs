#include <iostream>
#include "Array.h"
using namespace std;

int LinearSearch(int A[], int n, int E) {
	int i;
	for (i=0; i<n && A[i] != E; i++);
	return (i == n) ? -1 : i;
}

int main() {
	int A[50], n, E;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	cout<<"Elements : "; 
	InputArray(A, n);
	cout<<"Element To Search For : ";
	cin>>E;
	cout<<LinearSearch(A, 5, E)<<endl;
}
