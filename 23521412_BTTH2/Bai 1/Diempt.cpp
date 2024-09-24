#pragma once
#include <bits/stdc++.h>
#include "Diem.cpp"
using namespace std;



// Hàm khởi tạo mặc định
Diem::Diem()
{
    iHoanh = 0;
    iTung = 0;
}

// Hàm khởi tạo có tham số
Diem::Diem(int Hoanh, int Tung)
{
    iHoanh = Hoanh;
    iTung = Tung;
}

// Hàm khởi tạo sao chép
Diem::Diem(const Diem &x)
{
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

// Xuất thông tin điểm
void Diem::Xuat()
{
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

// Lấy giá trị tung độ
int Diem::GetTungDo()
{
    return iTung;
}

// Lấy giá trị hoành độ
int Diem::GetHoanhDo()
{
    return iHoanh;
}

// Thiết lập giá trị tung độ mới
void Diem::SetTungDo(int Tung)
{
    iTung = Tung;
}

// Thiết lập giá trị hoành độ mới
void Diem::SetHoanhDo(int Hoanh)
{
    iHoanh = Hoanh;
}

// Di chuyển điểm một khoảng dx theo trục hoành và dy theo trục tung
void Diem::TinhTien(int dx, int dy)
{
    iHoanh += dx;
    iTung += dy;
}