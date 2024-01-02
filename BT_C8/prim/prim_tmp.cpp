#include<iostream>
using namespace std;
#define M 101
int a[M][M] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
	{4, 0, 8, 0, 0, 0, 0, 11, 0},
	{0, 8, 0, 7, 0, 4, 3, 0, 4},
	{0, 0, 7, 0, 9, 14, 0, 0, 0},
	{0, 0, 0, 9, 0, 10, 0, 0, 0},
	{0, 0, 4, 14, 10, 0, 2, 0, 0},
	{0, 0, 3, 0, 0, 2, 0, 1, 3},
	{8, 11, 0, 0, 0, 0, 1, 0, 7},
	{0, 0, 4, 0, 0, 0, 3, 7, 0}
};
int n;
/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 3 0 4
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0 
0 0 3 0 0 2 0 1 4
8 11 0 0 0 0 1 0 7
0 0 4 0 0 0 4 7 0
*/

int E1[M];
int E2[M];
int wE[M];
int nE = 0;

// set T
int T1[M];
int T2[M];
int wT[M];
int nT = 0;

void input(){
    //cin >> n1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

bool exist(int d,int D[],int nD){
    for(int i = 0;i<nD;i++){
        if(d == D[i]){ // if the vertices exist in the T2
            return true;
        }
    }
    return false;
}

void deleteAtPos(int i){
    for(int j = i;j < nE;j++){
        E1[j] = E1[j+1];
        E2[j] = E2[j+1];
        wE[j] = wE[j+1];
    }
    nE--;
}

void deleteEdgeE(int u,int v){
    for(int i = 0;i < nE;i++){
        if(E1[i] == u and E2[i] == v){ // finding the edge over the array
            deleteAtPos(i);break;
        }
    }
}

void prim(int s){
    int u = s,min,d1,d2,i;
    while(nT < n-1){
        for(int v = 0;v < n;v++){
            if(a[u][v] != 0){
                if(!exist(E2[i],T2,nT)){
                    E1[nE] = u;E2[nE] = v;
                    wE[nE] = a[u][v];nE++;
                }
            }
        }
        for(i = 0;i<nE;i++){
            if(!exist(!E2[i],T2,nT)){
                min = wE[i];
                d1 = E1[i];
                d2 = E2[i];
                break;
            }
        }
        for(;i<nE;i++){
            if(!exist(E2[i],T2,nT)){
                if(min > wE[i]){
                    min = wE[i];
                    d1 = E1[i];
                    d2 = E2[i];
                }
            }
        }
        T1[nT] = d1;
        T2[nT] = d2;
        wT[nT] = min;
        nT++;
        a[d1][d2] = 0;a[d2][d1] = 0;
        deleteEdgeE(d1,d2);
        u = d2;
    }
}

void output(){
    int sum = 0;
    for(int i = 0;i<nT;i++){
        cout << endl << "( " << T1[i] << " , " << T2[i] << " ) = " << wT[i];
        sum += wT[i];
    }
    cout << endl;
    cout << "Sum = " << sum << endl;
}

int main(){
    cin >> n;
    //input();
    prim(0);
    output();
    return 0;
}