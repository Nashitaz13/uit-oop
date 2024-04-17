#include<iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

class PhanSo {
private:
    int iTu;
    int iMau;
public:
    // Constructor
    PhanSo() : iTu(0), iMau(1) {}
    PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {}
    // Operator Overloading
    friend PhanSo operator + (PhanSo a, PhanSo b);
    friend PhanSo operator - (PhanSo a, PhanSo b);
    friend PhanSo operator * (PhanSo a, PhanSo b);
    friend PhanSo operator / (PhanSo a, PhanSo b);
    friend bool operator == (PhanSo a, PhanSo b);
    friend bool operator != (PhanSo a, PhanSo b);
    friend bool operator >= (PhanSo a, PhanSo b);
    friend bool operator <= (PhanSo a, PhanSo b);
    friend bool operator > (PhanSo a, PhanSo b);
    friend bool operator < (PhanSo a, PhanSo b);
    friend ostream& operator << (ostream& os, PhanSo a);
    friend istream& operator >> (istream& is, PhanSo& a);
};

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo result;
    result.iTu = a.iTu * b.iMau + b.iTu * a.iMau;
    result.iMau = a.iMau * b.iMau;
    return result;
}

PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo result;
    result.iTu = a.iTu * b.iMau - b.iTu * a.iMau;
    result.iMau = a.iMau * b.iMau;
    return result;
}

PhanSo operator * (PhanSo a, PhanSo b) {
    return PhanSo(a.iTu * b.iTu, a.iMau * b.iMau);
}

PhanSo operator / (PhanSo a, PhanSo b) {
    return PhanSo(a.iTu * b.iMau, a.iMau * b.iTu);
}

bool operator == (PhanSo a, PhanSo b) {
    return a.iTu * b.iMau == a.iMau * b.iTu;
}

bool operator != (PhanSo a, PhanSo b) {
    return !(a == b);
}

bool operator >= (PhanSo a, PhanSo b) {
    return a.iTu * b.iMau >= a.iMau * b.iTu;
}

bool operator <= (PhanSo a, PhanSo b) {
    return a.iTu * b.iMau <= a.iMau * b.iTu;
}

bool operator > (PhanSo a, PhanSo b) {
    return !(a <= b);
}

bool operator < (PhanSo a, PhanSo b) {
    return !(a >= b);
}

ostream& operator << (ostream& os, PhanSo a) {
    int gcdVal = gcd(abs(a.iTu), abs(a.iMau));
    a.iTu /= gcdVal;
    a.iMau /= gcdVal;
    if (a.iMau == 0) {
        cout << "Khong ton tai phan so nay" << endl;
    } else if (a.iTu == 0) {
        cout << 0 << endl;
    } else if (a.iTu == a.iMau) {
        cout << 1 << endl;
    } else if (a.iTu % a.iMau == 0) {
        cout << a.iTu / a.iMau << endl;
    } else {
        if (a.iMau < 0) {
            cout << a.iTu * -1 << "/" << abs(a.iMau) << endl;
        } else {
            cout << a.iTu << "/" << a.iMau << endl;
        }
    }
    return os;
}

istream& operator >> (istream& is, PhanSo& a) {
    cout << "Nhap tu so: ";
    is >> a.iTu;
    do {
        cout << "Nhap mau so (khac 0): ";
        is >> a.iMau;
    } while (a.iMau == 0);
    return is;
}

int main() {
    PhanSo a, b, c;

    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;
    c = a + b;
    cout << a << " + " << b << " = " << c << endl;
    c = a - b;
    cout << a << " - " << b << " = " << c << endl;
    c = a * b;
    cout << a << " * " << b << " = " << c << endl;
    c = a / b;
    cout << a << " / " << b << " = " << c << endl;
    if (a == b)
        cout << a << " bang " << b << "\n";
    else
        cout << a << " khong bang " << b << "\n";
    if (a != b)
        cout << a << " khac " << b << "\n";
    else
        cout << a << " giong " << b << "\n";
    if (a >= b)
        cout << a << " lon hon hoac bang " << b << "\n";
    else
        cout << a << " nho hon " << b << "\n";
    if (a <= b)
        cout << a << " nho hon hoac bang " << b << "\n";
    else
        cout << a << " lon hon " << b << "\n";
    if (a > b)
        cout << a << " lon hon " << b << "\n";
    else
        cout << a << " khong lon hon " << b << "\n";
    if (a < b)
        cout << a << " nho hon " << b << "\n";
    else
        cout << a << " khong nho hon " << b << "\n";
    cout << endl;
    PhanSo d();
    PhanSo e(1, 2);
    PhanSo g(3, 2);
    cout << d << endl;
    cout << e << endl;
    PhanSo f;
    f = g + e;
    cout << f << endl;
    return 0;
}

