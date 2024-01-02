// #include<iostream>
// #include<limits.h>
// #include<cstring>
// using namespace std;
// #define INF INT_MAX
// #define M 100
// //int n;

// void prim(int graph[][M],int n){
//     int no_edge;
//     int sum = 0;
//     int selected[M];
//     memset(selected,false,sizeof(selected));
//     no_edge = 0;
//     selected[0] = true;
//     int x,y;
//     cout << "Edge" << " : " << "Weight";
//     cout << endl;
//     while(no_edge < n-1){
//         int min = INF;
//         x = 0;
//         y = 0;
//         for(int i = 0;i<n;i++){
//             if(selected[i]){
//                 for(int j = 0;j < n;j++){
//                     if(!selected[j] and graph[i][j]){
//                         if(min > graph[i][j]){
//                             min = graph[i][j];
//                             x = i;
//                             y = j;
//                         }
//                     }
//                 }
//             }
//         }
//         cout << x << " - " << y << " : " << graph[x][y];
//         sum += graph[x][y];
//         cout << endl;
//         selected[y] = true;
//         no_edge++;
//     }
//     cout << sum << endl;
// }

// int main(){
//     int n;cin >> n;
//     int G[M][M] = {
// 	{0, 4, 0, 0, 0, 0, 0, 8, 0},
// 	{4, 0, 8, 0, 0, 0, 0, 11, 0},
// 	{0, 8, 0, 7, 0, 4, 3, 0, 4},
// 	{0, 0, 7, 0, 9, 14, 0, 0, 0},
// 	{0, 0, 0, 9, 0, 10, 0, 0, 0},
// 	{0, 0, 4, 14, 10, 0, 2, 0, 0},
// 	{0, 0, 3, 0, 0, 2, 0, 1, 3},
// 	{8, 11, 0, 0, 0, 0, 1, 0, 7},
// 	{0, 0, 4, 0, 0, 0, 3, 7, 0}
// };
//     prim(G,n);
//     return 0;
// }

#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
#define INF INT_MAX
#define M 100

void prim(int a[][M],int n,int strt){
    int no_edge = 0;
    bool selected[M];
    memset(selected,false,sizeof(selected));
    int x,y,sum = 0;
    selected[strt] = true;
    while(no_edge < n-1){
        int min = INF;
        int x = 0;
        int y = 0;
        for(int i = 0;i<n;i++){
            if(selected[i]){
                for(int j = 0;j<n;j++){
                    if(!selected[j] && a[i][j]){
                        if(min > a[i][j]){
                            min = a[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " - " << a[x][y] << endl;
        sum+=a[x][y];
        selected[y] = true;
        no_edge++;
    }
    cout << sum << endl;
}

void prim_2(int a[][M],int n,int strt){
    int no_edge = 0;
    bool C[M];
    memset(C,false,sizeof(C));
    C[strt] = true;
    int x,y,sum = 0;
    while(no_edge < n-1){
        int min = INF;
        x = 0;y = 0;
        for(int i = 0;i<n;i++){
            if(C[i]){
                for(int j = 0;j < n;j++){
                    if(!C[j] && a[i][j]){
                        if(min > a[i][j]){
                            min = a[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << "Edge ( " << x << " , " << y << " )" << " : " << a[x][y] << endl;
        sum+=a[x][y];
        C[y] = true;
        no_edge++; 
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
    int strt;cin >> strt;
    prim(a,n,strt);
    return 0;
}