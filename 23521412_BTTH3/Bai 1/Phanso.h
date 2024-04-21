#pragma once
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