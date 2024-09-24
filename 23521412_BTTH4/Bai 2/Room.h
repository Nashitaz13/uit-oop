#pragma once
#include <iostream>

class Room {
protected:
    int soDem;
    int phiDichVu;
public:
    Room(int soDem, int phiDichVu = 0) : soDem(soDem), phiDichVu(phiDichVu) {}
    virtual int doanhThu() = 0;
    virtual std::string loaiPhong() = 0;
};

class Deluxe : public Room {
private:
    int phiPhucVu;
public:
    Deluxe(int soDem, int phiDichVu, int phiPhucVu)
    : Room(soDem, phiDichVu), phiPhucVu(phiPhucVu) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};

class Premium : public Room {
public:
    Premium(int soDem, int phiDichVu) 
    : Room(soDem, phiDichVu) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};

class Business : public Room {
public:
    Business(int soDem) : Room(soDem) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};