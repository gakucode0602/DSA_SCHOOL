#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
using namespace std;
#define M 101
#define INF 999999
char vertex[M] = {'a','b','c','d','e','f','g','h','i'};
int level[M];
struct node{
    int u,v;
    node *next;
};
typedef node* nd;
nd a[M];
void init(nd a[],int n){
    for(int i = 0;i<n;i++){
        a[i] = NULL;
    }
}

void insert(nd &a,int x,int y){
    nd ins = new node;
    ins->u = x;
    ins->v = y;
    ins->next = NULL;
    if(!a) a = ins;
    else{
        nd p = a;
        while(p->next){
            p = p->next;
        }
        p->next = ins;
    }
}

void readfile(nd a[],int &n){
    ifstream in("Input_2.txt");
    if(in.is_open()){
        in >> n;
        init(a,n);
        for(int i = 0;i<n;i++){
            in >> level[i];
        }
        for(int i = 0;i<n;i++){
            int cnt = level[i];
            while(cnt--){
                int x,y;
                in >> x;
                in >> y;
                insert(a[i],x,y);
            }
        }
        cout << "Succes \n";
        in.close();
    }
    else cout << "Error \n"; 
}

void out_List(nd a){
    if(a){
        nd p = a;
        while(p){
            cout << "(" << p->u << " , " << p->v << ") ";
            p = p->next;
        }
    }
}

void output(nd a[],int n){
    for(int i = 0;i<n;i++){
        out_List(a[i]);
        cout << "\n";
    }
}
char DFS_arr[M];
int n_dfs = 0;
void DFS(nd a[],int n){
    int start = 0;
    bool C[M];
    memset(C,false,sizeof(C));
    DFS_arr[n_dfs++] = vertex[start];
    C[start] = true;
    stack<int> s;
    s.push(start);
    nd u = a[start];
    while(!s.empty()){
        if(!u){
            int p = s.top();
            u = a[p];
            s.pop();
        }
        while(u){
            if(!C[u->u]){
                C[u->u] = true;
                s.push(u->u);
                DFS_arr[n_dfs++] = vertex[u->u];
                u = a[u->u];
            }
            u = u->next;
        }
    }
}

void out_DFS(nd a[],int n){
    DFS(a,n);
    for(int i = 0;i<n_dfs;i++){
        cout << DFS_arr[i] << " ";
    }
    cout << endl;
}

void level_Of_Node(int n){
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " : " << level[i] << endl;
    }
    cout << endl;
}

bool C[M];
char path[M];
int n_path = 0;
bool find_Path(nd a[],int n,int start,int end){
    C[start] = true;
    path[n_path++] = vertex[start];
    if(start == end){
        for(int i = 0;i<n_path-1;i++){
            cout << path[i] << " -> ";
        }
        cout << path[n_path-1] << endl;
        return true;
    }
    nd p = a[start];
    while(p){
        if(!C[p->u]){
            find_Path(a,n,p->u,end);
        }
        p = p->next;
    }
    return false;
}

void prim(nd a[],int n){
    int no_edge = 0;
    int sum = 0;
    bool C[M];
    memset(C,false,sizeof(C));
    C[0] = true;
    int i = 0;
    while(no_edge < n-1){
        int min = INF;
        int x = 0,y = 0;
        for(int i = 0;i<n;i++){
            if(C[i]){
                nd p = a[i];
                while(p){
                    if(!C[p->u]){
                        if(min > p->v){
                            min = p->v;
                            x = i;
                            y = p->u;
                        }
                    }
                    p = p->next;
                }
            }
        }
        cout << vertex[x] << " " << vertex[y] << " " << min << endl;
        C[y] = true;
        sum+=min;
        no_edge++;
    }
    cout << sum << endl;
}

struct Edge{
    int u,v,c;
    Edge() {}
    Edge(int _u,int _v,int _c) : u(_u),v(_v),c(_c){}
};

struct DSU{
    int par[M];
    void init(int n){
        for(int i = 0;i<n;i++) par[i] = i;
    }

    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool join(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

void kruskal(nd a[],int n){
    Edge E[M];
    int cnt_e = 0;
    bool check[M][M];
    for(int i = 0;i<n;i++){ memset(check[i],false,sizeof(check[i])); }
    for(int i = 0;i<n;i++){
        nd p = a[i];
        while(p){
            if(!check[i][p->u]){
                E[cnt_e++] = Edge(i,p->u,p->v);
                check[i][p->u] = true;
                check[p->u][i] = true;
            }
            p = p->next;
        }
    }
    for(int i = 0;i<cnt_e - 1;i++){
        for(int j = i+1;j<cnt_e;j++){
            if(E[i].c > E[j].c){
                swap(E[i],E[j]);
            }
        }
    }
    int sum = 0;
    dsu.init(n);
    for(int i = 0;i<cnt_e;i++){
        if(!dsu.join(E[i].u,E[i].v)) continue;
        cout << vertex[E[i].u] << " " << vertex[E[i].v] << " " << E[i].c << endl;
        sum+=E[i].c;
    }
    cout << sum << endl;
}

void menu(){
    cout << endl;
    cout << "1 . Doc du lieu tu file \n";
    cout << "2 . Xuat do thi duoi dang danh sach \n";
    cout << "3 . Duyet DFS \n";
    cout << "4 . Xuat bac cua dinh \n";
    cout << "5 . Tim duong di \n";
    cout << "6 . Tim cay khung nho nhat bang Prim \n";
    cout << "7 . Tim cay khung nho nhat bang kruskal \n";
    cout << "8 . Thoat \n";
    cout << endl;
}

int main(){
    system("cls");
    int n,choice;
    do{
        menu();
        cout << "Nhap lua chon : ";cin >> choice;
        while(choice < 1 || choice > 8){
            cout << "Nhap lai : ";cin >> choice;
        } 
        if(choice == 8) break;
        switch (choice)
        {
            case 1:{
                system("cls");
                readfile(a,n);
                break;
            }
            case 2:{
                system("cls");
                output(a,n);
                break;
            }
            case 3:{
                system("cls");
                cout << "DFS : ";
                out_DFS(a,n);
                break;
            }
            case 4:{
                system("cls");
                cout << "Bac cua do thi : \n";
                level_Of_Node(n);
                break;
            }
            case 5:{
                system("cls");
                cout << "Nhap index cua dinh : \n";
                for(int i = 0;i<n;i++){
                    cout << vertex[i] << " : [" << i << "] \n";
                }
                int start,end;cin >> start >> end;
                find_Path(a,n,start,end);
                break;
            }
            case 6:{
                system("cls");
                cout << "Prim \n";prim(a,n);
                break;
            }
            case 7:{
                system("cls");
                cout << "Kruskal : \n";kruskal(a,n);
                break;
            }
        }
    }while(choice >= 1 && choice <= 8);
    cout << "bye \n";
    return 0;
}
