#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;
#define M 51
#define INF 999999
int a[M][M];
char vertex[M] = {'a','b','c','d','e','g','h','k','i'};
void readFile(int a[][M],int &n){
    ifstream in("Input.txt");
    if(in.is_open()){
        in >> n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                in >> a[i][j];
            }
        }
        cout << "Success \n";
        in.close();
    }
    else cout << "Error \n";
}

void output(int a[][M],int n){
    cout << "Ma tran dang trong so cua do thi da cho \n";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

char BFS_arr[M];
int nbfs;
int par[M];
void BFS(int a[][M],int n,bool C[],int start){
    nbfs = 0;
    memset(par,-1,sizeof(par));
    //memset(C,false,sizeof(C));
    queue<int> q;
    C[start] = true;
    q.push(start);
    while(!q.empty()){
        int p = q.front();q.pop();
        BFS_arr[nbfs++] = vertex[p];
        for(int i = 0;i<n;i++){
            if(!C[i] && a[p][i]){
                C[i] = true;
                q.push(i);
                par[i] = p;
            }
        }
    }
}

void out_BFS(int a[][M],int n,int start){
    bool C[M];
    memset(C,false,sizeof(C));
    BFS(a,n,C,start);
    for(int i = 0;i<nbfs;i++){
        cout << BFS_arr[i] << " ";
    }
    cout << endl;
}

bool is_direct(int a[][M],int n){
    bool check[M][M];
    for(int i = 0;i<n;i++){
        memset(check[i],false,sizeof(check[i]));
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!check[i][j]){
                if(a[i][j] == a[j][i]){
                    check[i][j] = true;check[j][i] = true;
                }
                else return true;
            }
        }
    }
    return false;
}

void level_of_vertex(int a[][M],int n){
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(a[i][j]) cnt++;
        }
        cout << vertex[i] << " : " << cnt << endl;
    }
}

void find_Path(int a[][M],int n,int start,int end){
    int path[M];
    int n_path = 0;
    bool C[M];
    memset(C,false,sizeof(C));
    BFS(a,n,C,0);
    if(!C[end]){
        cout << "No path \n";
    }
    else{
        for(int v = end;v != start;v = par[v]){
            path[n_path++] = v;
        }
        path[n_path] = start;
        cout << "Path : "; 
        for(int i = n_path;i>=1;i--){
            cout << vertex[path[i]] << " -> ";
        }
        cout << vertex[path[0]] << endl;
    }
}

void prim(int a[][M],int n){
    int no_Edge = 0;
    bool C[M];memset(C,false,sizeof(C));
    C[0] = true;
    while(no_Edge < n){
        int min = INF;
        int x,y;
        for(int i = 0;i<n;i++){
            if(C[i]){
                for(int j = 0;j<n;j++){
                    if(!C[j] && a[i][j] != 0){
                        if(min > a[i][j]){
                            x = i;y = j;min = a[i][j];
                        }
                    }
                }
            }
        }
        cout << vertex[x] << " - " << vertex[y] << " - " << a[x][y] << endl;
        C[y] = true;
        no_Edge++;
    }
}

struct Edge{
    int u,v,c;
    Edge () {};
    Edge(int _u,int _v,int _c) : u(_u),v(_v),c(_c){}
};
struct DSU{
    int par[M];
    void init(int n){ for(int i = 0;i<n;i++) par[i] = i;}
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool join(int u,int v){
        if( (u = find(u)) == (v = find(v)) ) return false;
        par[v] = u;
        return true;
    }
} dsu;

void kruskal(int a[][M],int n){
    Edge E[M];
    int n_edge = 0;
    bool check[M][M];
    for(int i = 0;i<n;i++){
        memset(check[i],false,sizeof(check[i]));
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j] != 0){
                if(!check[i][j]){
                    E[n_edge++] = Edge(i,j,a[i][j]);
                    check[i][j] = check[j][i] = true;
                }
            }
        }
    }
    dsu.init(n);
    for(int i = 0;i<n_edge - 1;i++){
        for(int j = i + 1;j<n_edge;j++){
            if(E[i].c > E[j].c) swap(E[i],E[j]);
        }
    }
    for(int i = 0;i < n_edge;i++){
        if(!dsu.join(E[i].u,E[i].v)) continue;
        cout << vertex[E[i].u] << " - " << vertex[E[i].v] << " - " << E[i].c << endl;
    }
    cout << endl;
}

void menu(){
    cout << endl << "Chon cac lua chon sau \n";
    cout << "1 . Doc file tu du lieu \n";
    cout << "2 . Xuat ma tran \n";
    cout << "3 . Duyet BFS \n";
    cout << "4 . Kiem tra do thi la vo huong hay co huong \n";
    cout << "5 . In ra so bac cua do thi \n";
    cout << "6 . Cac dinh nam tren duong di tu x den y \n";
    cout << "7 . Prim \n";
    cout << "8 . Kruskal \n";
    cout << "9 . Thoat \n \n";
}
int main(){
    //int n;
    int n,choice;
    do{
        menu();
        cout << "Nhap lua chon : ";cin >> choice;
        while(choice < 1 || choice > 9) { cout << "Nhap lai : ";cin >> choice; }
        if(choice == 9) {break;}
        switch(choice){
            case 1:{
                system("cls");
                readFile(a,n);break;
            }
            case 2:{
                system("cls");
                output(a,n);break;
            }
            case 3:{
                system("cls");
                out_BFS(a,n,0);break;
            }
            case 4:{
                system("cls");
                string y;y = is_direct(a,n) ? "Y" : "N"; cout << y << endl;break;
            }
            case 5:{
                system("cls");
                cout << "Bac cua cac dinh : \n";level_of_vertex(a,n);break;
            }
            case 6:{
                system("cls");
                cout << "Nhap vi tri hai dinh \n";
                for(int i = 0;i<n;i++){
                    cout << "[" << i << "] " << " : " << vertex[i] << "\n";
                }
                int x,y;cin >> x >> y;
                find_Path(a,n,x,y);
                break;
            }
            case 7:{
                system("cls");
                cout << "Prim \n";
                prim(a,n);break;
            }
            case 8:{
                system("cls");
                cout << "Kruskal \n";
                kruskal(a,n);break;
            }
        }
    }while(choice >= 1 && choice <= 9);
    cout << "Bye \n";
    return 0;
}