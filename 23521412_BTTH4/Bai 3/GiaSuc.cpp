#pragma once
#include "GiaSuc.h"

GiaSuc::GiaSuc() : soLuong(0), soLuongBanDau(0), soLitSua(NULL), soLuongCon(0) {}

GiaSuc::GiaSuc(int sl) : soLuong(sl), soLuongBanDau(sl), soLuongCon(0) {
    soLitSua = new int[soLuong];
    sinhCon();
    choSua();
}

void GiaSuc::Nhap() {
    std::cout << "Nhap so luong: ";
    std::cin >> soLuong;
    soLuongBanDau = soLuong;
    soLitSua = new int[soLuong];
    sinhCon();
    choSua();
}

void GiaSuc::keu() const {
    for (int i = 0; i < soLuongBanDau; ++i) {
        keuMotLan();
    }
}

int GiaSuc::tinhTongLitSua() const {
    int tong = 0;
    for (int i = 0; i < soLuong; ++i) {
        tong += soLitSua[i];
    }
    return tong;
}

void GiaSuc::sinhCon() {
    int oldSoLuong = soLuong;
    for (int i = 0; i < oldSoLuong; ++i) {
        int con = rand() % 3;
        soLuong += con;
        soLuongCon += con; // Cập nhật số lượng con
    }
    // Cập nhật kích thước của mảng soLitSua
    int* newSoLitSua = new int[soLuong];
    for (int i = 0; i < oldSoLuong; ++i) {
        newSoLitSua[i] = soLitSua[i];
    }
    delete[] soLitSua;
    soLitSua = newSoLitSua;
}

int GiaSuc::getSoLuongCon() const {
    return soLuongCon;
}

void GiaSuc::choSua() {
    // Số lít sữa mỗi gia súc ngẫu nhiên trong giới hạn
    for (int i = 0; i < soLuong; ++i) {
        soLitSua[i] = rand() % 21; // Bò: 0-20 lít
    }
}

int GiaSuc::getSoLuong() const {
    return soLuong;
}

GiaSuc::~GiaSuc() {
    delete[] soLitSua;
}

Bo::Bo() : GiaSuc() {}
Bo::Bo(int sl) : GiaSuc(sl) {}

void Bo::keuMotLan() const {
    std::cout << "Boo ";
}

Cuu::Cuu() : GiaSuc() {}
Cuu::Cuu(int sl) : GiaSuc(sl) {}

void Cuu::keuMotLan() const {
    std::cout << "Mee ";
}

void Cuu::choSua() {
    for (int i = 0; i < soLuong; ++i) {
        soLitSua[i] = rand() % 6; // Cừu: 0-5 lít
    }
}

De::De() : GiaSuc() {}
De::De(int sl) : GiaSuc(sl) {}

void De::keuMotLan() const {
    std::cout << "Maa ";
}

void De::choSua() {
    for (int i = 0; i < soLuong; ++i) {
        soLitSua[i] = rand() % 11; // Dê: 0-10 lít
    }
}

void thongKe(const Bo* bo, const Cuu* cuu, const De* de) {
    int tongBo = bo->getSoLuong();
    int tongCuu = cuu->getSoLuong();
    int tongDe = de->getSoLuong();

    int tongLitSua = bo->tinhTongLitSua() + cuu->tinhTongLitSua() + de->tinhTongLitSua();

    std::cout << "Thong ke sau mot thoi gian chan nuoi:\n";
    std::cout << std::endl;
    std::cout << "So luong bo: " << tongBo << std::endl;
    std::cout << "Sau thoi gian chan nuoi, dan bo cho so lit sua la: " << bo->tinhTongLitSua() << " lit" << std::endl;
    std::cout << "Sau thoi gian chan nuoi, so luong con moi sinh ra cua dan bo la: " << bo->getSoLuongCon() << std::endl;
    std::cout << std::endl;
    std::cout << "So luong cuu: " << tongCuu << std::endl;
    std::cout << "Sau thoi gian chan nuoi, dan cuu cho so lit sua la: " << cuu->tinhTongLitSua() << " lit" << std::endl;
    std::cout << "Sau thoi gian chan nuoi, so luong con moi sinh ra cua dan cuu la: " << cuu->getSoLuongCon() << std::endl;
    std::cout << std::endl;
    std::cout << "So luong de: " << tongDe << std::endl;
    std::cout << "Sau thoi gian chan nuoi, dan de cho so lit sua la: " << de->tinhTongLitSua() << " lit" << std::endl;
    std::cout << "Sau thoi gian chan nuoi, so luong con moi sinh ra cua dan de la: " << de->getSoLuongCon() << std::endl;
    std::cout << "Tong so lit sua: " << tongLitSua << " lit" << std::endl;
}