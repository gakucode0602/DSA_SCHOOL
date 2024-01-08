#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define M 101
char vertex[M] = {'a','b','c','d','e','f','g','h','i'};
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
    for(int i = 0;i<cnt - 1;i++){
        for(int j = i + 1;j < cnt;j++){
            if(edges[i].c > edges[j].c){
                swap(edges[i],edges[j]);
            }
        }
    }

    cout << endl;
    for(int i = 0;i < cnt;i++){
        if(!dsu.join(edges[i].u,edges[i].v)) continue;
        cout << vertex[edges[i].u - 1] << " " << vertex[edges[i].v  - 1] << " " << edges[i].c << endl;
        sum+=edges[i].c;
    }
    cout << sum << endl;
    return 0;
}