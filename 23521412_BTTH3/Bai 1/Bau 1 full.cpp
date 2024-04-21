#include<iostream>
#include <math.h>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;
public:
    PhanSo() : iTu(0), iMau(1) {}
    PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {}
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

int main() {
    PhanSo ps1, ps2;
    PhanSo ps3;
    PhanSo ps4(-2, 4);
    PhanSo ps5(9, 0);

    cout << "Nhap phan so thu nhat: ";
    cin >> ps1;
    cout << "Nhap phan so thu hai: ";
    cin >> ps2;

    cout << "Phan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;
    cout << "Phan so thu ba: " << ps3 << endl;
    cout << "Phan so thu bon: " << ps4 << endl;
    cout << "Phan so thu nam: " << ps5 << endl;

    ps3 = ps1 + ps2;
    cout << "Tong hai phan so 1 va 2: " << ps3 << endl;

    ps3 = ps1 - ps2;
    cout << "Hieu hai phan so 1 va 2: " << ps3 << endl;

    ps3 = ps1 * ps2;
    cout << "Tich hai phan so 1 va 2: " << ps3 << endl;

    ps3 = ps1 / ps2;
    cout << "Thuong hai phan so 1 va 2: " << ps3 << endl;

    if (ps1 == ps4) {
        cout << "Hai phan so 1 va 4 bang nhau." << endl;
    }
    else {
        cout << "Hai phan so 1 va 4 khong bang nhau." << endl;
    }

    if (ps1 != ps2) {
        cout << "Hai phan so 1 va 2 khac nhau." << endl;
    }
    else {
        cout << "Hai phan so giong nhau." << endl;
    }

    if (ps1 > ps2) {
        cout << "Phan so 1 lon hon phan so 2." << endl;
    }
    else {
        cout << "Phan so 1 khong lon hon phan so 2." << endl;
    }

    if (ps1 < ps2) {
        cout << "Phan so 1 nho hon phan so 2." << endl;
    }
    else {
        cout << "Phan so 1 khong nho hon phan so 2." << endl;
    }

    if (ps1 >= ps2) {
        cout << "Phan so 1 lon hon hoac bang phan so 2." << endl;
    }
    else {
        cout << "Phan so 1 khong lon hon hoac bang phan so 2." << endl;
    }

    if (ps1 <= ps2) {
        cout << "Phan so 1 nho hon hoac bang phan so 2." << endl;
    }
    else {
        cout << "Phan so 1 khong nho hon hoac bang phan so 2." << endl;
    }

    return 0;
}

