
#include "DoiTuong.h"
#include <iostream>

DoiTuong::DoiTuong(int id, int loai, double sodu) : ID(id), Loai(loai), SoDu(sodu) {}

void DoiTuong::InThongTin() { 
    std::cout << ID << " " << Loai << " " << SoDu << std::endl;
}

int DoiTuong::layID() const { return ID; }

double DoiTuong::laySoDu() const { return SoDu; }

void DoiTuong::capNhatSoDu(double soTien) { SoDu += soTien; }

void DoiTuong::datSoDu(double sodu) { SoDu = sodu; }

int DoiTuong::layLoai() const { return Loai; }