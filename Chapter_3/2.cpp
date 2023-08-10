#include<iostream>
#include<vector>
using namespace std;
// tree
struct node {
	int val;
	node* left;
	node* right;
}; typedef node* nd;

void init(nd& a) {
	a = NULL;
}

void insertLoop(nd& a, int x) {
	nd insert = new node;
	insert->val = x;
	insert->left = NULL;
	insert->right = NULL;
	if (a == NULL) a = insert;
	else {
		nd p = a;
		while (p != NULL) {
			if (p->val == x) return;
			else if (p->val < x) {
				if (p->right != NULL) p = p->right;
				else p->right = insert;
			}
			else {
				if (p->left != NULL) p = p->left;
				else p->left = insert;
			}
		}
	}
}

bool search(nd a, int x) {
	if (a != NULL) {
		nd p = a;
		while (p != NULL) {
			if (p->val == x) return true;
			else if (p->val < x) p = p->right;
			else p = p->left;
		}
	}
	return false;
}

void searchStandFor(nd& p, nd& q) {
	if (q->left == NULL) {
		p->val = q->val;
		p = q;
		q = q->right;
	}
	else searchStandFor(p, q->left);
}


int deleteNode(nd& a, int x) {
	if (a == NULL) return 0;
	if (a->val == x) {
		nd p = a;
		if (a->right == NULL) {
			a = a->left;
		}
		else if (a->left == NULL) {
			a = a->right;
		}
		else searchStandFor(p, a->right);
		delete p;
		return 1;
	}
	if (a->val < x) return deleteNode(a->right, x);
	if (a->val > x) return deleteNode(a->left, x);
}

// stack danh sach dac


int main() {
	nd a = new node;
	init(a);
	vector<int> v = { 2,3,5,1,4,6,7,8,10,9 };
	for (auto x : v) {
		insertLoop(a, x);
	}
	if (search(a, 10)) cout << "true" << endl;
	else cout << "false" << endl;
	if (search(a, 11)) cout << "true" << endl;
	else cout << "false" << endl;
	deleteNode(a, 7);
	return 0;
}