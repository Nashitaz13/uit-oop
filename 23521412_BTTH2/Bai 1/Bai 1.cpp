#include <bits/stdc++.h>

using namespace std;

class Diem
{
private:
    int iHoanh;
    int iTung;
public:
    Diem();
    Diem(int Hoanh, int Tung);
    Diem(const Diem &x);
    void Xuat();
    int GetTungDo();
    int GetHoanhDo();
    void SetTungDo(int Tung);
    void SetHoanhDo(int Hoanh);
    void TinhTien(int dx, int dy);
};

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
    cout << C.GetHoanhDo(); // In ra hoanh do diem C
    cout << C.GetTungDo(); // In ra tung do diem C
    cout << endl;
    return 0;
}
