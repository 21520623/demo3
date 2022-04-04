#pragma once
#include <iostream>
using namespace std;
void Number(int& n);
class student
{
public:
    int ma;
    char hoten[20];
    char gioitinh;
    int date, month, year;
    float Toan, Van, Anh;
public:
    void Input();
    bool CheckYear();
    void Input_day();
    void Output();
    float sum();
    int sex_female();
    int Inspect();
};
int Number_of_female_students_over_28score(student a[], int n);
int students_pass_X_school(student a[], int n);
