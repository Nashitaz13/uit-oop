#pragma once
#include "NgayThangNam.h"

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

NgayThangNam::NgayThangNam() {
    iNgay = 0;
    iThang = 0;
    iNam = 0;
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

//Theo tien to
NgayThangNam NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

std::istream& operator>>(std::istream& is, NgayThangNam& date) {
    do {
        std::cout << "Nhap ngay: ";
        is >> date.iNgay;
        std::cout << "Nhap thang: ";
        is >> date.iThang;
        std::cout << "Nhap nam: ";
        is >> date.iNam;
        if (!NgayThangNamHopLe(date.iNgay, date.iThang, date.iNam)) {
            std::cout << "Ngay thang nam ban nhap khong hop le. Vui long nhap lai!" << std::endl;
        }
    } while (!NgayThangNamHopLe(date.iNgay, date.iThang, date.iNam));
    return is;
}


std::ostream& operator<<(std::ostream& os, const NgayThangNam& date) {
    os << std::setw(2) << std::setfill('0') << date.iNgay << "/";
    os << std::setw(2) << std::setfill('0') << date.iThang << "/" << date.iNam;
    return os;
}

int NgayThangNam::operator-(NgayThangNam& a) {
    int dayhientai = this->TinhNgay();
    int daykhac = a.TinhNgay();
    int songay = 0;
    // Nếu cùng năm
    if (this->iNam == a.iNam) {
        songay = abs(dayhientai - daykhac);
    } else {
        int kccacnam = abs(this->iNam - a.iNam);
        // Kiểm tra năm nhuận và tính số ngày
        for (int i = std::min(this->iNam, a.iNam); i < std::max(this->iNam, a.iNam); i++) {
            if (LaNamNhuan(i)) {
                songay += 366;
            } else {
                songay += 365;
            }
        }
        // Tính số ngày giữa hai thời điểm
        if (this->iNam > a.iNam) {
            songay = songay - daykhac + dayhientai;
        } else {
            songay = songay - dayhientai + daykhac;
        }
    }
    return songay;
}


bool operator==(const NgayThangNam& a, const NgayThangNam& b) {
    if (a.iNam == b.iNam) {
        if (a.iThang == b.iThang) {
            return a.iNgay == b.iNgay;
        } else {
            return a.iThang == b.iThang;
        }
    } else {
        return a.iNam == b.iNam;
    }
}

bool operator!=(const NgayThangNam& a, const NgayThangNam& b) {
    return !(a == b);
}

bool operator>=(const NgayThangNam& a, const NgayThangNam& b) {
    if (a.iNam > b.iNam) {
        return true;
    } else if (a.iNam == b.iNam) {
        if (a.iThang > b.iThang) {
            return true;
        } else if (a.iThang == b.iThang) {
            return a.iNgay >= b.iNgay;
        }
    }
    return false;
}

bool operator<=(const NgayThangNam& a, const NgayThangNam& b) {
    return !(a > b);
}

bool operator>(const NgayThangNam& a, const NgayThangNam& b) {
    if (a.iNam > b.iNam) {
        return true;
    } else if (a.iNam == b.iNam) {
        if (a.iThang > b.iThang) {
            return true;
        } else if (a.iThang == b.iThang) {
            return a.iNgay > b.iNgay;
        }
    }
    return false;
}

bool operator<(const NgayThangNam& a, const NgayThangNam& b) {
    return !(a >= b);
}