
#include "Fraction.h"
void main()
{
    Fraction a, b, c;
    a.Input();
    b.Input();
    cout << "Phan so dau tien sau ru gon: ";
    a.Out();
    cout << "\n----------------------" << endl;
    c.Plus(a, b);
    cout << "Tong 2 ps: ";
    c.Out();
    cout << "\nMultiply 2 ps: ";
    c.Multiply(a, b);
    c.Out();
    cout << "\nDivision 2 ps: ";
    c.Division(a, b);
    cout << "\nDeduct 2 ps: ";
    c.Deduct(a, b);
    c.Out();
    cout << "\n--------------------"<< endl;
    int n;
    Fraction k[10000], d[10000];
    Input_sequence_of_Fractions(d, k, n);
    Arrange(k, n);
    cout << "Mang ps sau khi sap xep: " << endl;
    Output(k,n);
}
