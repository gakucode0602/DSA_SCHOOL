#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
#include<cstring>
using namespace std;
#define M 1001
int a[M][M], vertex[M];

void input(int a[][M],int vertex[],int &n){
    ifstream in("data.txt");
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
    cout << "\n";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int n,int v){
    queue<int> q;
    bool visited[M];
    memset(visited,false,sizeof(visited));
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout << vertex[p] << " ";
        for(int i = 0;i<n;i++){
            if(visited[i] == false and a[p][i] == 1){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << "\n";
}

void dfs(int a[][M],int vertex[],int n,int v){
    stack<int> s;
    bool visited[M];
    memset(visited,false,sizeof(visited));
    s.push(v);
    cout << vertex[v] << " ";
    visited[v] = true;
    int w = -1,u = v;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w < n;w++){
            if(a[u][w] != 0 and !visited[w]){
                s.push(u);
                s.push(w);
                cout << vertex[w] << " ";
                visited[w] =  true;
                u = w;
                break;
            }
        }
    }
}

int main(){
    int n;
    input(a,vertex,n);
    output(a,vertex,n);
    cout << "bfs : ";bfs(n,0);cout << "\n";
    cout << "dfs : ";dfs(a,vertex,n,0);
    return 0;
}