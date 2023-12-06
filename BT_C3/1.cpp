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

bool search_BFS(int n,int x){
    queue<int> q;
    bool C[M];
    int v = 0;
    memset(C,false,sizeof(C));
    q.push(v);
    C[v] = true;
    while(!q.empty()){
        int p = q.front();
        if(vertex[p] == x) return true;
        q.pop();
        for(int i = 0;i<n;i++){
            if(C[i] == false and a[p][i] == 1){
                q.push(i);
                C[i] = true;
            }
        }
    }
    return false;
}

bool search_DFS(int n,int x){
    stack<int> s;
    bool C[M];
    memset(C,false,sizeof(C));
    int v = 0;
    s.push(v);
    if(vertex[v] == x) return true;
    int w = -1,u = v;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w<n;w++){
            if(a[u][w] != 1 and !C[w]){
                s.push(u);
                s.push(w);
                if(vertex[w] == x) return true;
                C[w] = true;
                u = w;
                break;
            }
        }
    }
    return false;
}


int main(){
    int n;
    input(a,vertex,n);
    output(a,vertex,n);
    cout << "bfs : ";bfs(n,0);cout << "\n";
    //cout << "dfs : ";dfs(a,vertex,n,0);
    // int x_bfs;cout << "Nhap dinh ma ban muon tim : ";cin >> x_bfs;
    // if(search_BFS(n,x_bfs)) cout << "y \n";
    // else cout << "n \n";
    int x_dfs;cout << "Nhap dinh ma ban muon tim : ";cin >> x_dfs;
    if(search_DFS(n,x_dfs)) cout << "y \n";
    else cout << "n \n";
    return 0;
}