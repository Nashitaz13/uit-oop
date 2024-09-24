
#include "CoMoi.h"
#include <cmath>

CoMoi::CoMoi(int id, int traderId) : DoiTuong(id, 2, 0), TraderID(traderId) {}

void CoMoi::InThongTin() { 
    std::cout << ID << " " << Loai << " " << TraderID << std::endl;
}

void CoMoi::ChiaSeHoaHong(double giaoDich) {
    double hoaHong = giaoDich * 0.01;
    hoaHong = std::round(hoaHong * 100) / 100;
    capNhatSoDu(hoaHong);
}

int CoMoi::layTraderID() const { return TraderID; }
