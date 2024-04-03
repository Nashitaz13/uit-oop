#pragma once
#include<bits/stdc++.h>
using namespace std;

class GioPhutGiay {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};

void GioPhutGiay::Nhap() {
    do {
        cout << "Nhap gio: ";
        cin >> iGio;
    } while (iGio < 0 || iGio >= 24);

    do {
        cout << "Nhap phut: ";
        cin >> iPhut;
    } while (iPhut < 0 || iPhut >= 60);

    do {
        cout << "Nhap giay: ";
        cin >> iGiay;
    } while (iGiay < 0 || iGiay >= 60);
}


void GioPhutGiay::Xuat() {
    cout << "Thoi gian: ";
    cout << setfill('0') << setw(2) << iGio << ":";
    cout << setfill('0') << setw(2) << iPhut << ":";
    cout << setfill('0') << setw(2) << iGiay << endl;
}


void GioPhutGiay::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay == 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut == 60) {
            iPhut = 0;
            iGio++;
            if (iGio == 24) {
                iGio = 0;
            }
        }
    }
}
