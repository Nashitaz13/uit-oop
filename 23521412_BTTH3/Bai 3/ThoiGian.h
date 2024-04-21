#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class ThoiGian
{
private:
    int iGio, iPhut, iGiay;
public:
    ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}  
    ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {} 
    int TinhGiay(); 
    void TinhLaiGio(int Giay); 
    friend istream& operator >> (istream& is, ThoiGian& T);
    friend ostream& operator << (ostream& os, ThoiGian& T);
    ThoiGian operator++ (); 
    ThoiGian operator-- (); 
    ThoiGian operator+(int Giay); 
    ThoiGian operator-(int Giay); 
    ThoiGian operator+(ThoiGian& Ts); 
    ThoiGian operator-(ThoiGian& Ts); 
    friend bool operator<(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator>=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator<=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator!=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator==(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator>(const ThoiGian& T1, const ThoiGian& T2);
};
