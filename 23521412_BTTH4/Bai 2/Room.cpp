#pragma once
#include "Room.h"

int Deluxe::doanhThu() {
    return soDem * 750000 + phiDichVu + phiPhucVu;
}

std::string Deluxe::loaiPhong() {
    return "Deluxe";
}

int Premium::doanhThu() {
    return soDem * 500000 + phiDichVu;
}

std::string Premium::loaiPhong() {
    return "Premium";
}

int Business::doanhThu() {
    return soDem * 300000;
}

std::string Business::loaiPhong() {
    return "Business";
}

Room* taoPhong(int loaiPhong, int soDem, int phiDichVu = 0, int phiPhucVu = 0) {
    if (loaiPhong == 1) {
        return new Deluxe(soDem, phiDichVu, phiPhucVu);
    } else if (loaiPhong == 2) {
        return new Premium(soDem, phiDichVu);
    } else if (loaiPhong == 3) {
        return new Business(soDem);
    } else {
        return NULL;
    }
}