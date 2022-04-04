#include "student.h"
void main()
{
    student hoc_sinh[10000];
    int so_luong;
    Number(so_luong);
    for (int i = 0; i < so_luong; i++) {
        hoc_sinh[i].Input();
        cout << endl;
    }
    cout << "--------------------";
    cout << "\nNhung hoc sinh co tong diem tren 25: \n";
    for (int i = 0; i < so_luong; i++) {
        if (hoc_sinh[i].sum() > 25.0) {
            hoc_sinh[i].Output();
            cout << endl;
        }
    }
    cout << "--------------------";
    cout << "\nNhung hoc sinh nu co tong diem > 28";
    cout << "\nCo " << Number_of_female_students_over_28score(hoc_sinh, so_luong) << " hoc sinh.\n";
    for (int i = 0; i < so_luong; i++) {
        if (hoc_sinh[i].sum() > 28.0 && hoc_sinh[i].sex_female()) {
            hoc_sinh[i].Output();
            cout << endl;
        }
    }
    cout << "--------------------\n";
    cout << "Nhung hoc sinh dau truong X: ";
    cout << "\nCo " << students_pass_X_school(hoc_sinh, so_luong) << " hoc sinh." << endl;
    for (int i = 0; i < so_luong; i++) {
        if (hoc_sinh[i].sum() > 18.0) {
            if (hoc_sinh[i].Inspect()) {
                hoc_sinh[i].Output();
                cout << endl;
            }
        }
    }
}