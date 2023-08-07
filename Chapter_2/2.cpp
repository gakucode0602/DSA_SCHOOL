#include<iostream>
#include<vector>
using namespace std;

struct node {
	int val;
	node* next;
};
typedef node* nd;
void createVector(vector<int>& v, nd a);
void init(nd& a);
void output(nd a);
void insertList(nd& a, int n);
void createList(nd& a, vector<int>v);
void InterchangeSort(nd a);
void InsertionSort(nd a);
void SelectionSort(nd a);
void menu();

int main()
{
	nd a = new node;
	int choice;
	do
	{
		menu();
		cout << "Input the choice : "; cin >> choice;
		while (choice < 1 || choice >6) {
			cout << "Error" << endl;
			cout << "Input the choice : "; cin >> choice;
		}
		switch (choice)
		{
		case 1: {
			system("cls");
			init(a);
			vector<int> v = { 4,2,1,5,3 };
			createList(a, v);
			break;
		}
		case 2:{
			system("cls");
			cout << "List : "; output(a);
			break;
		}
		case 3:{
			system("cls");
			cout << "List after sort : ";InterchangeSort(a);
			break;
		}
		case 4: {
			system("cls");
			cout << "List after sort : "; InsertionSort(a);
			break;
		}
		case 5: {
			system("cls");
			cout << "List after sort : "; SelectionSort(a);
			break;
		}
		}
		if (choice == 6) break;
	} while (choice >=1 && choice < 6);
	cout << "Bye" << endl;
	return 0;
}

// khoi tao
void init(nd& a)
{
	a = NULL;
}

// xuat
void output(nd a)
{
	nd p = a;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void createVector(vector<int>& v, nd a) {
	nd p = a;
	while (p != NULL)
	{
		v.push_back(p->val);
		p = p->next;
	}
}

void SelectionSort(nd a) {
	int choice;
	cout << "Which kind of sort you want to use ?\n [1]. Ascending \t[2]. Descending\n";
	cin >> choice;
	while (choice < 1 || choice >2) {
		cout << "Error" << endl;
		cin >> choice;
	}
	vector<int>v;
	nd p = new node; init(p);
	createVector(v, a);
	if (choice == 1) {
		for (int i = 0; i < v.size() - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[min] > v[j]) min = j;
			}
			swap(v[min], v[i]);
		}
	}
	else {
		for (int i = 0; i < v.size() - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[min] < v[j]) min = j;
			}
			swap(v[min], v[i]);
		}
	}
	createList(p, v);
	output(p);
}

void insertList(nd& a, int n) {
	nd insert = new node;
	insert->val = n;
	insert->next = NULL;
	if (a == NULL)
	{
		a = insert;
	}
	else {
		nd p = a;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = insert;
	}
}

void createList(nd& a, vector<int>v) {
	for (auto x : v) {
		insertList(a, x);
	}
}

void InsertionSort(nd a) {
	int choice;
	cout << "Which kind of sort you want to use ?\n [1]. Ascending \t[2]. Descending\n";
	cin >> choice;
	while (choice < 1 || choice >2) {
		cout << "Error" << endl;
		cin >> choice;
	}
	vector<int> v;
	nd p = new node; init(p);
	createVector(v, a);
	if (choice == 1) {
		for (int i = 1; i < v.size() - 1; i++)
		{
			int j = i - 1;
			int x = v[i];
			while (j >= 0 && v[j] >= v[i]) {
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = x;
		}
	}
	else {
		for (int i = 1; i < v.size() - 1; i++)
		{
			int j = i - 1;
			int x = v[i];
			while (j >= 0 && v[j] <= v[i]) {
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = x;
		}
	}
	createList(p, v);
	output(p);
}

void InterchangeSort(nd a) {
	int choice;
	cout << "Which kind of sort you want to use ?\n [1]. Ascending \t[2]. Descending\n";
	cin >> choice;
	while (choice < 1 || choice >2) {
		cout << "Error" << endl;
		cin >> choice;
	}
	vector<int>v;
	nd p = new node; init(p);
	createVector(v, a);
	if (choice == 1) {
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[i] > v[j]) swap(v[i], v[j]);
			}
		}
	}
	else {
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[i] < v[j]) swap(v[i], v[j]);
			}
		}
	}
	createList(p, v);
	output(p);
}

void menu()
{
	cout << "1 . Create a NULL list" << endl;
	cout << "2 . Output" << endl;
	cout << "3 . Interchange Sort" << endl;
	cout << "4 . Insertion Sort" << endl;
	cout << "5 . Selection Sort" << endl;
	cout << "6 . Exit" << endl;
}
