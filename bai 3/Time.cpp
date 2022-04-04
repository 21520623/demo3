// bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Time.h"
void TIME::Input() {
		cout << "Nhap ngay thang nam: ";
		cin >> day >> month >> year;
		cout << "Nhap gio phut giay: ";
		cin >> hour >> minute >> second;
		//kiem tra ngay thang nam
		while (month > 12 || month <= 0 || day <= 0 || day > 31) {
			cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
			Input();
		}
		//kiem tra gio phut giay
		while (hour > 24 || hour < 0 || minute > 60 || minute < 0 || second >60 || second < 0) {
			cout << "Thoi gian khong hop le. Moi nhap lai. " << endl;
			Input();
		}
		if (CheckYear()) {
			switch (month)
			{
			case 2:
				if (day > 29) {
					cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
					Input();
				}
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
					Input();
				}
			default:
				break;
			}
		}
		else {
			switch (month)
			{
			case 2:
				if (day > 28) {
					cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
					Input();
				}
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					cout << "Thoi gian khong hop le. Moi nhap lai." << endl;
					Input();
				}
			default:
				break;
			}
		}
		if (hour == 24) hour = 0;
		cout << endl;
	}
bool TIME::CheckYear() {
		if (year % 400 == 0) return true;
		if (year % 4 == 0 && year % 100 != 0) return true;
		return false;
	}
void TIME::Output_bissextile() {
		if (CheckYear())
			cout << year << " la nam nhuan." << endl;
	}
bool TIME::CheckDay() {
		if (day > 31) return false;
		if (CheckYear()) {
			switch (month)
			{
			case 2: if (day > 29) return false;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) return false;
			default:
				return true;
				break;
			}
		}
		else {
			switch (month)
			{
			case 2:
				if (day > 28) return false;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) return false;
			default:
				return true;
				break;
			}
		}
	}
int TIME::LastDay() {
		if (CheckYear()) {
			switch (month)
			{
			case 2: return 29;
			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
			default:
				return 31;
				break;
			}
		}
		else {
			switch (month)
			{
			case 2:
				return 28;
			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
			default:
				return 31;
				break;
			}
		}
	}
void TIME::Change_second_to_hour_minute_second() {
		int t;
		cout << "Nhap t: ";
		cin >> t;
		second = second + t;
		while (second >= 60) {
			minute++;
			second = second - 60;
		}
		while (minute >= 60) {
			hour++;
			minute = minute - 60;
		}
		while (hour >= 24) {
			day++;
			hour = hour - 24;
		}
	    while (!CheckDay()) {
			month++;
			day = day - LastDay();
		}
		while (month > 12) {
			year++;
			month = month - 12;
		}
		cout << day << "-" << month << "-" << year << " ";
		cout << hour << ":" << minute << ":" << second << endl;
	}
void Input_Time(TIME a[], int& n) {
	cin >> n;
	while (n <= 0 || n > 10000) {
		Input_Time(a, n);
	}
	for (int i = 0; i < n; i++) {
		cout << "Nhap ngay " << i+1 << endl;
		a[i].Input();
	}
}

