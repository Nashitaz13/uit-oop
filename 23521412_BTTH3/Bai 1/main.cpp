#include "Phanso.cpp"
#include <iostream>
#include <math.h>

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
