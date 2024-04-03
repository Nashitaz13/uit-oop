#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

class Diem {
private:
    float x, y;
public:
    Diem(float _x = 0, float _y = 0) : x(_x), y(_y) {}
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void Quay(float angle);
    float getX() { return x; }
    float getY() { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }
};

void Diem::Nhap() {
    float _x, _y;
    cout << "Nhap toa do x, y: ";
    cin >> _x >> _y;
    setX(_x);
    setY(_y);
}

void Diem::Xuat() {
    cout << "(" << getX() << ", " << getY() << ")";
}

void Diem::TinhTien(float dx, float dy) {
    setX(getX() + dx);
    setY(getY() + dy);
}

void Diem::Quay(float angle) {
    float rad = angle * M_PI / 180.0;
    float _x = getX() * cos(rad) - getY() * sin(rad);
    float _y = getX() * sin(rad) + getY() * cos(rad);
    setX(_x);
    setY(_y);
}

class DaGiac {
    int n;
    Diem *Dinh;
public:
    DaGiac() : n(0), Dinh(NULL) {}
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float angle);
};

void DaGiac::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    Dinh = new Diem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap dinh thu " << i + 1 << ": ";
        Dinh[i].Nhap();
    }
}

void DaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "Dinh thu " << i + 1 << ": ";
        Dinh[i].Xuat();
        cout << endl;
    }
}

void DaGiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        Dinh[i].TinhTien(dx, dy);
    }
}

void DaGiac::PhongTo(float k) {
    for (int i = 0; i < n; i++) {
        Dinh[i].setX(Dinh[i].getX() * k);
        Dinh[i].setY(Dinh[i].getY() * k);
    }
}

void DaGiac::ThuNho(float k) {
    PhongTo(1 / k);
}

void DaGiac::Quay(float angle) {
    for (int i = 0; i < n; i++) {
        Dinh[i].Quay(angle);
    }
}


int main() {
    DaGiac d;
    d.Nhap();
    d.Xuat();

    float dx, dy;
    cout << "Nhap khoang tinh tien dx, dy: ";
    cin >> dx >> dy;
    d.TinhTien(dx, dy);
    cout << "Da giac sau khi tinh tien: " << endl;
    d.Xuat();

    float k;
    cout << "Nhap he so phong to k: ";
    cin >> k;
    d.PhongTo(k);
    cout << "Da giac sau khi phong to: " << endl;
    d.Xuat();

    float n;
    cout << "Nhap he so thu nho n: ";
    cin >> n;
    d.ThuNho(n);
    cout << "Da giac sau khi thu nho: " << endl;
    d.Xuat();

    float angle;
    cout << "Nhap goc quay (do): ";
    cin >> angle;
    d.Quay(angle);
    cout << "Da giac sau khi quay: " << endl;
    d.Xuat();

    return 0;
}
