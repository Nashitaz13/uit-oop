#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay = 1);
    int TinhNgay() const;
    NgayThangNam operator+(int ngay) const;
    NgayThangNam operator-(int ngay) const;
    NgayThangNam operator++();
    NgayThangNam operator--();
    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
    int operator-(NgayThangNam &a);
    friend bool operator == (const NgayThangNam& a, const NgayThangNam& b);
    friend bool operator != (const NgayThangNam& a, const NgayThangNam& b);
    friend bool operator >= (const NgayThangNam& a, const NgayThangNam& b);
    friend bool operator <= (const NgayThangNam& a, const NgayThangNam& b);
    friend bool operator > (const NgayThangNam& a, const NgayThangNam& b);
    friend bool operator < (const NgayThangNam& a, const NgayThangNam& b);
};
