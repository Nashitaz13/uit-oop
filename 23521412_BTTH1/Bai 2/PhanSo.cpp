#pragma once
#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

public:
    void Nhap();
    void Xuat();
    void RutGon();
    PhanSo Tong(PhanSo ps);
    PhanSo Hieu(PhanSo ps);
    PhanSo Tich(PhanSo ps);
    PhanSo Thuong(PhanSo ps);
    int SoSanh(PhanSo ps);
};

void PhanSo::Nhap() {
    cout << "Nhap phan so thoa man." << endl;
    cout << "Nhap tu so: ";
    cin >> iTu;
   do
	{
		cout<<"Nhap Mau so: "; 
		cin>> iMau;
		if(iMau==0)
			cout<<"Nhap sai, yeu cau nhap lai mau so: ";
	}while(iMau==0);
}

void PhanSo::Xuat() {
    if (iMau == 0) {
        cout << "Khong ton tai phan so nay" << endl;
    } else if (iTu == 0) {
        cout << 0 << endl;
    } else if (iTu == iMau) {
        cout << 1 << endl;
    } else if (iTu % iMau == 0) {
        cout << iTu / iMau << endl;
    } else {
        if (iMau < 0) {
            cout << iTu * -1 << "/" << abs(iMau) << endl;
        } else {
            cout << iTu << "/" << iMau << endl;
        }
    }
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
}

PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo tong;
    tong.iTu = this->iTu * ps.iMau + this->iMau * ps.iTu;
    tong.iMau = this->iMau * ps.iMau;
    tong.RutGon();
    return tong;
}

PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo hieu;
    hieu.iTu = this->iTu * ps.iMau - this->iMau * ps.iTu;
    hieu.iMau = this->iMau * ps.iMau;
    hieu.RutGon();
    return hieu;
}

PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo tich;
    tich.iTu = this->iTu * ps.iTu;
    tich.iMau = this->iMau * ps.iMau;
    tich.RutGon();
    return tich;
}

PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo thuong;
    thuong.iTu = this->iTu * ps.iMau;
    thuong.iMau = this->iMau * ps.iTu;
    thuong.RutGon();
    return thuong;
}

int PhanSo::SoSanh(PhanSo ps) {
    float soSanh1 = static_cast<float>(this->iTu) / this->iMau; 
    float soSanh2 = static_cast<float>(ps.iTu) / ps.iMau;
    if (soSanh1 > soSanh2) {
        return 1;
    } else if (soSanh1 < soSanh2) {
        return -1;
    } else {
        return 0;
    }
}
