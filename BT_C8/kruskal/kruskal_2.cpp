// #include<iostream>
// using namespace std;

// #define M 100
// int a[M][M];

// //
// int E1[M];
// int E2[M];
// int wE[M];
// int nE = 0;
// //
// int T1[M];
// int T2[M];
// int wT[M];
// int nT = 0;
// bool exist(int d,int D[],int nD){
//     for(int i = 0;i<nD;i++){
//         if(d == D[i]) return true;
//     }
//     return false;
// }

// void createE(int a[][M],int n){
//     for(int i = 0;i<n;i++){
//        for(int j = 0;j<n;j++){
//         if(a[i][j]!=0){
//             E1[nE] = i;
//             E2[nE] = j;
//             wE[nE] = a[i][j];
//             a[i][j] = 0;a[j][i] = 0;
//             nE++; 
//         }
//        } 
//     }
// }

// void sortE(int a[][M],int n){
//     for(int i = 0;i<nE-1;i++){
//         for(int j = i + 1;j<nE;j++){
//             if(wE[i] > wE[j]){
//                 swap(E1[i],E1[j]);
//                 swap(E2[i],E2[j]);
//                 swap(wE[i],wE[j]);
//             }
//         }
//     }
// }

// void kruskal(int a[][M],int n){
//     int sum = 0;
//     for(int i = 0;i<n;i++){
//         if(exist(E1[i],T1,nT) && exist(E2[i],T2,nT)) continue;
//         if(exist(E1[i],T2,nT) && exist(E2[i],T1,nT)) continue;
//         T1[nT] = E1[i];
//         T2[nT] = E2[i];
//         wT[i] = wE[i];
//         cout << T1[nT] << " - " << T2[nT] << " - " << wT[nT] << endl; 
//         sum+=wT[i];
//         nT++;
//         if(nT == n-1) break;
//     }
//     cout << "Sum = " << sum << endl;
// }

// int main(){
//     int n;cin >> n;
//     int a[M][M] = {
// 	    {0, 4, 0, 0, 0, 0, 0, 8, 0},
// 	    {4, 0, 8, 0, 0, 0, 0, 11, 0},
// 	    {0, 8, 0, 7, 0, 4, 3, 0, 4},
// 	    {0, 0, 7, 0, 9, 14, 0, 0, 0},
// 	    {0, 0, 0, 9, 0, 10, 0, 0, 0},
// 	    {0, 0, 4, 14, 10, 0, 2, 0, 0},
// 	    {0, 0, 3, 0, 0, 2, 0, 1, 3},
// 	    {8, 11, 0, 0, 0, 0, 1, 0, 7},
// 	    {0, 0, 4, 0, 0, 0, 3, 7, 0}};
//     createE(a,n);
//     sortE(a,n);
//     kruskal(a,n);
//     return 0;
// }

#include<iostream>
#include<limits>
#include<cstring>
using namespace std;
#define INF INT_MAX
#define M 100

int E1[M],E2[M],wE[M],nE = 0;
int T1[M],T2[M],wT[M],nT = 0;

bool exist(int d,int D[],int nD){
    for(int i = 0;i<nD;i++){
        if(d == D[i]){
            return true;
        }
    }
    return false;
}

void createE(int a[][M],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j < n;j++){
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

void sortE(int a[][M],int n){
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

void kruskal(int a[][M],int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(exist(E1[i],T1,nT) && exist(E2[i],T2,nT)) continue;
        if(exist(E1[i],T2,nT) && exist(E2[i],T1,nT)) continue;
        T1[nT] = E1[i];
        T2[nT] = E2[i];
        wT[nT] = wE[i];
        cout << T1[nT] << " - " << T2[nT] << " - " << wT[nT] << endl;
        sum += wT[nT];
        nT++;
        if(nT == n-1) break;
    }
    cout << sum << endl;
}

int main(){
        int n;cin >> n;
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
    createE(a,n);
    sortE(a,n);
    kruskal(a,n);
    return 0;
}
