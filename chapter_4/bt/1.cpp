#include<iostream>
#include<vector>
using namespace std;
#define M 5000
#define Hash 501
// a
struct node{
    int val;
    node *next;
};

typedef node* nd;
// b ,
void init(nd a[]){
    for(int i = 0;i<M;i++){
        a[i] = NULL;
    }
}


int hashFunc(int x){
    return x % Hash;
}
// c
void inputHT(nd a[],int x){
    int idx = hashFunc(x);
    nd insert = new node;
    insert->val = x;
    if(a[idx]==NULL){
        insert->next = a[idx];
        a[idx] = insert;
    }
    else if(x < a[idx]->val){
        insert->next = a[idx];
        a[idx] = insert;
    }
    else{
        nd p = a[idx];
        nd q = NULL;
        while(p!=NULL && p->val < x){
            q = p;
            p = p->next;
        }
        q->next = insert;
        insert->next = p;
    }
}

void display(nd a[]){
    for(int i = 0;i<M;i++){
        if(a[i]!=NULL){
            nd p = a[i];
            cout << i << " ";
            while(p!=NULL){
                cout << p->val << " ";
                p = p->next; 
            }
            cout << endl;
        }
    }
}

bool search(nd a[],int x){
    int idx = hashFunc(x);
    nd p = a[idx];
    while(p!=NULL && p->val!=x){
        p = p->next;
    }
    if(p==NULL) return false;
    return true;
}

int main(){
    system("cls");
    vector<int> v = {3, 7, 10, 20, 30, 45, 60, 70, 213, 222, 228, 
443, 367, 470, 503, 507};
    nd a[M];
    init(a);
    for(auto x : v){
        inputHT(a,x);
    }
    display(a);
    int find;cout << "Find : ";cin >> find;
    if(search(a,find)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}