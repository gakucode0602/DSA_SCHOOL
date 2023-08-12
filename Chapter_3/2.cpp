#include<iostream>
#include<vector>
using namespace std;

// tree
struct node{
	int val;
	node *left;
	node *right;
};typedef node* nd;

void inTree(nd &a){
	a = NULL;
}

void insertTree(nd &a,int x){
	nd insert = new node;
	insert->val = x;
	insert->left = NULL;
	insert->right = NULL;
	if(a==NULL) a = insert;
	else{
		nd p = a;
		while(p!=NULL){
			if(p->val==x) return;
			else{
				if(p->val < x){
					if(p->right!=NULL) p = p->right;
					else p->right = insert;
				}
				else
				{
					if(p->left!=NULL) p = p->left;
					else p->left = insert;
				}
			}
		}
	}
}

bool search(nd a,int x){
	nd p = a;
	while(p!=NULL){
		if(p->val==x) return true;
		else{
			if(p->val < x) p = p->right;
			else p = p->left;
		}
	}
	return false;
}

void searchStandFor(nd &p,nd &q){
	if(q->left==NULL){
		p->val = q->val;
		p = q;
		q = q->right;
	}
	else searchStandFor(p,q->left);
}

int deleteNode(nd &a,int x){
	if(a==NULL) return 0;
	if(a->val==x){
		nd p = a;
		if(a->left==NULL){
			a = a->right;
		}
		else if(a->right==NULL){
			a = a->left;
		}
		else searchStandFor(p,a->right);
		delete p;
		return 1;
	}
	else if(a->val < x) return deleteNode(a->right,x);
	else return deleteNode(a->left,x);
}

struct stack{
	nd val;
	stack *next;
};typedef stack* st;

void inStack(st &a){
	a = NULL;
}

void pushStack(st &a,nd x){
	st insert = new stack;
	insert->val = x;
	insert->next = a;
	a = insert;
}

void popStack(st &a){
	st p = a;
	a = a->next;
	delete p;
}

nd topStack(st a){
	return a->val;
}

bool emptyStack(st a){
	if(a==NULL) return true;
	else return false;
}

void NLR(nd a){
	st stk = new stack;inStack(stk);
	nd curr = a;
	nd lastVisited = NULL;
	while(!emptyStack(stk)||curr){
		if(curr){
			cout << curr->val << " ";
			pushStack(stk,curr);
			curr = curr->left;
		}
		else{
			nd topNode = topStack(stk);
			if(topNode->right && lastVisited!=topNode->right){
				curr = topNode->right;
			}
			else{
				lastVisited = topNode;
				popStack(stk);
			}
		}
	}
	cout << endl;
}

void LNR(nd a){
	st stk = new stack;inStack(stk);
	nd curr = a;
	while(!emptyStack(stk) || curr){
		while(curr){
			pushStack(stk,curr);
			curr = curr -> left;
		}
		curr = topStack(stk);
		popStack(stk);
		cout << curr->val << " ";
		curr = curr -> right;
	}
	cout << endl;
}
 
struct queue{
	nd val;
	queue* next;
};typedef queue* qu;

void inQueue(qu &a){
	a = NULL;
}

void push(qu &a,nd x){
	qu insert = new queue;
	insert->val = x;
	insert->next = NULL;
	if(a==NULL) a = insert;
	else{
		qu p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = insert;
	}
}

void pop(qu &a){
	qu p = a;
	a = a->next;
	delete p;
}

nd front(qu a){
	return a->val;
}

bool emptyQueue(qu a){
	if(a==NULL) return true;
	return false;
}

void LRN(nd a){
	qu que = new queue;inQueue(que);
	st stk = new stack;inStack(stk);
	st newStack = new stack;inStack(newStack);
	pushStack(stk,a);
	while(!emptyStack(stk)){
		nd curr = topStack(stk);
		push(que,curr);
		popStack(stk);
		if(curr->left!=NULL){
			pushStack(stk,curr->left);
		}
		if(curr->right!=NULL){
			pushStack(stk,curr->right);
		}
	}
	while(!emptyQueue(que)){
		pushStack(newStack,front(que));
		pop(que);
	}
	while(!emptyStack(newStack)){
		cout << newStack->val->val << " ";
		popStack(newStack);
	}
} 
int main(){
	nd root = new node;inTree(root);
	std::vector<int> v = {4,2,6,1,3,5,7};
	for(auto x : v){
		insertTree(root,x);
	}
	NLR(root);
	LNR(root);
	LRN(root);
	return 0;

}
