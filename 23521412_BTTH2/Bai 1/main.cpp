#include "Diempt.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Diem A; // Tạo điểm A mặc định
    A.Xuat(); // Xuất thông tin điểm A (0, 0)

    Diem B(2, 3); // Tạo điểm B với hoành độ 2 và tung độ 3
    B.Xuat(); // Xuất thông tin điểm B (2, 3)

    Diem C(B); // Tạo điểm C là bản sao của điểm B
    C.Xuat(); // Xuất thông tin điểm C (2, 3)

    C.SetHoanhDo(5); // Thiết lập hoành độ mới cho điểm C
    C.Xuat(); // Xuất thông tin điểm C (5, 3)

    C.TinhTien(1, -1); // Di chuyển điểm C 1 đơn vị sang phải và 1 đơn vị xuống dưới
    C.Xuat(); // Xuất thông tin điểm C (6, 2)

    return 0;
}