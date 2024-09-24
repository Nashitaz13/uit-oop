#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

public:
    void Nhap();
    void Xuat();
    void RutGon();
    PhanSo Tong(PhanSo ps);
    PhanSo Hieu(PhanSo ps);
    PhanSo Tich(PhanSo ps);
    PhanSo Thuong(PhanSo ps);
    int SoSanh(PhanSo ps);
    PhanSo NghichDao(); 
    int getTu() const;
    int getMau() const;
    void setTu(int tu);
    void setMau(int mau);
};

void PhanSo::Nhap() {
    cout << "Nhap phan so thoa man." << endl;
    cout << "Nhap tu so: ";
    cin >> iTu;
    do {
        cout << "Nhap Mau so: "; 
        cin >> iMau;
        if (iMau == 0)
            cout << "Nhap sai, yeu cau nhap lai mau so: ";
    } while (iMau == 0);
}

void PhanSo::Xuat() {
    if (iMau == 0) {
        cout << "Khong ton tai phan so nay" << endl;
    } else if (iTu == 0) {
        cout << 0 << endl;
    } else if (iTu == iMau) {
        cout << 1 << endl;
    } else if (iTu % iMau == 0) {
        cout << iTu / iMau << endl;
    } else {
        if (iMau < 0) {
            cout << iTu * -1 << "/" << abs(iMau) << endl;
        } else {
            cout << iTu << "/" << iMau << endl;
        }
    }
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
}

PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo tong;
    tong.iTu = this->iTu * ps.iMau + this->iMau * ps.iTu;
    tong.iMau = this->iMau * ps.iMau;
    tong.RutGon();
    return tong;
}

PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo hieu;
    hieu.iTu = this->iTu * ps.iMau - this->iMau * ps.iTu;
    hieu.iMau = this->iMau * ps.iMau;
    hieu.RutGon();
    return hieu;
}

PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo tich;
    tich.iTu = this->iTu * ps.iTu;
    tich.iMau = this->iMau * ps.iMau;
    tich.RutGon();
    return tich;
}

PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo thuong;
    thuong.iTu = this->iTu * ps.iMau;
    thuong.iMau = this->iMau * ps.iTu;
    thuong.RutGon();
    return thuong;
}

int PhanSo::SoSanh(PhanSo ps) {
    int l = this->iTu * ps.iMau;
    int r = ps.iTu * this->iMau;
    if (l > r) {
        return 1;
    } else if (l < r) {
        return -1;
    } else {
        return 0;
    }
}

// Phương thức nghịch đảo
PhanSo PhanSo::NghichDao() {
    PhanSo nghichDao;
    nghichDao.iTu = this->iMau;
    nghichDao.iMau = this->iTu;
    return nghichDao;
}

// Các phương thức lấy và gán tử số, mẫu số
int PhanSo::getTu() const {
    return iTu;
}

int PhanSo::getMau() const {
    return iMau;
}

void PhanSo::setTu(int tu) {
    iTu = tu;
}

void PhanSo::setMau(int mau) {
    if (mau != 0) {
        iMau = mau;
    } else {
        cout << "Mau so khong duoc bang 0." << endl;
    }
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    ps1.Nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.Nhap();

    PhanSo tong = ps1.Tong(ps2);
    cout << "Tong hai phan so la: ";
    tong.Xuat();

    PhanSo hieu = ps1.Hieu(ps2);
    cout << "Hieu hai phan so la: ";
    hieu.Xuat();

    PhanSo tich = ps1.Tich(ps2);
    cout << "Tich hai phan so la: ";
    tich.Xuat();

    PhanSo thuong = ps1.Thuong(ps2);
    cout << "Thuong hai phan so la: ";
    thuong.Xuat();

    int soSanh = ps1.SoSanh(ps2);
    if (soSanh > 0) {
        cout << "Phan so thu nhat lon hon phan so thu hai.\n";
    } else if (soSanh < 0) {
        cout << "Phan so thu nhat nho hon phan so thu hai.\n";
    } else {
        cout << "Hai phan so bang nhau.\n";
    }

    // Sử dụng phương thức nghịch đảo
    PhanSo nghichDao1 = ps1.NghichDao();
    cout << "Nghich dao cua phan so thu nhat la: ";
    nghichDao1.Xuat();

    PhanSo nghichDao2 = ps2.NghichDao();
    cout << "Nghich dao cua phan so thu hai la: ";
    nghichDao2.Xuat();

    // Sử dụng các phương thức lấy và gán tử số, mẫu số
    cout << "Tu so cua phan so thu nhat: " << ps1.getTu() << endl;
    cout << "Mau so cua phan so thu nhat: " << ps1.getMau() << endl;

    cout << "Gan lai tu so va mau so cho phan so thu nhat.\n";
    ps1.setTu(5);
    ps1.setMau(10);
    cout << "Phan so thu nhat sau khi gan lai: ";
    ps1.Xuat();

    return 0;
}
