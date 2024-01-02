#include<iostream>
#include<queue>
#include<fstream>
#include<cstring>
using namespace std;
typedef queue<int> q;
#define M 101
int a[M][M],vertex[M];
void inputFile(int a[][M],int vertex[],int &n){
    ifstream in("text.txt");
    if(in.is_open()){
        in >> n;
        for(int i = 0;i<n;i++){
            in >> vertex[i];
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                in >> a[i][j];
            }
        }
        in.close();
    }
    else cout << "Error \n"; 
}

void output(int a[][M],int vertex[],int n){
    cout << "  ";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << '\n';
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int a[][M],int vertex[],int n,int x){
    q qu;
    bool C[M];
    memset(C,false,sizeof(C));
    qu.push(x);
    C[x] = true;
    while(!qu.empty()){
        int p = qu.front();
        qu.pop();
        cout << vertex[p] << " ";
        for(int i = 0;i<n;i++){
            if(!C[i] and a[p][i] == 1){
                qu.push(i);
                C[i] = true;
            }
        }
    }
    cout << endl;
}

int main(){
    int n;
    inputFile(a,vertex,n);
    output(a,vertex,n);
    BFS(a,vertex,n,0);

    return 0;
}