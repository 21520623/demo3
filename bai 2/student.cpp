// bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "student.h"
void Number(int& n) {
	cout << "Nhap so luong: ";
	cin >> n;
	while (n <= 0 || n > 10000) {
		Number(n);
	}
}
void student::Input() {
	cout << "Nhap thong tin hoc sinh: " << endl;
	cout << "Ma hoc sinh: ";
	cin >> ma;
	cout << "Ho ten: ";
	cin.ignore();
	cin.getline(hoten, 20);
	cout << "Gioi tinh: (F là nu, M la nam) ";
	cin >> gioitinh;
	cout << "Ngay thang nam sinh: ";
	cin >> date >> month >> year;
	while (date > 31 || date <= 0 || month > 12 || month <= 0) {
		cout << "Nhap lai ngay thang nam.\n";
		Input_day();
	}
	if (CheckYear()) {
		switch (month)
		{
		case 2:
			if (date > 29) {
				cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
				Input_day();
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (date > 30) {
				cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
				Input_day();
			}
		default:
			break;
		}
	}
	else {
		switch (month)
		{
		case 2:
			if (date > 28) {
				cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
				Input_day();
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (date > 30) {
				cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
				Input_day();
			}
		default:
			break;
		}
	}
	cout << "Diem 3 mon: ";
	cin >> Toan >> Van >> Anh;
	cout << endl;
}
void student::Input_day() {
	cin >> date >> month >> year;
}
bool student::CheckYear() {
	if (year % 400 == 0) return true;
	if (year % 4 == 0 && year % 100 != 0) return true;
	return false;
}
void student::Output() {
	cout << "Ma hoc sinh: " << ma << endl;
	cout << "Ho ten hoc sinh: " << hoten << endl;
	cout << "Gioi tinh: ";
	if (gioitinh == 'F' || gioitinh == 'f') cout << "Nu";
	else if (gioitinh == 'M' || gioitinh == 'm') cout << "Nam";
	else cout << "Gioi tinh thu ba.";
	cout << endl;
	cout << "Ngay sinh: " << date << "/" << month << "/" << year << endl;
	cout << "Diem mon Toan : " << Toan;
	cout << "\nDiem mon Van: " << Van;
	cout << "\nDiem mon Anh: " << Anh;
	cout << endl;
}
float student::sum() {
	return (Toan + Van + Anh);
}
int student::sex_female() {
	if (gioitinh == 'F' || gioitinh == 'f') return 1;
	return 0;
}
int student::Inspect() {
	if (Toan >= 3.0 && Van >= 3.0 && Anh >= 3.0) return 1;
	return 0;
}
int Number_of_female_students_over_28score(student a[], int n) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].sum() > 28.0 && a[i].sex_female()) t++;
	}
	return t;
}
int students_pass_X_school(student a[], int n) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].sum() > 18.0) {
			if (a[i].Inspect()) t++;
		}
	}
	return t;
}

