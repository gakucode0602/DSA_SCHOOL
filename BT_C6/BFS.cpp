#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define M 100
int a[M][M];
int vertex[M];
/*
7
0 1 1 1 0 0 0
1 0 1 0 1 1 0
1 1 0 1 0 1 0
1 0 1 0 0 1 1
0 1 0 0 0 1 0
0 1 1 1 1 0 1
0 0 0 1 0 1 0
*/
struct node{
    int val;
    node* next;
    // node() : val(0),next(nullptr){}
    // node(int x) : val(x),next(nullptr){}
};
typedef node* qu;
//qu Queue;
void init(qu &Queue){
    Queue = NULL;
}
void push(qu &Queue,int x){
    qu ins = new node;
    ins->val = x;
    ins->next = NULL;
    if(Queue == NULL) 
    {
        Queue = ins;
    }
    else{
        qu p = Queue;
        while(p->next){
            p = p->next;
        }
        p->next = ins;
    }
}
void pop(qu &Queue){
    qu tmp = Queue;
    Queue = Queue->next;
    delete tmp;
    //return x;
}
bool empty(qu Queue){
    if(Queue == NULL) { return true; }
    return false;
}
int front(qu Queue){
    return Queue->val;
}

void input(int a[][M],int vertex[],int &n){
    //cout << "Input number of vertex : \n";
    cin >> n;
    for(int i = 0;i<n;i++){
        vertex[i] = i+1;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
        }
    }
}
void output(int a[][M],int vertex[],int n){
    cout << "  ";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << '\n';
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
void bfs(int a[][M],int vertex[],int n,int x){
    qu Q;init(Q);
    bool check[M];
    memset(check,false,sizeof(check));
    push(Q,x);
    check[x] = true;
    while(empty(Q) ==  false){
        int p = front(Q);
        pop(Q);
        cout << vertex[p] << " "; 
        for(int i = 0;i<n;i++){
            if(check[i] == false && a[p][i] == 1){
                check[i] = true;
                push(Q,i);
            }
        }
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false) ; 
    cin.tie(nullptr);
    int n;
    input(a,vertex,n);
    output(a,vertex,n);
    cout << "bfs : ";bfs(a,vertex,n,0);
    return 0;
}