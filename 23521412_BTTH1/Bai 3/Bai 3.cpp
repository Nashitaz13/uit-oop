#pragma once
#include <bits/stdc++.h>
using namespace std;

class SoPhuc {
    private:
        double iThuc, iAo;
    public:
        void Nhap();
        void Xuat();
        SoPhuc Tong(SoPhuc b);
        SoPhuc Hieu(SoPhuc b);
        SoPhuc Tich(SoPhuc b);
        SoPhuc Thuong(SoPhuc b);
};

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void SoPhuc::Xuat() {
    cout << "So phuc: " << iThuc;
    if (iAo >= 0) {
        cout << " + " << iAo << "i" << endl;
    } else {
        cout << " - " << -iAo << "i" << endl;
    }
}


SoPhuc SoPhuc::Tong(SoPhuc b) {
    SoPhuc tong;
    tong.iThuc = this->iThuc + b.iThuc;
    tong.iAo = this->iAo + b.iAo;
    return tong;
}

SoPhuc SoPhuc::Hieu(SoPhuc b) {
    SoPhuc hieu;
    hieu.iThuc = this->iThuc - b.iThuc;
    hieu.iAo = this->iAo - b.iAo;
    return hieu;
}

SoPhuc SoPhuc::Tich(SoPhuc b) {
    SoPhuc tich;
    tich.iThuc = this->iThuc * b.iThuc - this->iAo * b.iAo;
    tich.iAo = this->iThuc * b.iAo + this->iAo * b.iThuc;
    return tich;
}

SoPhuc SoPhuc::Thuong(SoPhuc b) {
    SoPhuc thuong;
    double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (mau == 0) {
        cout << "Loi: Khong the chia cho 0!" << endl;
        return *this;
    }
    thuong.iThuc = (this->iThuc * b.iThuc + this->iAo * b.iAo) / mau;
    thuong.iAo = (this->iAo * b.iThuc - this->iThuc * b.iAo) / mau;
    return thuong;
}


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

