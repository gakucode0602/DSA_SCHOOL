#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define M 100
int a[M];
int n;
void selection(int a[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        swap(a[min],a[i]);
    }
}

void insertion_sort(int a[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int j = i-1;
        int x = a[i];
        while(j>=0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void bubble(vector <int> &a)
{
    for(int i = 0;i<a.size()-1;i++)
    {
        for(int j = a.size()-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}

void merge(int a[],int l,int m,int r)
{
    vector<int>x(a+l,a+m+1);
    vector<int>y(a+m+1,a+r+1);
    int i = 0,j = 0,k = l;
    int n1 = x.size(),n2 = y.size();
    while(i<n1 && j<n2)
    {
        if(x[i] < y[j]){ a[k] = x[i];i++;}
        else { a[k]= y[j];j++;}
        k++;
    }
    while(i<n1) {a[k] = x[i];i++;k++;}
    while(j<n2) {a[k] = y[j];j++;k++;}
}
void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void interchange(vector<int> &a)
{
    for(int i = 0;i<a.size();i++)
    {
        for(int j = i+1;j<a.size();j++)
        {
            if(a[i]>a[j]) {swap(a[i],a[j]);}
        }
    }
}

int Sequential_search(int a[],int n,int x)
{
    int i = 0;
    while(i<n && a[i] != x)
    {
        i++;
    }
    if(i<n) return i;
    else return -1;
}

int Binary_search(int a[],int n,int x)
{
    int l = 0,r = n-1;
    while(l<r)
    {
        int m = l + (r-l)/2;
        if(a[m]==x) { return m;}
        else if(a[m] > x) { r = m-1; }
        else { l = m + 1; }
    }
    return -1;
}