#include <iostream>
using namespace std;

struct Node {
	int a;
	Node * next;
};

void Insert(Node * &P, int p) {
	Node * Q = P;
	if (Q == 0) {
		Q = new Node;
		P = Q;
	} else {
		while (Q->next != 0) Q = Q->next;
		Q->next = new Node;
		Q = Q->next;
	}
	Q->a = p;
	Q->next = 0;
}

void Delete(Node * &P) {
	Node * Q = P;
	if (Q == 0) return;
	if (Q->next == 0) P = 0;
	else {
		while (Q->next->next != 0) Q = Q->next;
		Q->next = 0;
	}
}

Node * Search(Node * P, int E) {
	while (P != 0 && P->a != E) P = P->next;
	return P;
}

void Print(Node * P) {
	if (P == 0) cout<<"Empty";
	while (P != 0) {
		cout<<P->a<<' ';
		P = P->next;
	}
	cout<<endl;
}

void Reverse(Node * &P) {
	if (P == 0 || P->next == 0) return;
	Node * T, * Q = P, * Prev = 0;
	while (Q->next != 0) {
		T = Q->next;
		Q->next = Prev;
		Prev = Q;
		Q = T;
	}
	Q->next = Prev;
	P = Q;
}

int main() {
	int n, i , p;
	Node * START = 0;
	cout<<"Input No. Of Elements : ";
	cin>>n;
	for (i = 0; i < n; i++) {
		cin>>p;
		Insert(START, p);
	}
	Print(START);
	Reverse(START);
	Print(START);
	Delete(START);
	Delete(START);
	Print(START);
	Delete(START);
	Node * N = Search(START, 4);
	if (N != 0) cout<<"Found\n"; else cout<<"Not Found\n";
	Delete(START);
	Delete(START);
	Print(START);
}
