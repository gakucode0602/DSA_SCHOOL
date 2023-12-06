#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
#include<cstdio>
using namespace std;
#define M 101
int a[M][M];
int vertex[M];
// chuyển từ ma trận kê sang danh sách kề
void input(int a[][M],int vertex[],int &n){
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
void output(int a[][M],int vertex[],int n)
{
    cout << "Adjency matrix : \n";
    cout << "    ";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << "\n";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " : ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void DFS(int a[][M],int vertex[],int n,int &x){
    cout << "Input the start vertex : ";
    cin >> x;
    stack<int> s;
    bool checked[M];
    memset(checked,false,sizeof(checked));
    cout << vertex[x] << " ";
    s.push(x);
    checked[x] = true;
    int w = -1,u = x;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w < n;w++){
            if(!checked[w] && a[u][w] != 0){
                s.push(u);
                s.push(w);
                cout << vertex[w] << " ";
                checked[w] = true;
                u = w;
                break;
            }
        }
    }
}
bool find(int a[][M],int vertex[],int n,int &search){
    cout << "Input the vertex you want to find : ";
    cin >> search;
    int x = 0;
    stack<int> s;
    bool check[M];memset(check,false,sizeof(check));
    if(vertex[x] == search) return true;
    check[x] = true;
    s.push(x);
    int w = -1,u = x;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w<n;w++){
            if(!check[w] && a[u][w]!=0){
                s.push(u);
                s.push(w);
                if(vertex[w] == search) return true;
                check[w] = true;
                u = w;
                break;
            }
        }
    }
    return false;
}
int n,x,search;
int main(){
    input(a,vertex,n);
    output(a,vertex,n);
    DFS(a,vertex,n,x);
    string ans;
    ans = find(a,vertex,n,search) ? "y" : "n";
    cout << ans << "\n";
    return 0;
}