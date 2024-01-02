#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define M 101
int a[M][M];
int vertex[M];
void input(int a[][M],int vertex[],int &n){
    cin >> n;
    cout << "Nhap cac dinh cua do thi \n";
    for(int i = 0;i<n;i++){
        cin >> vertex[i];
    }
    for(int i = 0;i<n;i++){
        cout << "Dinh " << vertex[i] << " : ";
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void inputFile(int a[][M],int vertex[],int &n){
    ifstream in("text.txt");
    if(in.is_open()){
        in >> n;
        for(int i = 0;i<n;i++){
            in >> vertex[i];
            in.ignore();
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                in >> a[i][j];
                in.ignore();
            }
        }
        in.close();
    }
    else cout << "Error \n"; 
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
        cout << "\n";
    }
}

struct node{
    int val;
    node* next;
};
typedef node* nd;
void init(nd& a){
    a = NULL;
}

void push_Queue(nd &a,int x){
    nd ins = new node;
    ins->val = x;
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

void pop_Queue(nd &a){
    if(a){
        nd p = a;
        a = a->next;
        delete p;
    }
}

int front(nd a){
    return a->val;
}

bool empty(nd a){
    if(!a) return true;
    return false;
}

void BFS(int a[][M],int vertex[],int n,int x){
    nd q;init(q);
    bool C[M];
    memset(C,false,sizeof(C));
    C[x] = true;
    push_Queue(q,x);
    while(!empty(q)){
        int p = front(q);
        pop_Queue(q);
        cout << vertex[p] << " ";
        for(int i = 0;i < n;i++){
            if(!C[i] && a[p][i] == 1){
                C[i] = true;
                push_Queue(q,i);
            }
        }
    }
    cout << '\n';
}

void push_Stack(nd &a,int x){
    nd ins = new node;
    ins->val = x;
    ins->next = a;
    a = ins;
}

void pop_Stack(nd &a){
    if(a){
        nd p = a;
        a = a->next;
        delete p;
    }
}

int top(nd a){
    return a->val;
}

void DFS(int a[][M],int vertex[],int n,int x){
    nd q;init(q);
    bool C[M];
    memset(C,false,sizeof(C));
    cout << vertex[x] << " ";
    C[x] = true;
    push_Stack(q,x);
    int w = -1,u = x;
    while(!empty(q)){
        if(w == n){
            u = top(q);
            pop_Stack(q);
        }
        for(w = 0;w < n;w++){
            if(!C[w] && a[u][w]!=0){
                push_Stack(q,w);
                cout << vertex[w] << " ";
                C[w] = true;
                u = w;
                break;
            }
        }
    }
    cout << endl;
}

int main(){
    int n;
    inputFile(a,vertex,n);
    output(a,vertex,n);
    cout << "BFS : ";BFS(a,vertex,n,0);
    cout << "DFS : ";DFS(a,vertex,n,0);
    return 0;
}