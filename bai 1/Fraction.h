#pragma once
#include <iostream>
using namespace std;
class Fraction {
public:
	int tuso;
	int mauso;
public:
	void Input();
	int Greatest_common_divisor();
	void Reduce();
	void Out();
	void Plus(Fraction a, Fraction b);
	void Deduct(Fraction a, Fraction b);
	void Multiply(Fraction a, Fraction b);
	void Division(Fraction a, Fraction b);
	void Input_Unconditioned();
};
void Input_sequence_of_Fractions(Fraction d[], Fraction k[], int& n);
bool More_little(Fraction x, Fraction y);
void Arrange(Fraction k[], int n);
void Output(Fraction k[], int n);