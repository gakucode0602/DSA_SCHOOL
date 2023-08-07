#include <iostream>
#include <vector>
using namespace std;
// #define M 101
// struct Node{
//     int val;
//     Node* next;
// };
// typedef Node* nd;

// void init(nd &heads[])
// {
//     for(int i = 0;i<M;i++)
//     {
//         heads[i] = NULL;
//     }
// }

// nd insert_ele(nd heads[],int k)
// {
//     nd t = heads[k%M];
//     nd x = new Node;
//     x->val = k;
//     if(t==NULL)
//     {
//         x->next = t;
//         head[k%M] = x;
//     }
//     else if(t->val >= k)
//     {
//         x->next = t;
//         heads[k%M] = x;
//     }
//     else
//     {
//         nd p = t->next;
//         while(p!=NULL && p->val < k)
//         {
//             t = t->next;
//             p = t->next;
//         }
//         t->next = x;
//         x->next = p
//     }
//     return x;
// }

// nd search(nd heads[],int k)
// {
//     nd t = heads[k%M];
//     if(t==NULL) return t;
//     while(t->val < k && t->next!=NULL)
//     {
//         t = t->next;
//     }
//     if(t->val==k) return t;
//     return NULL;
// }

// int delete_ele(int k)
// {
//     nd t = heads[k%M];
//     if(t==NULL) return 0;
//     nd p = NULL;
//     while(t->val < k && t->next!=NULL)
//     {
//         p = t;
//         t = t->next;
//     }
//     if(t==NULL) return 0;
//     if(t->val == k)
//     {
//         if(p==NULL) heads[k%M] = t->next;
//         else p->next = t->next;
//         delete t;
//         return 1;
//     }
//     return 0;
// }

// coalesced chaining : noi ket hop nhat

#define M 10

struct item
{
    int value;
    int next;
};

struct HashTable
{
    item h[M];
    int r;
};

void init(HashTable &t)
{
    for (int i = 0; i < M; i++)
    {
        t.h[i].value = -1;
        t.h[i].next = -1;
    }
    t.r = M - 1;
}

int hashFunc(int x)
{
    return x % M;
}

void insertHashItem(HashTable &t, int x)
{
    if (t.r >= 0)
    {
        int idx = hashFunc(x);
        if (t.h[idx].value == -1)
        {
            t.h[idx].value = x;
        }
        else
        {
            t.h[t.r].value = x;
            while (t.h[idx].next != -1)
            {
                idx = t.h[idx].next;
            }
            t.h[idx].next = t.r;
        }
        while (t.r >= 0 && t.h[t.r].value >= 0)
        {
            t.r--;
        }
    }
}

void display(HashTable t)
{
    for (int i = 0; i < M; i++)
    {
        if (t.h[i].value >= 0)
        {
            cout << i << " : " << t.h[i].value << " : " << t.h[i].next << endl;
        }
    }
}

bool search(HashTable t, int x)
{
    int idx = hashFunc(x);
    while (x!=t.h[idx].value && idx!=-1)
    {
        idx = t.h[idx].next;
    }
    if(t.h[idx].value == x) return true;
    return false;
}

int delete_item(HashTable &t, int x)
{
    int i = hashFunc(x);
    int j = i;
    while (x != t.h[i].value && i != -1)
    {
        j = i;
        i = t.h[i].next;
    }
    if (i == -1)
        return i;
    int arr[M], k = 0;
    if (j != i)
    {
        t.h[j].next = -1;
    }
    while (t.h[i].next != -1)
    {
        t.h[i].value = t.h[t.h[i].next].value;
        arr[k++] = t.h[i].value;
        t.h[i].value = -1;
        j = i;
        i = t.h[i].next;
        t.h[j].next = -1;
    }
    t.r = M - 1;
    t.h[i].value = t.h[i].next = -1;
    while (t.h[t.r].value != -1)
        t.r--;
    for (int i = 0; i < k; i++)
    {
        insertHashItem(t, arr[i]);
    }
    return 1;
}

int main()
{
    system("cls");
    HashTable t;
    init(t);
    vector<int> v = {20, 35, 16, 40, 45, 25, 32, 37, 22, 55};
    for (auto x : v)
    {
        insertHashItem(t, x);
    }
    display(t);
    int x;
    cout << "Input the number you want to search : ";
    cin >> x;
    if (search(t, x))
        cout << "y" << endl;
    else
        cout << "n" << endl;
    int del;
    cout << "Input the number you want to delete : ";
    cin >> del;
    delete_item(t, del);
    cout << "The table after delete : " << endl;
    display(t);
    return 0;
}