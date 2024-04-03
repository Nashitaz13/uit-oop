#include "SoPhuc.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    SoPhuc a, b, tong, hieu, tich, thuong;

    cout << "Nhap so phuc a:\n";
    a.Nhap();
    cout << "Nhap so phuc b:\n";
    b.Nhap();

    tong = a.Tong(b);
    hieu = a.Hieu(b);
    tich = a.Tich(b);
    thuong = a.Thuong(b);

    cout << "Tong cua a va b la: ";
    tong.Xuat();
    cout << "Hieu cua a va b la: ";
    hieu.Xuat();
    cout << "Tich cua a va b la: ";
    tich.Xuat();
    cout << "Thuong cua a va b la: ";
    thuong.Xuat();

    return 0;
}
