#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define M 101
void input(int a[],int &n){
    cout << "Nhap so phan tu cho mang : ";cin >> n;
    while(n < 0 || n > M){
        cout << "Nhap lai : ";cin >> n;
    }
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
}

void inputFromFile(int a[],int &n){
    ifstream in("data.txt");
    if(in.is_open()){
        in >> n;
        for(int i = 0;i<n;i++){
            in >> a[i];
        }
        in.close();
    }else{
        cout << "Error" << endl;
    }
}

void output(int a[],int n){
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void menu(){
    cout << "Chon mot kieu sap xep : \n";
    cout << "1 . Heap sort \n";
    cout << "2 . Quick sort \n";
    cout << "3 . Counting sort \n";
    cout << "4 . Break \n";
    cout << "\n";
}

void heapify(int a[],int n,int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if(l < n && a[l] > a[largest]){
        largest = l;
    }
    if(r < n && a[r] > a[largest]){
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
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}

void quicksort(int a[],int l,int r){
    int i = l;
    int j = r;
    int x = a[(l + r) / 2];
    while(i < j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){ swap(a[i],a[j]);i++;j--; }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);
}

void countingsort(int a[],int b[],int n){
    int max_num = a[0];
    for(int i = 1;i<n;i++){ max_num = max(a[i],max_num); }
    int cnt[M] = { 0 };
    for(int i = 0;i<n;i++){ cnt[a[i]]++; }
    for(int i = 1;i<=max_num;i++){ cnt[i]+=cnt[i-1]; }
    for(int i = n-1;i>=0;i--){
        b[cnt[a[i]]-1] = a[i];
        cnt[a[i]]--;
    }
}

int main(){
    int a[M],b[M],n;
    int choice;
    do{
        menu();
        cin >> choice;
        while(choice < 1 || choice > 4){
            cout << "Nhap lai : ";cin >> choice;
        }
        if(choice == 4){
            break;
        }
        switch(choice){
            case 1:{
                inputFromFile(a,n);
                cout << "a[] : ";output(a,n);
                cout << "1 . Heap sort : ";heapsort(a,n);output(a,n);
                break;
            }
            case 2:{
                inputFromFile(a,n);
                cout << "a[] : ";output(a,n);
                cout << "1 . Quick sort : ";quicksort(a,0,n-1);output(a,n);
                break;
            }
            case 3:{
                inputFromFile(a,n);
                cout << "a[] : ";output(a,n);
                cout << "1 . Counting sort : ";countingsort(a,b,n);output(b,n);
                break;
            }
        }
    }while(choice >= 1 || choice <= 4);
    return 0;
}