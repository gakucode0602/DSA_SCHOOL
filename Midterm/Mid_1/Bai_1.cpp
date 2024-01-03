#include<iostream>
#include<limits>
#include<fstream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF INT_MAX
#define M 50
int a[M][M];
bool check[M][M];
bool kruskal_Check[M][M];
int par[M];
char vertex[M] = {'a','b','c','d','e','g','h','k'};
bool C[M];
bool selected[M];
char BFS_Arr[M];
void readFile(int a[][M],int &n){
    ifstream in("Input.txt");
    if(in.is_open()){
        in >> n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                in >> a[i][j];
        }
    }
        cout << "Doc file thanh cong \n";
        in.close();
    }
    else{
        cout << "Error" << endl;
    }
    cout << endl;
}

void output(int a[][M],char vertex[],int n){
    cout << "Ma tran trong so : \n";
    cout << "  ";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << endl;
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int a[][M],char vertex[],int n,int start,int &cnt){
    cnt = 0;
    memset(par,-1,sizeof(par));
    memset(C,false,sizeof(C));
    queue<int> q;
    q.push(start);
    C[start] = true;
    //cout << "BFS : ";
    while(!q.empty()){
        int p = q.front();
        q.pop();
        BFS_Arr[cnt++] = vertex[p];
        for(int i = 0;i<n;i++){
            if(!C[i] && a[p][i] != 0){
                par[i] = p;
                C[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void out_BFS(char BFS_Arr[],int cnt){
    for(int i = 0;i < cnt;i++){
        cout << BFS_Arr[i] << " ";
    }
    cout << endl;
}

bool direct_or_not(int a[][M],int n){
    for(int i = 0;i<n;i++){
        memset(check[i],false,sizeof(check));
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != 0 && check[i][j] == false){
                if(a[i][j] == a[j][i]){
                    check[i][j] = true;
                    check[j][i] = true;
                }
                else {
                    cout << i << " " << j << endl;
                    cout << a[i][j] << " " << a[j][i] << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void Level_of_node(int a[][M],char vertex[],int n){
    cout << "Bac cua do thi \n";
    for(int i = 0;i<n;i++){
        int num = 0;
        for(int j = 0;j<n;j++){
            if(a[i][j]){
                num++;
            }
        }
        cout << "Level of node " << vertex[i] << " : " << num << endl;
    }
    cout << endl;
}

void find_Path(int a[][M],int n,int start,int end){
    int cnt;
    BFS(a,vertex,n,0,cnt);
    if(!C[start] && !C[end]) {
        cout << "No path ! \n";
    }
    else{
        int cnt = 0;
        int path[M];
        for(int v = end;v!=start;v = par[v]){
            path[cnt++] = v;
        }
        path[cnt++] = start;
        reverse(path,path+cnt);
        cout << "So dinh tong cong : " << cnt << endl;
        int i;
        for(i = 0;i<cnt-1;i++){
            cout << vertex[path[i]] << " -> ";
        }
        cout << vertex[path[i]] << endl;
        cout << endl;
    }
}

void prim(int a[][M],char vertex[],int n,int s){
    memset(selected,false,sizeof(selected));
    int no_Edge = 0;
    int x , y;
    selected[s] = true;
    while(no_Edge < n-1){
        int min = INF;
        x = 0;y = 0;
        for(int i = 0;i<n;i++){
            if(selected[i]){
                for(int j = 0;j<n;j++){
                    if(!selected[j] && a[i][j]){
                        if(min > a[i][j]){
                            min = a[i][j];
                            x = i;y = j;
                        }
                    }
                }
            }
        }
        cout << vertex[x] << " " << vertex[y] << " " << a[x][y] << endl;
        selected[y] = true;
        no_Edge++; 
    }
    cout << endl;
}
int E1[M],E2[M],wE[M],nE = 0;
int T1[M],T2[M],wT[M],nT = 0;
bool exist(int d,int D[],int nD){
    for(int i = 0;i<nD;i++){
        if(d == D[i]) return true;
    }
    return false;
}
void createE(int a[][M],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] && kruskal_Check[i][j] == false){
                E1[nE] = i;
                E2[nE] = j;
                wE[nE] = a[i][j];
                nE++;
                //a[i][j] = 0;a[j][i] = 0;
                kruskal_Check[i][j] = true;
                kruskal_Check[i][j] = true;
            }
        }
    }
    for(int i = 0;i<n;i++){
        memset(kruskal_Check[i],false,sizeof(kruskal_Check[i]));
    }
}

void sortE(){
    for(int i = 0;i<nE - 1;i++){
        for(int j = i+1;j < nE;j++){
            if(wE[i] > wE[j]){
                swap(E1[i],E1[j]);
                swap(E2[i],E2[j]);
                swap(wE[i],wE[j]);
            }
        }
    }
}
void Kruskal(int a[][M],char vertex[],int n){
    createE(a,n);
    sortE();
    for(int i = 0;i<nE;i++){
        if(exist(E1[i],T1,nT) && exist(E2[i],T2,nT)) continue;
        if(exist(E1[i],T2,nT) && exist(E2[i],T1,nT)) continue;
        T1[nT] = E1[i];T2[nT] = E2[i];wT[nT] = wE[i];
        cout << vertex[T1[nT]] << "  " << vertex[T2[nT]] << " " << wT[nT] << endl;
        nT++;
        if(nT == n-1) break;
    }
    nE = 0;
    nT = 0;
    cout << endl;
}

void menu(){
    cout << "Nhap cac lua chon sau : " << endl;
    cout << "1 . Doc du lieu tu file \n";
    cout << "2 . Xuat ma tran ra man hinh \n";
    cout << "3 . Duyet BFS \n";
    cout << "4 . Kiem tra do thi co huong hay vo huong \n";
    cout << "5 . So bac cua cac dinh \n";
    cout << "6 . Tim duong di \n";
    cout << "7 . Tim cay khung nho nhat bang Prim \n";
    cout << "8 . Tim cay khung nho nhat bang DFS \n";
    cout << "9 . Thoat \n";
    cout << endl;
}

int main(){
    int n;
    int choice;
    do{
        menu();
        cout << "Nhap lua chon cua ban : ";cin >> choice;
        while(choice < 1 || choice > 10){
            cout << "Nhap lai : ";cin >> choice;
        }
        if(choice == 9){
            break;
        }
        switch(choice){
            case 1:{
                system("cls");
                readFile(a,n);
                break;
            }
            case 2:{
                system("cls");
                output(a,vertex,n);
                break;
            }
            case 3:{
                system("cls");
                int cnt;
                int start = 0;
                BFS(a,vertex,n,start,cnt);
                out_BFS(BFS_Arr,cnt);
                break;
            }
            case 4:{
                system("cls");
                if(direct_or_not(a,n)){
                    cout << "Do thi co huong \n";
                }
                else cout << "Do thi vo huong \n";
                break;
            }
            case 5:{
                system("cls");
                Level_of_node(a,vertex,n);
                break;
            }
            case 6:{
                system("cls");
                int x;
                int y;
                cout << "Nhap dinh ban muon tim duong di : ";cin >> x >> y;
                find_Path(a,n,x,y);
                break;
            }
            case 7:
            {
                system("cls");
                cout << "Prim : \n";
                prim(a,vertex,n,0);
                memset(selected,false,sizeof(selected)); // reset lai gia tri sau moi lan chay lai chuong trinh
                break;
            }
            case 8:
            {
                system("cls");
                // createE(a,n);
                // sortE();
                cout << "Kruskal : \n";
                Kruskal(a,vertex,n); // Ham createE va ham sort duoc cap nhat lai sau moi lan chay chuong trinh
                break;
            }
        }
    }while(choice >= 1 && choice <= 9);
    system("cls");cout << "Good bye \n";
    return 0;
}