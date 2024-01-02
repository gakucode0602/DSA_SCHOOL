#include<iostream>
#include<queue>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define M 100
int a[M][M];
int vertex[M];
int bfs[M];
int nbfs = 0;

void inputFile(int a[][M],int vertex[] ,int &n,int &x) {
	ifstream in("data.txt");
	if (in.is_open()) {
		in >> n >> x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				in >> a[i][j];
			}
		}
		in.close();
	}
	else cout << "Error" << endl;
}

void arrange(queue <int> &q){
	vector<int> v;
	while(!q.empty()){
		v.push_back(q.front());
		q.pop();
	}
	sort(v.begin(),v.end());
	for(auto x : v){
		q.push(x);
	}
}

void BFS(int a[][M],int n,int x) {
	queue<int> q;
	bool C[M];
	memset(C, false, sizeof(C));
	q.push(x);
	C[x] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		bfs[nbfs] = p + 1;
		nbfs++;
		for (int i = 0; i < n; i++) {
			if (!C[i] && a[p][i] == 1) {
				q.push(i);
				C[i] = true;
			}
		}
		arrange(q);
	}
}


void write(int bfs[], int nbfs) {
	ofstream out("output.txt");
	if (out.is_open()) {
		out << "So dinh tim duoc : " << nbfs - 1 << endl;
		for (int i = 1; i < nbfs; i++) {
			out << bfs[i] << " ";
		}
		out.close();
	}
	else cout << "Error";
}

int main() {
	int n,x;
	inputFile(a, vertex, n, x);
	BFS(a, n, x - 1);
	write(bfs, nbfs);
	cout << "Success" << endl;
	system("pause");
	return 0;
}