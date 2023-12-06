#include<iostream>
using namespace std;
#define M 100


struct list {
	int val;
	list* next;
};
typedef list* ll;

ll a[M];

void init(ll a[],int n) {
	for (int i = 0; i < n; i++) {
		a[i] = NULL;
	}
}

void insert(ll& a, int x) {
	ll ins = new list;
	ins->val = x;
	ins->next = NULL;
	if (a == NULL) a = ins;
	else {
		ll p = a;
		while (p->next) {
			p = p->next;
		}
		p->next = ins;
	}
}

void input(ll a[], int &n) {
	cout << "Nhap so dinh cua do thi : \n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		cout << "Nhap dinh thu " << i + 1 << " : ";cin >> d;
		insert(a[i], d);
		cout << "Nhap so dinh ke cua " << d << " : ";
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			insert(a[i], x);
		}
	}
}

void outputList(ll a) {
	ll p = a;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void output(ll a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Dinh thu " << i + 1 << " : ";
		outputList(a[i]);
	}
}


void main() {
	int n;
	input(a, n);
	output(a, n);
}
