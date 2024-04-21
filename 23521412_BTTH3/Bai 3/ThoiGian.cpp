#pragma once
#include "ThoiGian.h"
#include <iostream>
#include <iomanip>
#include <math.h>

int ThoiGian::TinhGiay() 
{
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) 
{
    iGio = Giay / 3600;
    int GiayConLai = Giay % 3600;
    iPhut = GiayConLai / 60;
    iGiay = GiayConLai % 60;
}

istream& operator >> (istream& is, ThoiGian& T) 
{
    do {
        cout << "Nhap gio (0-23): ";
        is >> T.iGio;
    } while (T.iGio < 0 || T.iGio > 23);

    do {
        cout << "Nhap phut (0-59) = ";
        is >> T.iPhut;
    } while (T.iPhut < 0 || T.iPhut > 59);

    do {
        cout << "Nhap giay (0-59) = ";
        is >> T.iGiay;
    } while (T.iGiay < 0 || T.iGiay > 59);

    return is;
}

ostream& operator << (ostream& os, ThoiGian& T) 
{
    if (T.iGio == 24) {os << "00:";}
    else
    {
        os << setfill('0') << setw(2) << T.iGio << ":";
    }
       os << setfill('0') << setw(2) << T.iPhut << ":"
       << setfill('0') << setw(2) << T.iGiay << endl;
    return os;
}

ThoiGian ThoiGian::operator++ () 
{
    ++iGiay;        
    if (iGiay >= 60)
    {
        ++iPhut;
        iGiay -= 60;
    }
    if (iPhut >= 60)
    {
        ++iGio;
        iPhut -= 60;
    }
    return ThoiGian(iGio, iPhut, iGiay);
}

ThoiGian ThoiGian::operator-- () 
{
    --iGiay;        
    if (iGiay < 0)
    {
        --iPhut;
        iGiay += 60;
    }
    if (iPhut < 0)
    {
        --iGio;
        iPhut += 60;
    }
    return ThoiGian(iGio, iPhut, iGiay);
}

ThoiGian ThoiGian::operator+(int Giay) 
{
    ThoiGian T = *this;
    T.iGiay += Giay;
    while (T.iGiay >= 60)
    {
        ++T.iPhut;
        T.iGiay -= 60;
    }
    while (T.iPhut >= 60)
    {
        ++T.iGio;
        T.iPhut -= 60;
    }
    return T;
}

ThoiGian ThoiGian::operator-(int Giay) 
{
    ThoiGian T = *this;
    T.iGiay -= Giay;
    while (T.iGiay < 0)
    {
        --T.iPhut;
        T.iGiay += 60;
    }
    while (T.iPhut < 0)
    {
        --T.iGio;
        T.iPhut += 60;
    }
    return T;
}

ThoiGian ThoiGian::operator+(ThoiGian& Ts) 
{
    ThoiGian T;
    T.iGio = this->iGio + Ts.iGio;
    T.iPhut = this->iPhut + Ts.iPhut;
    T.iGiay = this->iGiay + Ts.iGiay;
    if (T.iGiay >= 60)
    {
        ++T.iPhut;
        T.iGiay -= 60;
    }
    if (T.iPhut >= 60)
    {
        ++T.iGio;
        T.iPhut -= 60;
    }
    if (T.iGio >= 24)
    {
       T.iGio = T.iGio % 24;
    }
    return T;
}

ThoiGian ThoiGian::operator-(ThoiGian& Ts) 
{
    ThoiGian T;
    T.iGio = this->iGio - Ts.iGio;
    T.iPhut = this->iPhut - Ts.iPhut;
    T.iGiay = this->iGiay - Ts.iGiay;

    // Đảo dấu nếu kết quả là âm
    if (T.iGiay < 0)
    {
        --T.iPhut;
        T.iGiay += 60;
    }
    if (T.iPhut < 0)
    {
        --T.iGio;
        T.iPhut += 60;
    }
    if (T.iGio < 0)
    {
        T.iGio = abs(T.iGio);
        T.iPhut = abs(T.iPhut);
        T.iGiay = abs(T.iGiay);
    }
    return T;
}


bool operator<(const ThoiGian& T1, const ThoiGian& T2)
{
    if (T1.iGio < T2.iGio)
        return true;
    else if (T1.iGio == T2.iGio && T1.iPhut < T2.iPhut)
        return true;
    else if (T1.iGio == T2.iGio && T1.iPhut == T2.iPhut && T1.iGiay < T2.iGiay)
        return true;
    else
        return false;
}

bool operator>(const ThoiGian& T1,const ThoiGian& T2)
{
    return !(T1 < T2) && !(T1 == T2);
}

bool operator==(const ThoiGian& T1, const ThoiGian& T2)
{
    return T1.iGio == T2.iGio && T1.iPhut == T2.iPhut && T1.iGiay == T2.iGiay;
}

bool operator!=(const ThoiGian& T1,const ThoiGian& T2)
{
    return !(T1 == T2);
}

bool operator<=(const ThoiGian& T1,const ThoiGian& T2)
{
    return (T1 < T2) || (T1 == T2);
}

bool operator>=(const ThoiGian& T1,const ThoiGian& T2)
{
    return (T1 > T2) || (T1 == T2);
}