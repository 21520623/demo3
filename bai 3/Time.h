#pragma once
#include <iostream>
using namespace std;
class TIME {
private:
	int day, month, year;
	int hour, minute, second;
public:
	void Input();
	bool CheckYear();
	void Output_bissextile();
	bool CheckDay();
	int LastDay();
	void Change_second_to_hour_minute_second();
};
void Input_Time(TIME a[], int& n);