#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    double x, y;
public:
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double angle);
    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }
};

bool LaTamGiac(Diem A, Diem B, Diem C) {
    double AB = sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
    double BC = sqrt(pow(C.getX() - B.getX(), 2) + pow(C.getY() - B.getY(), 2));
    double CA = sqrt(pow(A.getX() - C.getX(), 2) + pow(A.getY() - C.getY(), 2));

    return (AB + BC > CA) && (BC + CA > AB) && (CA + AB > BC);
}


void Diem::Nhap() {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
}

void Diem::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

void Diem::TinhTien(double dx, double dy) {
    x += dx; y += dy;
}

void Diem::PhongTo(double k) {
    x *= k; y *= k;
}

void Diem::ThuNho(double k) {
    x /= k; y /= k;
}

void Diem::Quay(double angle) {
    double rad = angle * M_PI / 180.0;
    double sinA = sin(rad), cosA = cos(rad);
    double tempX = x*cosA - y*sinA;
    double tempY = x*sinA + y*cosA;
    x = tempX; y = tempY;
}

class TamGiac {
public:
    Diem A, B, C;
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double angle);
};

void TamGiac::Nhap() {
    do {
        cout << "Nhap dinh A:\n";
        A.Nhap();
        cout << "Nhap dinh B:\n";
        B.Nhap();
        cout << "Nhap dinh C:\n";
        C.Nhap();
        if (!LaTamGiac(A, B, C)) {
            cout << "3 diem khong tao thanh tam giac. Vui long nhap lai.\n";
        }
    } while (!LaTamGiac(A, B, C));
}


void TamGiac::Xuat() {
    cout << "Dinh A: ";
    A.Xuat();
    cout << "\nDinh B: ";
    B.Xuat();
    cout << "\nDinh C: ";
    C.Xuat();
    cout << "\n" << endl;
}

void TamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void TamGiac::PhongTo(double k) {
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}

void TamGiac::ThuNho(double k) {
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}

void TamGiac::Quay(double angle) {
    A.Quay(angle);
    B.Quay(angle);
    C.Quay(angle);
}

int main() {
    TamGiac tamGiac;
    tamGiac.Nhap();
    tamGiac.Xuat();

    float dx, dy;
    cout << "Nhap khoang tinh theo theo dang (dx,dy): ";
    cin >> dx >> dy;
    tamGiac.TinhTien(dx, dy);
    tamGiac.Xuat();

    float k;
    cout << "Nhap he so phong to k: ";
    cin >> k;
    tamGiac.PhongTo(k);
    tamGiac.Xuat();

    float n;
    cout << "Nhap he so thu nho n: ";
    cin >> n;
    tamGiac.ThuNho(n);
    tamGiac.Xuat();

    float angle;
    cout << "Nhap goc quay (don vi do): ";
    cin >> angle;
    tamGiac.Quay(angle);
    tamGiac.Xuat();

    return 0;
}
