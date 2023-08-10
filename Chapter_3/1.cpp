//#include<iostream>
//#include<vector>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//// 1.1
//struct node{
//	int val;
//	node* left;
//	node* right;
//};
//typedef node* nd;
//// 1.2
//void init(nd& a);
//// 1.3
//void insertRecursion(nd& a, int x);
//// 1.4
//bool searchRecursion(nd a, int x);
//// 1.5
//void searchStandFor(nd& p, nd& q);
//int deleteNode(nd& a, int x);
//// 1.6
//void LNR(nd a);
//// 1.7
//void NLR(nd a);
//// 1.8
//void LRN(nd a);
//// 1.9
//int count(nd a);
////1.10
//double averageValue(nd a);
//// 1.11
//void pushVector(vector<int>& v, nd a);
//int max(nd a);
//// 1.12
//bool isPrime(int x);
//int countPrime(nd a);
//
//
//int main() {
//	nd a = new node; init(a);
//	vector<int> v = { 2,3,5,1,4,6,7,8,10,9 };
//	for (auto x : v) {
//		insertRecursion(a, x);
//	}
//	cout << count(a) << endl;
//	cout << averageValue(a)/count(a) << endl;
//	cout << max(a) << endl;
//	cout << countPrime(a) << endl;
//	return 0;
//}
//
//
//void init(nd& a) {
//	a = NULL;
//}
//
//// 1.3
//void insertRecursion(nd& a, int x) {
//	nd insert = new node;
//	insert->val = x;
//	insert->left = NULL;
//	insert->right = NULL;
//	if (a == NULL) {
//		a = insert;
//	}
//	else {
//		if (a->val == x) return;
//		else if (a->val > x) insertRecursion(a->left, x);
//		else insertRecursion(a->right, x);
//	}
//}
//
//// 1.4
//bool searchRecursion(nd a, int x) {
//	if (a != NULL) {
//		if (a->val == x) return true;
//		else if (a->val < x) searchRecursion(a->right, x);
//		else searchRecursion(a->left, x);
//	}
//	return false;
//}
//
//// 1.5
//void searchStandFor(nd& p, nd& q) {
//	if (q->left == NULL) {
//		p->val = q->val;
//		p = q;
//		q = q->right;
//	}
//	else searchStandFor(p, q->left);
//}
//
//int deleteNode(nd& a, int x) {
//	if (a == NULL) return 0;
//	if (a->val == x) {
//		nd p = a;
//		if (a->left == NULL) {
//			a = a->right;
//		}
//		else if (a->right == NULL) {
//			a = a->left;
//		}
//		else searchStandFor(p, a->right);
//		delete p;
//		return 1;
//	}
//	if (a->val < x) return deleteNode(a->right, x);
//	if (a->val > x) return deleteNode(a->left, x);
//}
//
//// 1.6
//void LNR(nd a) {
//	if (a != NULL) {
//		LNR(a->left);
//		cout << a->val << " ";
//		LNR(a->right);
//	}
//}
//
//// 1.7
//void NLR(nd a) {
//	if (a != NULL) {
//		cout << a->val << " ";
//		NLR(a->left);
//		NLR(a->right);
//	}
//}
//
//// 1.8
//void LRN(nd a) {
//	if (a != NULL) {
//		LRN(a->left);
//		LRN(a->right);
//		cout << a->val << " ";
//	}
//}
//
//// 1.9
//int count(nd a) {
//	if (a == NULL) return 0;
//	else {
//		return 1 + count(a->left) + count(a->right);
//	}
//}
//
//// 1.10
//int sum = 0;
//double averageValue(nd a) {
//	if (a == NULL) return sum;
//	else {
//		averageValue(a->left);
//		sum += a->val;
//		averageValue(a->right);
//	}
//}
//
//// 1.11
//void pushVector(vector<int>& v, nd a) {
//	if (a != NULL) {
//		pushVector(v, a->left);
//		v.push_back(a->val);
//		pushVector(v, a->right);
//	}
//}
//int max(nd a) {
//	vector<int> v;
//	pushVector(v, a);
//	int max = v[0];
//	for (int i = 1; i < v.size(); i++) {
//		if (max < v[i]) max = v[i];
//	}
//	return max;
//}
//
//
//// 1.12
//bool isPrime(int x) {
//	if (x <= 1) return false;
//	for (int i = 2; i <= sqrt(x); i++) {
//		if (x % i == 0) return false;
//	}
//	return true;
//}
//
//int prime = 0;
//int countPrime(nd a) {
//	if (a == NULL) return prime;
//	else {
//		countPrime(a->left);
//		if (isPrime(a->val)) {
//			prime++;
//		}
//		countPrime(a->right);
//	}
//}
