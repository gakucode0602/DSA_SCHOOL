// #include<iostream>
// #include<limits>
// #include<cstring>
// using namespace std;
// #define INF INT_MAX
// #define M 100

// int E1[M],E2[M],wE[M],nE = 0;
// int T1[M],T2[M],wT[M],nT = 0;

// bool exist(int d,int D[],int nD){
//     for(int i = 0;i<nD;i++){
//         if(d == D[i]){
//             return true;
//         }
//     }
//     return false;
// }

// void createE(int a[][M],int n){
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j < n;j++){
//             if(a[i][j] != 0){
//                 E1[nE] = i;
//                 E2[nE] = j;
//                 wE[nE] = a[i][j];
//                 a[i][j] = 0;a[j][i] = 0;
//                 nE++;
//             }
//         }
//     }
// }

// void sortE(){
//     for(int i = 0;i<nE-1;i++){
//         for(int j = i+1;j<nE;j++){
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
//         wT[nT] = wE[i];
//         cout << T1[nT] << " - " << T2[nT] << " - " << wT[nT] << endl;
//         sum += wT[nT];
//         nT++;
//         if(nT == n-1) break;
//     }
//     cout << sum << endl;
// }

// int main(){
//     int n = 9;
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
//     sortE();
//     kruskal(a,n);
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

vector<int> par;

void init(int n) {
    par.resize(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int u) {
    if (par[u] == u) {
        return u;
    }
    return par[u] = find(par[u]);
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    // Gộp hai nhóm nếu chúng không thuộc cùng một nhóm
    if (rootU != rootV) {
        par[rootU] = rootV;
    }
}

int main() {
    int n = 6; // Số lượng phần tử
    init(n);

    // Hợp các nhóm
    unite(1, 2);
    unite(2, 3);
    unite(4, 5);

    // In ra phần tử cha của từng phần tử
    for (int i = 1; i <= n; i++) {
        cout << "Parent of " << i << ": " << find(i) << endl;
    }

    return 0;
}
