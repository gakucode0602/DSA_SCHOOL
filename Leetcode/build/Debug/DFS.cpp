#include<iostream>
#include<stack>
#include<fstream>
using namespace std;
#define M 1001
int a[M][M],vertices[M];

void input(int a[][M],int vertices[],int &n){
	ifstream fi("data.txt");
	if(fi.is_open()){
		fi >> n;
		for(int i = 0;i<n;i++){
			fi >> vertices[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				fi >> a[i][j];
			}
		}
		fi.close();
	}
	else cout << "error" << endl;void output(int a[][M],int vertices[],int n){
	cout << "    ";
	for(int i = 0;i<n;i++){
		cout << vertices[i] << " ";
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}


int main(){
	int n;
	input(a,vertices,n);
	output(a,vertices,n);
	return 0;
}