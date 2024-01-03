#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define M 101
struct Edge{
    int u,v,c;
    Edge () {};
    Edge(int _u,int _v,int _c) : u(_u),v(_v),c(_c){};
};

struct DSU{
    int par[M];
    void init(int n){
        for(int i = 1;i<=n;i++){
            par[i] = i;
        }
    }
    int find(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = find(par[u]);
    }

    bool join(int u,int v){
        if((u = find(u)) == (v = find(v))) return false;
        par[v] = u;
        return true;
    }
} dsu;

int n,m,sum = 0;
Edge edges[M];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1;i<=m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        edges[cnt++] = Edge(u,v,c);
    }
    dsu.init(n);
    sort(edges,edges + cnt,[](const Edge &a,const Edge &b){
        return a.c < b.c;
    });
    cout << endl;
    for(int i = 0;i < cnt;i++){
        if(!dsu.join(edges[i].u,edges[i].v)) continue;
        cout << edges[i].u << " " << edges[i].v << " " << edges[i].c << endl;
        sum+=edges[i].c;
    }
    cout << sum << endl;
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// #define M 101

// struct Edge {
//     int u, v, c;
//     Edge() {}
//     Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
// };

// struct DSU {
//     int par[M];

//     void init(int n) {
//         for (int i = 1; i <= n; i++) {
//             par[i] = i;
//         }
//     }

//     int find(int u) {
//         if (u == par[u]) {
//             return u;
//         }
//         return par[u] = find(par[u]);
//     }

//     bool join(int u, int v) {
//         if ((u = find(u)) == (v = find(v))) return false;
//         par[v] = u;
//         return true;
//     }
// } dsu;

// int n, m, sum = 0;
// Edge edges[M]; // Kích thước của mảng lớn hơn để đảm bảo đủ không gian

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     int cnt = 0;
//     for (int i = 1; i <= m; i++) {
//         int u, v, c;
//         cin >> u >> v >> c;
//         edges[cnt++] = Edge(u, v, c);
//     }

//     dsu.init(n);

//     sort(edges, edges + cnt, [](const Edge &a, const Edge &b) {
//         return a.c < b.c;
//     });

//     for (int i = 0; i < cnt; i++) {
//         if (!dsu.join(edges[i].u, edges[i].v)) continue;
//         cout << edges[i].u << " " << edges[i].v << " " << edges[i].c << endl;
//         sum += edges[i].c;
//     }

//     cout << sum << endl;
//     return 0;
// }
