#include<iostream>
using namespace std;
#define M 20
/*
	A B C D E F G
7
0 1 1 1 0 0 0
1 0 1 0 1 1 0
1 1 0 1 0 1 0
1 0 1 0 0 1 1
0 1 0 0 0 1 0
0 1 1 1 1 0 1
0 0 0 1 0 1 0
*/


void input(int a[][M], int &n) {
	cout << "Nhap so dinh cho do thi : \n"; cin >> n;
	while (n <= 0 or n > M) {
		cout << "Nhap lai : "; cin >> n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		cout << '\n';
	}
}


void output(int a[][M], int n) {
	cout << "Ma tran ke da cho : \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void main() {
	int n;
	char vertices[M];
	int a[M][M];
	input(a, n);
	output(a, n);
}
