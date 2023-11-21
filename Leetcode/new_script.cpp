#include<iostream>
#include<stack>
#include<fstream>
#include<cstring>
#include<queue>
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
    else cout << "error" << endl;
}

void output(int a[][M],int vertices[],int n){
    cout << "   ";
    for(int i = 0;i<n;i++){
        cout << vertices[i] << " ";
    }
    cout << "\n";
    for(int i = 0;i<n;i++){
        cout << vertices[i] << "  ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int a[][M],int vertices[],int n,int v){
    stack<int> s;
    bool C[M];
    memset(C,false,sizeof(C));
    s.push(v);
    cout << vertices[v] << " ";
    C[v] = true;
    int w = -1,u = v;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w < n;w++){
            if(a[u][w] != 0 and !C[w]){
                s.push(u);
                s.push(w);
                cout << vertices[w] << " ";
                C[w] = true;
                u = w;
                break;
            }
        }
    }
}

void bfs(int a[][M],int vertices[],int n,int v){
    queue<int> q;
    bool C[M];
    memset(C,false,sizeof(C));
    q.push(v);
    C[v] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout << vertices[p] << " ";
        for(int i = 0;i<n;i++){
            if(C[i] == false and a[p][i]==1){
                q.push(i);
                C[i] = true;
            }
        }
    }
}

int main(){
    int n;
    input(a,vertices,n);
    output(a,vertices,n);cout << "\n";
    cout << "DFS : ";dfs(a,vertices,n,0);cout << '\n';
    cout << "BFS : ";bfs(a,vertices,n,0);
    return 0;
}