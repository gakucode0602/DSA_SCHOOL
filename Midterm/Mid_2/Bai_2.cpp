#include<iostream>
#include<cstring>
#include<queue>
#include<fstream>
#include<stack>
using namespace std;
#define M 50
struct Node{
    int vertex,weight;
    Node* next;
};
typedef Node* nd;
nd list_node[M];
char DFS_ARR[M];
int parent[M];
int cnt_par = 0;
char vertex[M] = {'A','B','C','D','E','F','G','H','I'};
void init(nd list_node[]){
    for(int i = 0;i<M;i++){
        list_node[i] = NULL;
    }
}

void insertNode(nd &a,int u,int v){
    nd ins = new Node;
    ins->vertex = u;
    ins->weight = v;
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

void readFile(nd list_node[],int &n){
    ifstream in("Input.txt");
    if(in.is_open()){
        in >> n;
        int i,u,v;
        while(in >> i >> u >> v){
            insertNode(list_node[i],u,v);
            insertNode(list_node[u],i,v);
        }
        cout << "Thanh cong \n";
        in.close();
    }
    else cout << "Error" << endl;
}

void outlist_node(nd a){
    if(a){
        nd p = a;
        while(p){
            cout << vertex[p->vertex] << "," << p->weight << "  ";
            p = p->next;
        }
    }
    cout << endl;
}

void output(nd list_node[],int n){
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " : ";outlist_node(list_node[i]);
    }
    cout << endl;
}
int cnt_dfs = 0;
void DFS(nd a[],int n,bool C[M],int start){
    C[start] = true;
    DFS_ARR[cnt_dfs++] = vertex[start];
    nd p = a[start];
    while(p){
        if(!C[p->vertex]){
            parent[p->vertex] = start;
            DFS(a,n,C,p->vertex);
        }
        p = p->next;
    }
}

void out_DFS(char DFS_ARR[]){
    for(int i = 0;i<cnt_dfs;i++){
        cout << DFS_ARR[i] <<  " ";
    }
    cout << endl;
}

void LevelOfNode(nd a[],int n){
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " : ";
        nd p = a[i];
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        } 
        cout << cnt << endl;
    }
}

void find_Path(nd a[],int n,int start,int end){
    bool C[M];memset(C,false,sizeof(C));
    memset(parent,-1,sizeof(parent));
    DFS(a,n,C,0);
    if(!C[end]) cout << "No path \n";
    else{
        int cnt = 0;
        char path[M];
        for(int v = end;v!=start;v = parent[v]){
            path[cnt++] = vertex[v];
        }
        cout << "Path : " << vertex[start] << " -> ";
        for(int i = cnt-1;i >= 1;i--){
            cout << path[i] << " -> ";
        }
        cout << path[0] << endl;
        cout << "Number of vertex : " << cnt + 1 << endl;
    }
}

void prim(nd a[],int n){
    bool C[M];
    memset(C,false,sizeof(C));
    int no_Edge = 0;
    C[0] = true;
    int x,y;
    while(no_Edge < n-1){
        int min = 9999;
        x = 0;y = 0;
        for(int i = 0;i<n;i++){
            if(C[i]){
                nd p = a[i];
                while(p){
                    if(!C[p->vertex]){
                        if(min > p->weight){
                            min = p->weight;
                            x = i;
                            y = p->vertex;
                            min = p->weight;
                        }
                    }
                    p = p->next;
                }
            }
        }
        cout << x << " - " << y << " - " << min << endl;
        C[y] = true;
        no_Edge++;
    }
}

int E1[M],E2[M],wE[M],nE = 0;
int T1[M],T2[M],wT[M],nT = 0;

void createE(nd a[],int n){
    bool kruskal_check[M][M];
    memset(kruskal_check,false,sizeof(kruskal_check));
    for(int i = 0;i<n;i++){
        nd p = a[i];
        while(p){
            if(!kruskal_check[i][p->vertex]){
                E1[nE] = i;
                E2[nE] = p->vertex;
                wE[nE] = p->weight;
                kruskal_check[i][p->vertex] = true;
                kruskal_check[p->vertex][i] = true;
                nE++;
            }
            p = p->next;
        }
    }
}

void sortE(){
    for(int i = 0;i<nE-1;i++){
        for(int j = i+1;j < nE;j++){
            if(wE[i] > wE[j]){
                swap(E1[i],E1[j]);swap(E2[i],E2[j]);swap(wE[i],wE[j]);
            }
        }
    }
}

bool exist(int d,int D[],int nD){
    for(int i = 0;i<nD;i++){
        if(d == nD){
            return true;
        }
    }
    return false;
}

void kruskal(nd a[],int n){
    int no_Edge = 0;
    createE(a,n);
    sortE();
    for(int i = 0;i<nE;i++){
        if(exist(E1[i],T1,nT) && exist(E2[i],T2,nT)) continue;
        if(exist(E1[i],T2,nT) && exist(E2[i],T1,nT)) continue;
        T1[nT] = E1[i];T2[nT] = E2[i];wT[nT] = wE[i];
        cout << vertex[T1[nT]] << " " << vertex[T2[nT]] << " " << wT[nT] << endl;
        nT++;
        if(nT == n) break;
    }
}

void menu(){
    cout << "\n";
    cout << "Chon chuong trinh sau day \n";
    cout << "1 . Doc file tu du lieu \n";
    cout << "2 . Xuat thong tin \n";
    cout << "3 . Duyet DFS \n";
    cout << "4 . Tim duong di \n";
    cout << "5 . Bac cua cac dinh \n";
    cout << "6 . Tim duong di bang giai thuat Prim \n";
    cout << "7 . Tim duong di bang giai thuat Prim \n";
    cout << "8 . Thoat\n";
    cout << "\n";
}

int main(){
    int n,m,cnt_dfs,choice;
    do
    {
        menu();
        cout << "Nhap lua chon cua ban : ";cin >> choice;
        while(choice < 1 || choice > 8){
            cout << "Nhap lai : ";cin >> choice;
        }
        if(choice == 8) break;
        switch (choice)
        {
        case 1:{
            system("cls");
            init(list_node);
            readFile(list_node,n);
            break;
        }
        case 2:{
            system("cls");
            cout << "Thong tin do thi \n";
            output(list_node,n);
            break;
        }
        case 3:{
            system("cls");
            bool C[M];
            memset(C,false,sizeof(C));
            int start = 0;
            DFS(list_node,n,C,start);
            out_DFS(DFS_ARR);
            break;
        }
        case 4:{
            system("cls");
            int start,end;
            cout << "Nhap vao dinh ban muon tim duong di : ";cin >> start >> end;
            find_Path(list_node,n,start,end);
            break;
        }
        case 5:{
            system("cls");
            cout << "Bac cua cac dinh : \n";
            LevelOfNode(list_node,n);
            break;
        }
        case 6:{
            system("cls");
            cout << "Prim : \n";prim(list_node,n);cout << "\n";break;
        }
        case 7:{
            system("cls");
            cout << "Kruskal : \n";kruskal(list_node,n);break;
        }
        }
    } while (choice >= 1 && choice <= 8);
    cout << "Done \n";
    return 0;
}