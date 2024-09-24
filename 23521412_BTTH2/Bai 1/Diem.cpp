#pragma once
#include <bits/stdc++.h>

using namespace std;

class Diem
{
private:
    int iHoanh;
    int iTung;
public:
    Diem();
    Diem(int Hoanh, int Tung);
    Diem(const Diem &x);
    void Xuat();
    int GetTungDo();
    int GetHoanhDo();
    void SetTungDo(int Tung);
    void SetHoanhDo(int Hoanh);
    void TinhTien(int dx, int dy);
};
