#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class GiaSuc {
protected:
    int soLuong;
    int soLuongBanDau;
    int* soLitSua;
    int soLuongCon;
public:
    GiaSuc();
    GiaSuc(int sl);
    virtual void Nhap();
    virtual void keu() const;
    virtual void keuMotLan() const = 0;
    int tinhTongLitSua() const;
    void sinhCon();
    int getSoLuongCon() const;
    virtual void choSua();
    int getSoLuong() const;
    virtual ~GiaSuc();
};

class Bo : public GiaSuc {
public:
    Bo();
    Bo(int sl);
    void keuMotLan() const override;
};

class Cuu : public GiaSuc {
public:
    Cuu();
    Cuu(int sl);
    void keuMotLan() const override;
    void choSua() override;
};

class De : public GiaSuc {
public:
    De();
    De(int sl);
    void keuMotLan() const override;
    void choSua() override;
};