#include<iostream>
#include<queue>
#include<cstring>
#include<fstream>
using namespace std;
#define M 101
int a[M][M],vertex[M];
int n, x;

/*
7
1 2 3 4 5 6 7
0 1 1 1 0 0 0
1 0 1 0 1 1 0
1 1 0 1 0 1 0
1 0 1 0 0 1 1
0 1 0 0 0 1 0
0 1 1 1 1 0 1
0 0 0 1 0 1 0
*/
void input(int a[][M], int vertex[], int& n);
void output(int a[][M], int vertex[], int n);
void BFS(int a[][M], int vertex[], int n, int& x);
bool find(int a[][M], int vertex[], int n, int& x);
void execute(int a[][M], int vertex[], int n);

int main() {
	input(a, vertex, n); output(a, vertex, n);
	BFS(a, vertex, n, x);
	execute(a, vertex, n);
	return 0;
}

void input(int a[][M], int vertex[], int& n) {
	cout << "Input the number of vertex : " << endl; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl;
}


void output(int a[][M], int vertex[], int n) {
	cout << "  ";
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " ";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(int a[][M], int vertex[], int n, int& x) {
	cout << "Input the vertex you want to start : "; cin >> x;
	queue<int> q;
	bool C[M];
	memset(C, false, sizeof(C));
	q.push(x);
	C[x] = true;
	cout << "BFS : ";
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		cout << vertex[p] << " ";
		for (int i = 0; i < n; i++) {
			if (!C[i] && a[p][i] == 1) {
				q.push(i);
				C[i] = true;
			}
		}
	}
	cout << endl;
}
bool find(int a[][M], int vertex[], int n, int& x) {
	cout << "Input the vertex you want to find : "; cin >> x;
	queue<int> q;
	int start = 0;
	bool C[M];
	memset(C, false, sizeof(C));
	q.push(start);
	C[start] = true;
	while (!q.empty()) {
		int p = q.front();
		if (vertex[p] == vertex[x]) return true;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (!C[i] && a[p][i] == 1) {
				C[i] = true;
				q.push(i);
			}
		}
	}
	return false;
}

void execute(int a[][M], int vertex[], int n) {
	int x;
	if (find(a, vertex, n, x)) cout << "Y" << endl;
	else cout << "N" << endl;
}