#include <iostream>
#include <iomanip>

bool LaNamNhuan(int nam) {
    return (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0));
}

bool NgayThangNamHopLe(int Ngay, int Thang, int Nam) {
    if (Ngay < 1 || Thang < 1 || Thang > 12)
        return false;

    switch (Thang) {
        case 4:
        case 6:
        case 9:
        case 11:
            return (Ngay <= 30);
        case 2:
            if (LaNamNhuan(Nam))
                return (Ngay <= 29);
            else
                return (Ngay <= 28);
        default:
            return (Ngay <= 31);
    }
}

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    // Constructor có tham số
    NgayThangNam(int Nam, int Thang, int Ngay = 1);
    // Phương thức tính số ngày trong năm
    int TinhNgay() const;
    // Phép cộng ngày
    NgayThangNam operator+(int ngay) const;
    // Phép trừ ngày
    NgayThangNam operator-(int ngay) const;
    // Phép ++ (tăng lên 1 ngày)
    NgayThangNam& operator++();
    // Phép -- (giảm đi 1 ngày)
    NgayThangNam& operator--();
    // Phép -- (giảm đi 1 ngày)
    NgayThangNam operator--(int);
    // Hàm nhập
    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);
    // Hàm xuất
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
    // Phương thức trừ một ngày tháng năm khác
    friend int operator-(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh bằng
    friend bool operator==(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh không bằng
    friend bool operator!=(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh lớn hơn hoặc bằng
    friend bool operator>=(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh nhỏ hơn hoặc bằng
    friend bool operator<=(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh lớn hơn
    friend bool operator>(const NgayThangNam& a, const NgayThangNam& b);
    // Phương thức so sánh nhỏ hơn
    friend bool operator<(const NgayThangNam& a, const NgayThangNam& b);
};

NgayThangNam::NgayThangNam() {
    iNgay = 1;
    iThang = 1;
    iNam = 2000;
}

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {
    iNgay = Ngay;
    iThang = Thang;
    iNam = Nam;
}

int NgayThangNam::TinhNgay() const {
    int days = iNgay;
    for (int i = 1; i < iThang; ++i) {
        switch (i) {
            case 2:
                days += LaNamNhuan(iNam) ? 29 : 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
            default:
                days += 31;
        }
    }
    return days;
}

NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam temp = *this;
    temp.iNgay += ngay;
    while (temp.iNgay > 31 || (temp.iThang == 2 && temp.iNgay > (LaNamNhuan(temp.iNam) ? 29 : 28))) {
        if (temp.iThang == 2 && temp.iNgay > (LaNamNhuan(temp.iNam) ? 29 : 28)) {
            temp.iNgay -= LaNamNhuan(temp.iNam) ? 29 : 28;
            temp.iThang++;
        } else {
            switch (temp.iThang) {
                case 4:
                case 6:
                case 9:
                case 11:
                    if (temp.iNgay > 30) {
                        temp.iNgay -= 30;
                        temp.iThang++;
                    }
                    break;
                default:
                    if (temp.iNgay > 31) {
                        temp.iNgay -= 31;
                        temp.iThang++;
                    }
            }
        }
        if (temp.iThang > 12) {
            temp.iThang = 1;
            temp.iNam++;
        }
    }
    return temp;
}

NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam temp = *this;
    temp.iNgay -= ngay;
    while (temp.iNgay < 1) {
        if (temp.iThang == 3 && temp.iNgay < (LaNamNhuan(temp.iNam) ? 29 : 28)) {
            temp.iThang--;
            temp.iNgay += LaNamNhuan(temp.iNam) ? 29 : 28;
        } else {
            switch (temp.iThang) {
                case 5:
                case 7:
                case 10:
                case 12:
                    temp.iThang--;
                    temp.iNgay += 30;
                    break;
                default:
                    temp.iThang--;
                    temp.iNgay += 31;
            }
        }
        if (temp.iThang < 1) {
            temp.iThang = 12;
            temp.iNam--;
        }
    }
    return temp;
}

NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

std::istream& operator>>(std::istream& is, NgayThangNam& date) {
    do {
        std::cout << "Nhap ngay: ";
        is >> date.iNgay;
        std::cout << "Nhap thang: ";
        is >> date.iThang;
        std::cout << "Nhap nam: ";
        is >> date.iNam;
    } while (!NgayThangNamHopLe(date.iNgay, date.iThang, date.iNam));
    return is;
}

std::ostream& operator<<(std::ostream& os, const NgayThangNam& date) {
    os << std::setw(2) << std::setfill('0') << date.iNgay << "/" << std::setw(2) << std::setfill('0') << date.iThang << "/" << date.iNam;
    return os;
}

int operator-(const NgayThangNam& a, const NgayThangNam& b) {
    return a.TinhNgay() - b.TinhNgay();
}

bool operator==(const NgayThangNam& a, const NgayThangNam& b) {
    return (a.iNgay == b.iNgay && a.iThang == b.iThang && a.iNam == b.iNam);
}

bool operator!=(const NgayThangNam& a, const NgayThangNam& b) {
    return !(a == b);
}

bool operator>=(const NgayThangNam& a, const NgayThangNam& b) {
    return a.TinhNgay() >= b.TinhNgay();
}

bool operator<=(const NgayThangNam& a, const NgayThangNam& b) {
    return a.TinhNgay() <= b.TinhNgay();
}

bool operator>(const NgayThangNam& a, const NgayThangNam& b) {
    return a.TinhNgay() > b.TinhNgay();
}

bool operator<(const NgayThangNam& a, const NgayThangNam& b) {
    return a.TinhNgay() < b.TinhNgay();
}

int main() {
    NgayThangNam date1, date2(2023, 12, 31);
    std::cout << "Nhap ngay thang nam cho date1 (dd/mm/yyyy): ";
    std::cin >> date1;
    std::cout << "Date 1: " << date1 << std::endl;
    std::cout << "Date 2: " << date2 << std::endl;
    std::cout << "So ngay trong nam cua Date1: " << date1.TinhNgay() << std::endl;
    
    std::cout << "So ngay giua hai ngay: " << (date2 - date1) << std::endl;

    std::cout << "Tang date1 len 1 ngay: " << ++date1 << std::endl;
    std::cout << "Giam date2 di 1 ngay: " << --date2 << std::endl;

    std::cout << "Date 1 bang Date 2? " << (date1 == date2 ? "Yes" : "No") << std::endl;
    std::cout << "Date 1 khac Date 2? " << (date1 != date2 ? "Yes" : "No") << std::endl;
    std::cout << "Date 1 lon hon hoac bang Date 2? " << (date1 >= date2 ? "Yes" : "No") << std::endl;
    std::cout << "Date 1 nho hon hoac bang Date 2? " << (date1 <= date2 ? "Yes" : "No") << std::endl;
    std::cout << "Date 1 lon hon Date 2? " << (date1 > date2 ? "Yes" : "No") << std::endl;
    std::cout << "Date 1 nho hon Date 2? " << (date1 < date2 ? "Yes" : "No") << std::endl;

    return 0;
}
