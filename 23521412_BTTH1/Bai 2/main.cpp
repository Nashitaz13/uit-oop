#include "PhanSo.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    ps1.Nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.Nhap();

    PhanSo tong = ps1.Tong(ps2);
    cout << "Tong hai phan so la: ";
    tong.Xuat();

    PhanSo hieu = ps1.Hieu(ps2);
    cout << "Hieu hai phan so la: ";
    hieu.Xuat();

    PhanSo tich = ps1.Tich(ps2);
    cout << "Tich hai phan so la: ";
    tich.Xuat();

    PhanSo thuong = ps1.Thuong(ps2);
    cout << "Thuong hai phan so la: ";
    thuong.Xuat();

    int soSanh = ps1.SoSanh(ps2);
    if (soSanh > 0) {
        cout << "Phan so thu nhat lon hon phan so thu hai.\n";
    } else if (soSanh < 0) {
        cout << "Phan so thu nhat nho hon phan so thu hai.\n";
    } else {
        cout << "Hai phan so bang nhau.\n";
    }

    return 0;
}