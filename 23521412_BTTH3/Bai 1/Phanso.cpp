#pragma once
#include "PhanSo.h"
#include <iostream>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

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