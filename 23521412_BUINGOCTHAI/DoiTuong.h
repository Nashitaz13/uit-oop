#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
const int MAX_DOITUONG = 1000;
const int MAX_CUOC = 1000;


class DoiTuong {
protected:
    int ID;
    int Loai;
    double SoDu;
public:
    DoiTuong(int id, int loai, double sodu);
    virtual void InThongTin();
    int layID() const;
    double laySoDu() const;
    void capNhatSoDu(double soTien);
    void datSoDu(double sodu);
    int layLoai() const;
};
