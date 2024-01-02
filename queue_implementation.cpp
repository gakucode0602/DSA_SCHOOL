#include<iostream>
using namespace std;
#define M 101
void traversal(int q[],int n,int &front,int &rear){
    if(front == -1){
        cout << "Empty\n";
    }
    else{
        cout << "Queue : ";
        for(int i = front;i<=rear;i++){
            cout << q[i] << " ";
        }
        cout << endl;
    }
}

void push_TT(int a[],int &front,int &rear,int x){
    if(rear - front == M - 1) return; // queue is full
    else{
        if(front == -1) front = 0; // queue is empty
        if(rear == M - 1){ // rear at the max pos but 
            for(int i = front;i<=rear;i++){
                a[i - front] = a[i];
            }
            rear = M - 1 - front;
            front = 0;
        }
        cin >> x;
        a[++rear] = x;
    }
}

void pop_TT(int a[],int &front,int &rear,int &x){
    if(front == -1){
        return;
    }
    else{
        x = a[front++];
        if(front > rear){ // when there is only one ele in queue then remove it , it becomes empty
            front = rear = -1;
        }
    }
}

int main(){
    int a[M],n,front = -1,rear = -1;
    int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: int x_1;push_TT(a,front,rear,x_1);
         break;
         case 2: int x_2;pop_TT(a,front,rear,x_2);
         break;
         case 3: traversal(a,M,front,rear);
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
    return 0;
}