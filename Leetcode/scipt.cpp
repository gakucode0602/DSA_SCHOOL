#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define M 101
int a[M][M],vertices[M],C[M];
struct queue{
	int val;
	queue *next;
};
typedef queue* qu;
qu front,rear;


// BFS
void init(){
	front = rear = NULL;
}

bool empty(){
	if(!front) return true;
	else return false;
}

void push(int x){
	qu insert = new queue;
	insert->val = x;
	insert->next = NULL;
	if(rear == NULL){
		front = insert;
	}
	else{
		rear->next = insert;
	}
	rear = insert;
}

void pop(int &x){
	if(front!=NULL){
		qu p = front;
		x = front->val;
		front = front->next;
		if(front == NULL){
			rear = NULL;
		}
		delete p;
	}
}

void process()
{
	if(front){
		qu p = front;
		while(p){
			cout << p->val << " ";
			p = p->next;
		}
	}
	cout << '\n';
}



void inputFromFile(int a[][M],int vertices[M],int &n){
	ifstream fi("data.txt");
	if(fi.is_open()){
		fi >> n;
		for(int i = 0;i<n;i++){
			fi >> vertices[i];
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				fi >> a[i][j];
			}
		}
		fi.close();
	}
	else cout << "Unable to read \n";
}

void output(int a[][M],int vertices[],int n){
	cout << "    ";
	for(int i = 0;i<n;i++){
		cout << vertices[i] << " ";
	}
	cout << '\n';
	for(int i = 0;i<n;i++){
		cout << vertices[i] << " : "; 
		for(int j = 0;j<n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void bfs(int n,int v){ // v : index of the start vertex
	memset(C,1,sizeof(C));
	init();
	int w,p;
	push(v);
	C[v] = 0;
	while(front){
		pop(p);
		cout << vertices[p] << " ";
		for(w = 0;w<n;w++){
			if(C[w] and a[p][w] == 1){
				push(w);
				C[w] = 0;
			}
		}
	}
	cout << "\n";
}


// DFS

//create stack
struct Stack{
	int val;
	Stack *next;
	Stack() : val(0),next(nullptr){}
	Stack(int x) : val(x),next(nullptr){}
};
typedef Stack* st;
void inStack(st &s){
	s = NULL;
}

void pushSt(st &s,int x){
	st insert = new Stack(x);
	if(!s) s = insert;
	else{
		insert->next = s;
		s = insert;
	}
}

void popSt(st &s,int &x){
	if(s){
		st tmp = s;
		x = s->val;
		s = s->next;
		delete tmp;
	}
}

int top(st s){
	return s->val;
}

bool emptySt(st s){
	if(!s) return true;
	return false;
}



void DFS(int n,int x){
	bool C[M];
	memset(C,false,sizeof(C));
	st S;
	inStack(S);
	pushSt(S,x);
	cout << vertices[x] << " ";
	C[x] = true;
	int w = -1,u = x;
	while(!emptySt(S)){
		if(w == n) popSt(S,u);
		for(w = 0;w<n;w++){
			if(a[u][w]!=0 and C[w]==false){
				pushSt(S,u);
				pushSt(S,w);
				cout << vertices[w] << " ";
				C[w] = true;
				u = w;
				break;
			}
		}
	}
}


int main(){
	int n;
	inputFromFile(a,vertices,n);
	output(a,vertices,n);
	//bfs(a,vertices,n,1);
	//bfs(n,0);
	DFS(n,0);
	return 0;
}