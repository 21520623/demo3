// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Fraction.h"
    void Fraction::Input() {
        cout << "Input phan so: ";
        cin >> tuso >> mauso;
        while (mauso == 0) {
            cout << "Phan so khong hop le. Vui long Input lai." << endl;
            Input();
        }
    }
    int Fraction::Greatest_common_divisor() {
        int tu_rg = tuso, mau_rg = mauso;
        if (tuso < 0) tu_rg = tu_rg * (-1);
        if (mauso < 0) mau_rg = mau_rg * (-1);
        if (tu_rg == 0 || tu_rg == 1) return tu_rg;
        if (tu_rg > mau_rg) swap(tu_rg, mau_rg);
        int uocchung = 1;
        for (int i = tu_rg; i <= mau_rg; i++) {
            if (tu_rg % i == 0 && mau_rg % i == 0)
                uocchung = i;
        }
        return uocchung;
    }
    void Fraction::Reduce() {
        int tu, mau;
        if (Greatest_common_divisor() == 0) {
            tuso = 0;
        }
        else {
            tu = tuso / Greatest_common_divisor();
            mau = mauso / Greatest_common_divisor();
            tuso = tu;
            mauso = mau;
        }
    }
    void Fraction::Out() {
        Reduce();
        if (tuso == 0 || mauso == 1) {
            cout << tuso;
        }
        else {
            if (mauso < 0) {
                if (mauso == -1) cout << tuso * (-1);
                else cout << tuso * (-1) << "/" << mauso * (-1);
            }
            else cout << tuso << "/" << mauso;
        }
    }
    void Fraction::Plus(Fraction a, Fraction b) {
        tuso = a.tuso * b.mauso + a.mauso * b.tuso;
        mauso = a.mauso * b.mauso;
    }
    void Fraction::Deduct(Fraction a, Fraction b) {
        tuso = a.tuso * b.mauso - b.tuso * a.mauso;
        mauso = a.mauso * b.mauso;
    }
    void Fraction::Multiply(Fraction a, Fraction b) {
        tuso = a.tuso * b.tuso;
        mauso = a.mauso * b.mauso;
    }
    void Fraction::Division(Fraction a, Fraction b) {
        if (b.tuso == 0) {
            cout << "Khong Division duoc.";
        }
        else {
            tuso = a.tuso * b.mauso;
            mauso = a.mauso * b.tuso;
            Out();
        }
    }
    void Fraction::Input_Unconditioned() {
        cout << "Input ps: ";
        cin >> tuso >> mauso;
    }
    bool More_little(Fraction x, Fraction y) {
        Fraction e;
        e.Deduct(x, y);
        if (((float)e.tuso / e.mauso) > 0) return false;
        else return true;
    }
    void Input_sequence_of_Fractions(Fraction d[], Fraction k[], int& n) {
        cout << "Input so luong: ";
        int j = 0;
        cin >> n;
        while (n <= 0 || n > 10000) {
            Input_sequence_of_Fractions(d, k, n);
        }
        for (int i = 0; i < n; i++) {
            d[i].Input_Unconditioned();
            if (d[i].mauso != 0) {
                k[j] = d[i];
                j++;
            }
            else continue;
        }
        n = j;
    }
    void Arrange(Fraction k[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (More_little(k[i], k[j])) swap(k[i], k[j]);
            }
        }
    }
    void Output(Fraction k[], int n) {
        for (int i = 0; i < n; i++) {
            k[i].Out();
            cout << endl;
        }
    }