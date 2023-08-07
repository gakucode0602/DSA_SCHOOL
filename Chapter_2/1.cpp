#include<iostream>
#include<vector>
using namespace std;
#define M 100

void processVec(vector<int> v);
void input(int a[], int n);
void output(int a[], int n);
void insertionSort(int a[], int n);
void selectionSort(int a[], int n);
void interchangeSort(int a[], int n);
void bubbleSort(int a[], int n);
bool sequentialSearch(int a[], int n, int x);
bool binarySearch(int a[], int n, int x);
void menu();

int main()
{
	int a[M];
	int n;
	int choice;
	do
	{
		menu();
		cout << "Input your choice : "; cin >> choice;
		switch (choice) {
		case 1: {
			system("cls");
			cout << "Input n : "; cin >> n;
			input(a, n);
			cout << "Success" << endl;
			break;
		}
		case 2: {
			system("cls");
			cout << "List "; output(a, n);
			break;
		}
		case 3: {
			system("cls");
			cout << "List after using insertion Sort : "; insertionSort(a, n);
			break;
		}
		case 4: {
			system("cls");
			cout << "List after using selection Sort : "; selectionSort(a, n);
			break;
		}
		case 5: {
			system("cls");
			cout << "List after using interchange Sort : "; interchangeSort(a, n);
			break;
		}
		case 6: {
			system("cls");
			cout << "List after using bubble Sort : "; bubbleSort(a, n);
			break;
		}
		case 7: {
			system("cls");
			int x; cout << "Find : "; cin >> x;
			if (sequentialSearch(a, n, x)) cout << "true" << endl;
			else cout << "false" << endl;
			break;
		}
		case 8: {
			system("cls");
			int x; cout << "Find : "; cin >> x;
			if (binarySearch(a, n, x)) cout << "true" << endl;
			else cout << "false" << endl;
			break;
		}
		}
	} while (choice >= 1 && choice <=8);
	return 0;
}

void menu() {
	cout << "1 . Input list " << endl;
	cout << "2 . Output list" << endl;
	cout << "3 . Insertion Sort" << endl;
	cout << "4 . Selection Sort" << endl;
	cout << "5 . Interchange Sort" << endl;
	cout << "6 . Bubble Sort" << endl;
	cout << "7 . Search using Sequential search" << endl;
	cout << "8 . Search using Binary search" << endl;
	cout << "9 . Exit" << endl;
	cout << endl;
}

void processVec(vector<int> v)
{
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

// 1 Nhap danh sach
void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

// 2 Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// 3 Insertion sort
void insertionSort(int a[], int n)
{
	vector<int> v(a + 0, a + n);
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int x = v[i];
		while (j >= 0 && v[j] >= x) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = x;
	}
	processVec(v);
}

// Selection sort
void selectionSort(int a[], int n)
{
	vector<int> v(a + 0, a + n);
	for (int i = 0; i < v.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j]) min = j;
		}
		swap(v[min], v[i]);
	}
	processVec(v);
}

//Interchange sort
void interchangeSort(int a[], int n)
{
	vector<int> v(a + 0, a + n);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j]) swap(v[i], v[j]);
		}
	}
	processVec(v);
}

// Bubble sort
void bubbleSort(int a[], int n)
{
	vector<int> v(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[i] < v[j]) swap(v[i], v[j]);
		}
	}
	processVec(v);
}

// Sequential search
bool sequentialSearch(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x) {
		i++;
	}
	if (i == n) return false;
	else return true;
}


// binary search
bool binarySearch(int a[], int n, int x)
{
	vector<int> v(a, a + n);
	// sort
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j]) swap(v[i], v[j]);
		}
	}
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (r + l) / 2;
		if (v[m] == x) return true;
		else {
			if (v[m] < x) {
				l = m + 1;
			}
			else r = m - 1;
		}
	}
	return false;
}

