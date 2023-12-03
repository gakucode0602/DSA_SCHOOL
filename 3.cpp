#include<iostream>
#include<fstream>
using namespace std;
#define M 101
char vertex[M];
int VoHuong[M][M];
int CoHuong[M][M];
// a . Do thi vo huong co trong so

void input_VoHuong(int a[][M], int &n) {
	cout << "Nhap so dinh cho do thi : \n";
	cin >> n;
	while (n <= 0 or n > M) {
		cout << "Nhap lai : "; cin >> n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		cout << '\n';
	}
}


void output_VoHuong(int a[][M], int n) {
	cout << "Ma tran ke da cho : \n";
	cout << '\t';
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "\t";
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " : \t";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}


// b . Do thi co huong co trong so
void input_CoHuong(int a[][M], int& n) {
	cout << "Nhap so dinh cho do thi : \n"; cin >> n;
	while (n <= 0 or n > M) {
		cout << "Nhap lai : "; cin >> n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		cout << '\n';
	}
}


void output_CoHuong(int a[][M], int n) {
	cout << "Ma tran ke da cho : \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

// c . Nhap du lieu tu file
void input_VoHuong_file(int a[][M], char vertex[], int& n) {
	ifstream fi("Vo_Huong.txt");
	if (fi.is_open()) {
		fi >> n;
		for (int i = 0; i < n; i++) {
			fi >> vertex[i];
			fi.ignore();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fi >> a[i][j];
			}
		}
		fi.close();
	}
	else cout << "error \n";
}

void output_VoHuong_file(int a[][M], char vertex[], int n) {
	cout << "Ma tran ke da cho : \n";
	cout << '\t';
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << "\t";
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " : \t";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void input_CoHuong_file(int a[][M], char vertex[], int& n) {
	ifstream fi("Co_Huong.txt");
	if (fi.is_open()) {
		fi >> n;
		for (int i = 0; i < n; i++) {
			fi >> vertex[i];
			fi.ignore();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fi >> a[i][j];
			}
		}
		fi.close();
	}
	else cout << "error \n";
}

void output_CoHuong_file(int a[][M], char vertex[], int n) {
	cout << "Ma tran ke da cho : \n";
	cout << '\t';
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << "\t";
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " : \t";
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void menu() {
	cout << "1 . Do thi vo huong" << endl;
	cout << "2 . Do thi co huong" << endl;
	cout << "3 . Nhap tu file txt" << endl;
	cout << "4 . Thoat \n";
	cout << endl;
}

void main() {
	int n;
	int choice;
	do
	{
		menu();
		cout << "Nhap lua chon : "; cin >> choice;
		while (choice < 1 || choice > 4)
		{
			cout << "Nhap lai : "; cin >> choice;
		}
		switch (choice) {
			case 1: 
			{
				system("cls");
				input_VoHuong(VoHuong, n);
				output_VoHuong(VoHuong, n);
				break;
			}
			case 2:
			{
				system("cls");
				input_CoHuong(CoHuong, n);
				output_CoHuong(CoHuong, n);
				break;
			}
			case 3:
			{
				system("cls");
				int choice_2;
				cout << "1 . Vo Huong \t 2.Co huong\n"; cin >> choice_2;
				while (choice_2 < 1 || choice_2 > 2) {
					cout << "1 . Vo Huong \t 2.Co huong\n"; cin >> choice_2;
				}
				if (choice_2 == 1) {
					input_VoHuong_file(VoHuong, vertex, n);
					output_VoHuong_file(VoHuong, vertex, n);
				}
				else {
					input_CoHuong_file(CoHuong, vertex, n);
					output_CoHuong_file(CoHuong, vertex, n);
				}
				break;
			}
			if (choice == 4) {
				break;
			}
		}
	} while (choice >= 1 && choice <= 3);
	system("cls");
	cout << "Lan dau tien trai thanh long co trong mi tom :))))) \n";
}
