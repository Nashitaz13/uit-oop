#include "NgayThangNam.cpp"
#include <iostream>

int main() {
    NgayThangNam date1, date2(2024, 4, 9);
    std::cout << "Nhap ngay thang nam cho ngay thang nam (1) (dd/mm/yyyy): ";
    std::cin >> date1;
    std::cout << "Ngay thang nam (1): " << date1 << std::endl;
    std::cout << "Ngay thang nam (2): " << date2 << std::endl;
    std::cout << "So ngay trong nam cua ngay thang nam (1): " << date1.TinhNgay() << std::endl;
    std::cout << "So ngay giua hai thoi diem " << date1 << " va " << date2 << ": " << (date2 - date1) << std::endl;
    std::cout << date1 << " = " <<  date2 << " ? " << (date1 == date2 ? "Yes" : "No") << std::endl;
    std::cout << date1 << " != " <<  date2 << " ? " << (date1 != date2 ? "Yes" : "No") << std::endl;
    std::cout << date1 << " >= " <<  date2 << " ? " << (date1 >= date2 ? "Yes" : "No") << std::endl;
    std::cout << date1 << " <= " <<  date2 << " ? " << (date1 <= date2 ? "Yes" : "No") << std::endl;
    std::cout << date1 << " > " <<  date2 << " ? " << (date1 > date2 ? "Yes" : "No") << std::endl;
    std::cout << date1 << " < " <<  date2 << " ? "  << (date1 < date2 ? "Yes" : "No") << std::endl;
    std::cout << "Tang (1) len 1 ngay: " << ++date1 << std::endl;
    std::cout << "Giam (2) di 1 ngay: " << --date2 << std::endl;

    NgayThangNam dt1, dt2;
    std::cout << "Nhap ngay thang nam (3): ";
    std::cin >> dt1;
    std::cout << "Nhap ngay thang nam (4): ";
    std::cin >> dt2;
    std::cout << "Ngay thang nam (3): " << dt1 << std::endl;
    std::cout << "Ngay thang nam (4): " << dt2 << std::endl;
    std::cout << "So ngay trong nam cua ngay thang nam (3): " << dt1.TinhNgay() << std::endl;
    std::cout << "So ngay trong nam cua ngay thang nam (4): " << dt2.TinhNgay() << std::endl;
    std::cout << "So ngay giua hai thoi diem " << dt1 << " va " << dt2 << ": " << (dt2 - dt1) << std::endl;
    std::cout << dt1 << " = " <<  dt2 << " ? " << (dt1 == dt2 ? "Yes" : "No") << std::endl;
    std::cout << dt1 << " != " <<  dt2 << " ? " << (dt1 != dt2 ? "Yes" : "No") << std::endl;
    std::cout << dt1 << " >= " <<  dt2 << " ? " << (dt1 >= dt2 ? "Yes" : "No") << std::endl;
    std::cout << dt1 << " <= " <<  dt2 << " ? " << (dt1 <= dt2 ? "Yes" : "No") << std::endl;
    std::cout << dt1 << " > " <<  dt2 << " ? " << (dt1 > dt2 ? "Yes" : "No") << std::endl;
    std::cout << dt1 << " < " <<  dt2 << " ? "  << (dt1 < dt2 ? "Yes" : "No") << std::endl;
    std::cout << "Tang (3) len 1 ngay: " << ++dt1 << std::endl;
    std::cout << "Giam (4) di 1 ngay: " << --dt2 << std::endl;
    std::cout << "Giam (3) di 1 ngay: " << --dt1 << std::endl;
    std::cout << "Tang (4) len 1 ngay: " << ++dt2 << std::endl;
    std::cout << "Tang (3) len 1000 ngay: " << dt1 + 1000 << std::endl;
    std::cout << "Giam (4) di 1000 ngay: " << dt2 - 1000 << std::endl;
    return 0;
}