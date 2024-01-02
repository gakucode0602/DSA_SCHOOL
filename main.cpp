#include<iostream>
#include<fstream>
#include<algorithm>
#include<random>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

// Define maximum limit for the array
#define M 100
int a[M][M];
int vertex[M];
void heapify(int a[],int n,int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if(l < n && a[largest] < a[l]){
        largest = l;
    }
    if(r < n && a[largest] < a[r]){
        largest = r;
    }
    if(largest != i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n){
    for(int i = n/2 - 1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i = n - 1;i > 0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void counting_sort_desc(int a[],int b[],int n){
    int max_num = a[0];
    for(int i = 1;i < n;i++){
        max_num = max(max_num,a[i]);
    }
    int cnt[M] = { 0 };
    for(int i = 0;i < n;i++){
        cnt[a[i]]++;
    }
    for(int i = max_num; i >= 1;i--){
        cnt[i-1] += cnt[i];
    }
    for(int i = n-1;i >= 0 ;i--){
        b[cnt[a[i]] - 1] = a[i];
        cnt[a[i]]--;
    }
}

void counting_sort_asc(int a[],int b[],int n){
    // find max
    int max_num = a[0];
    for(int i = 1;i<n;i++){ max_num = max(max_num,a[i]); }
    
    // set up the counting array
    int cnt[M] = { 0 };
    for(int i = 0;i<n;i++){ cnt[a[i]]++; }
    
    int idx = 0;
    for(int i = 1;i <= max_num;i++){ cnt[i]+=cnt[i-1]; }
    
    for(int i = n - 1;i >= 0;i--){
        b[cnt[a[i]] - 1] = a[i];
        cnt[a[i]]--;
    }
}

void input(int a[][M],int vertex[],int &n){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> vertex[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

void output(int a[][M],int vertex[],int n){
    cout <<  "    ";
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " ";
    }
    cout << endl;
    for(int i = 0;i<n;i++){
        cout << vertex[i] << " : ";
        for(int j = 0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS_Q(int a[][M],int vertex[],int n,int x){
    queue<int> q;
    bool C[M];
    memset(C,false,sizeof(C));
    q.push(x);
    C[x] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout << vertex[p] << " ";
        for(int i = 0;i<n;i++){
            if(!C[i] && a[p][i] == 1){
                q.push(i);
                C[i] = true;
            }
        }
    }
    cout << endl;
}

struct Node{
    int val;
    Node* next;
};
typedef Node* nd;

void init(nd &a){ a = NULL; }

void push(nd &a,int x){
    nd ins = new Node();
    ins->val = x;
    ins->next = NULL;
    if(!a) a = ins;
    else{
        ins->next = a;
        a = ins;
    }
}

void pop(nd &a){
    nd p = a;
    a = a->next;
    delete p;
}

int front(nd a){
    return a->val;
}

int top(nd a){
    return a->val;
}

bool empty(nd a){
    if(!a) return true;
    return false;
}

void BFS_LL(int a[][M],int vertex[],int n,int x){
    nd q;init(q);
    bool C[M];
    memset(C,false,sizeof(C));
    push(q,x);
    C[x] = true;
    while(!empty(q)){
        int p = front(q);
        pop(q);
        cout << vertex[p] << " ";
        for(int i = 0;i<n;i++){
            if(!C[i] && a[p][i] == 1){
                C[i] = true;
                push(q,i);
            }
        }
    }
    cout << endl;
}

void DFS_S(int a[][M],int vertex[],int n,int x){
    stack<int> s;
    bool C[M];
    memset(C,false,sizeof(C));
    cout << vertex[x] << " ";
    C[x] = true;
    s.push(x);
    int w = -1,u = x;
    while(!s.empty()){
        if(w == n){
            u = s.top();
            s.pop();
        }
        for(w = 0;w < n;w++){
            if(!C[w] && a[u][w] != 0){
                s.push(w);
                cout << vertex[w] << " ";
                C[w] = true;
                u = w;
                break;
            }
        }
    }
}

void DFS_LL(int a[][M],int vertex[],int n,int x){
    nd s;init(s);
    bool C[M];
    memset(C,false,sizeof(C));
    cout << vertex[x] << " ";
    C[x] = true;
    push(s,x);
    int w = -1,u = x;
    while(!empty(s)){
        if(w == n){
            u = top(s);
            pop(s);
        }
        for(w = 0;w < n;w++){
            if(!C[w] && a[u][w] != 0){
                push(s,w);
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
    input(a,vertex,n);
    output(a,vertex,n);
    cout << "DFS : ";DFS_LL(a,vertex,n,0);
    return 0;
}