#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
struct SinhVien {
	long int id;
	string lastName,firstName;
	int date, month, year;
	int gendre;
	double gpa;
};

struct st {
	SinhVien sv;
	st* next;
};

typedef st* s;

void init(s& a) {
	a = NULL;
}

SinhVien inputStruct() {
	SinhVien a;
	cout << "Insert id : "; cin >> a.id;
	cout << "Insert last name : "; cin >> a.lastName;
	cout << "Insert first name : "; cin >> a.firstName;
	cout << "Day : "; cin >> a.date;
	cout << "Month : "; cin >> a.month;
	cout << "Year : "; cin >> a.year;
	cout << "Gendre : \n [0] . Female\t [1] . Male\n"; cin >> a.gendre;
	while (a.gendre < 0 || a.gendre >1)
	{
		cout << "Error" << endl;
		cout << "Gendre : \n [0] . Female\t [1] . Male\n"; cin >> a.gendre;
	}
	cout << "GPA : "; cin >> a.gpa;
	return a;
}

void create(s &a, SinhVien obj)
{
	s insert = new st;
	insert->sv.firstName = obj.firstName;
	insert->sv.lastName = obj.lastName;
	insert->sv.id = obj.id;
	insert->sv.date = obj.date;
	insert->sv.month = obj.month;
	insert->sv.year = obj.year;
	insert->sv.gendre = obj.gendre;
	insert->sv.gpa = obj.gpa;
	insert->next = NULL;
	if (a == NULL)
	{
		a = insert;
	}
	else {
		s p = a;
		while (p->next != NULL) p = p->next;
		p->next = insert;
	}
}

void inputSV(s &a, string filename) {
	ofstream fo(filename);
	if (fo.is_open()) {
		SinhVien obj = inputStruct();
		create(a,obj);
		s p = a;
		while (p != NULL) {
			fo << p->sv.id << "#" << p->sv.firstName << "#" << p->sv.lastName << "#" 
			   << p->sv.date << "-" << p->sv.month << "-" << p->sv.year << "#" 
			   << p->sv.gendre << "#" << p->sv.gpa << endl;
			p = p->next;
		}
		fo.close();
	}
	else cout << "Open file error" << endl;
}

// c
void sortVecId(vector<SinhVien> &v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].id > v[j].id) swap(v[i], v[j]);
		}
	}
}

void sortVecGPA(vector<SinhVien>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].gpa > v[j].gpa) swap(v[i], v[j]);
		}
	}
}

void sortById(s &a,string filename) {
	vector<SinhVien> v;
	ifstream fi(filename);
	if (fi.is_open())
	{
		string line;
		while (getline(fi, line)) {
			istringstream iss(line);
			long int id;
			string lastName, firstName;
			int date, month, year;
			int gendre;
			double gpa;

			iss >> id; iss.ignore();
			getline(iss, firstName, '#');
			getline(iss, lastName, '#');
			iss >> date; iss.ignore();
			iss >> month; iss.ignore();
			iss >> year; iss.ignore();
			iss >> gendre; iss.ignore();
			iss >> gpa;
			if (!iss.fail()) {
				SinhVien obj;
				obj.id = id; obj.firstName = firstName; obj.lastName = lastName;
				obj.date = date; obj.month = month; obj.year = year;
				obj.gendre = gendre; obj.gpa = gpa;
				v.push_back(obj);
			}
			else cout << "Unreadable" << endl;
		}
		sortVecId(v);
		while (a != NULL) {
			s curr = a;
			a = a->next;
			delete curr;
		}

		s temp = new st; init(temp);
		for (auto x : v) {
			create(temp, x);
			//delete(curr);
		}
		a = temp;
		s p = a;
		cout << "Sorting by ID" << endl;
		while (p != NULL)
		{
			cout << p->sv.id << "#" << p->sv.firstName << "#" << p->sv.lastName << "#"
				<< p->sv.date << "-" << p->sv.month << "-" << p->sv.year << "#"
				<< p->sv.gendre << "#" << p->sv.gpa << endl;
			p = p->next;
		}
		fi.close();
	}
	else cout << "Failed" << endl;
}

void sortByGPA(s& a, string filename) {
	vector<SinhVien> v;
	ifstream fi(filename);
	if (fi.is_open())
	{
		string line;
		while (getline(fi, line)) {
			istringstream iss(line);
			long int id;
			string lastName, firstName;
			int date, month, year;
			int gendre;
			double gpa;

			iss >> id; iss.ignore();
			getline(iss, firstName, '#');
			getline(iss, lastName, '#');
			iss >> date; iss.ignore();
			iss >> month; iss.ignore();
			iss >> year; iss.ignore();
			iss >> gendre; iss.ignore();
			iss >> gpa;
			if (!iss.fail()) {
				SinhVien obj;
				obj.id = id; obj.firstName = firstName; obj.lastName = lastName;
				obj.date = date; obj.month = month; obj.year = year;
				obj.gendre = gendre; obj.gpa = gpa;
				v.push_back(obj);
			}
			else cout << "Unreadable" << endl;
		}
		sortVecGPA(v);
		while (a != NULL) {
			s curr = a;
			a = a->next;
			delete curr;
		}

		s temp = new st; init(temp);
		for (auto x : v) {
			create(temp, x);
			//delete(curr);
		}
		a = temp;
		s p = a;
		cout << "Sorting by GPA" << endl;
		while (p != NULL)
		{
			cout << p->sv.id << "#" << p->sv.firstName << "#" << p->sv.lastName << "#"
				<< p->sv.date << "-" << p->sv.month << "-" << p->sv.year << "#"
				<< p->sv.gendre << "#" << p->sv.gpa << endl;
			p = p->next;
		}
		fi.close();
	}
	else cout << "Failed" << endl;
}

int main()
{
	s a = new st;
	init(a);
    int N; cout << "N : "; cin >> N;
	system("cls");
	for (int i = 0; i < N; i++) {
		inputSV(a, "SinhVien.dat");
	}
	sortById(a, "SinhVien.dat");
	sortByGPA(a, "SinhVien.dat");
	return 0;
}