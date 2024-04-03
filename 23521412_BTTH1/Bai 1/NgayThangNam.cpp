#include <bits/stdc++.h>

using namespace std;

class NgayThangNam{
    private:
        int iNgay, iThang, iNam;
    public:
        void Nhap();
        void Xuat();
        void NgayThangNamTiepTheo();
};

void NgayThangNam::Nhap(){
    cout << "Nhap ngay: "; cin >> iNgay; cout << endl;
    cout << "Nhap thang: "; cin >> iThang; cout << endl;
    cout << "Nhap nam: "; cin >> iNam; cout << endl;
}

void NgayThangNam::Xuat(){
    cout << "Ngay/Thang/Nam: " << iNgay << "/" << iThang << "/" << iNam << endl;
}

void NgayThangNam::NgayThangNamTiepTheo() {
    iNgay++; 
    if (iThang == 2) { 
        if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0) {
            if (iNgay > 29) {
                iNgay = 1;
                iThang++;
            }
        } else {
            if (iNgay > 28) {
                iNgay = 1;
                iThang++;
            }
        }
    } else if (iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11) {
        if (iNgay > 30) {
            iNgay = 1;
            iThang++;
        }
    } else {
        if (iNgay > 31) {
            iNgay = 1;
            if (iThang == 12) {
                iThang = 1;
                iNam++;
            } else {
                iThang++;
            }
        }
    }
}