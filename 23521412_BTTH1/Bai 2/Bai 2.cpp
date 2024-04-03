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
