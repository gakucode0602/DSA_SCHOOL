#include <iostream>
#include<vector>
using namespace std;
#define M 20
struct item
{
    int val;
    int next;
};

struct hashTable
{
    item h[M];
    int r;
};

int hashFunc(int x)
{
    return x % M;
}

void init(hashTable &t)
{
    for (int i = 0; i < M; i++)
    {
        t.h[i].val = -1;
        t.h[i].next = -1;
    }
    t.r = M - 1;
}

void insertHash(hashTable &t, int x)
{
    if(t.r>=0){
        int idx = hashFunc(x);
        if(t.h[idx].val == -1){
            t.h[idx].val = x;
        }
        else{
            t.h[t.r].val = x;
            while(t.h[idx].next != -1){
                idx = t.h[idx].next;
            }
            t.h[idx].next = t.r;
        }
        while(t.r >= 0 && t.h[t.r].val>=0){
            t.r--;
        }
    }
}

void display(hashTable t){
    for(int i = 0;i<M;i++){
        if(t.h[i].val >= 0){
            cout << t.h[i].val << "\t" << t.h[i].next << endl;
        }
    }
}

bool search(hashTable t,int x){
    int idx = hashFunc(x);
    while(x!=t.h[idx].val && idx!=-1){
        idx = t.h[idx].next;
    }
    if(t.h[idx].val==x) return true;
    return false; 
}

// xem lại phần xóa và phần thêm

int main()
{
    system("cls");
    hashTable t;
    init(t);
    vector<int> v = {3, 7, 10, 20, 30, 45, 60, 70, 213, 222, 228, 443, 
367, 470, 503, 507};
    for(auto x : v){
        insertHash(t,x);
    }
    display(t);
    int find;cout << "Find : ";cin >> find;
    if(search(t,find)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}