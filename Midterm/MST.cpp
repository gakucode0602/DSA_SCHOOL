#include<iostream>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
#define M 101
#define INF 9999999
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

void prim(int a[][M],int vertex[],int n){
    int no_edge = 0;
    int sum = 0;
    bool C[M];
    memset(C,false,sizeof(C));
    C[0] = true;
    while(no_edge < n-1){
        int x = 0,y = 0,min = INF;
        for(int i = 0;i < n;i++){
            if(C[i]){
                for(int j = 0;j<n;j++){
                    if(!C[j] && a[i][j] != 0){
                        if(min > a[i][j]){
                            x = i;
                            y = j;
                            min = a[i][j];
                        }
                    }
                }
            }
        }
        cout << vertex[x] << " - " << vertex[y] << " - " << a[x][y] << endl;
        sum+=a[x][y];
        C[y] = true;
        no_edge++;
    }
    cout << "Tong : " << sum << endl;
}

int E1[M],E2[M],wE[M],nE = 0;
int T1[M],T2[M],wT[M],nT = 0;

void create(int a[][M],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i][j] != 0){
            E1[nE] = i;
            E2[nE] = j;
            wE[nE] = a[i][j];
            a[i][j] = 0;a[j][i] = 0;
            nE++;
            }
        }
    }
}

void sortE(int wE[],int nE){
    for(int i = 0;i<nE-1;i++){
        for(int j = i+1;j<nE;j++){
            if(wE[i] > wE[j]){
                swap(E1[i],E1[j]);
                swap(E2[i],E2[j]);
                swap(wE[i],wE[j]);
            }
        }
    }
}

bool exist(int d,int D[],int nD){
    for(int i = 0;i<nD;i++){
        if(d == D[i]) return true;
    }
    return false;
}



void kruskal(int a[][M],int vertex[],int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(exist(E1[i],T1,nT) && exist(E2[i],T2,nT)) continue;
        if(exist(E1[i],T2,nT) && exist(E2[i],T1,nT)) continue;
        T1[nT] = E1[i];T2[nT] = E2[i];wT[nT] = wE[i];sum += wT[nT];
        cout << vertex[T1[nT]] << " - " << vertex[T2[nT]] << " - " << wT[nT] << endl; nT++;
        if(nT == n-1) break;
    }
    cout << sum << endl;
}

int main(){
    int n;cin >> n;
    for(int i = 0;i<n;i++){
        vertex[i] = i+1;
    }
    int a[M][M] = {
	{0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 3, 0, 4},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 3, 0, 0, 2, 0, 1, 3},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 4, 0, 0, 0, 3, 7, 0}};
    prim(a,vertex,n);
    cout << "\n";
    create(a,n);
    sortE(wE,nE);
    kruskal(a,vertex,n);
    return 0;
}