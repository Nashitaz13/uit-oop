#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Diem {
private:
    float x, y;
public:
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void Quay(float angle);
    void PhongTo(float k);
    void ThuNho(float k);
    float getX() { return x; }
    float getY() { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }
};

class DaGiac {
private:
    int n;
    Diem *dinh;
public:
    DaGiac() : n(0), dinh(NULL) {}
    ~DaGiac() { delete[] dinh; }
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void Quay(float angle);
    void PhongTo(float k);
    void ThuNho(float k);
};

void Diem::Nhap() {
    cout << "Nhap toa do x, y: ";
    cin >> x >> y;
}

void Diem::Xuat() {
    cout << "(" << x << ", " << y << ")" << endl;
}

void Diem::TinhTien(float dx, float dy) {
    x += dx;
    y += dy;
}

void Diem::Quay(float angle) {
    float rad = angle * M_PI / 180.0;
    float _x = x * cos(rad) - y * sin(rad);
    float _y = x * sin(rad) + y * cos(rad);
    x = _x;
    y = _y;
}

void Diem::PhongTo(float k) {
    x *= k;
    y *= k;
}

void Diem::ThuNho(float k) {
    if (k != 0) {
        x /= k;
        y /= k;
    }
}

bool LaDaGiac(Diem* dinh, int n) {
    if (n < 3) return false;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (i + 2) % n;
        float dx1 = dinh[j].getX() - dinh[i].getX();
        float dy1 = dinh[j].getY() - dinh[i].getY();
        float dx2 = dinh[k].getX() - dinh[j].getX();
        float dy2 = dinh[k].getY() - dinh[j].getY();
        if (dx1 * dy2 == dx2 * dy1) return false;
    }
    return true;
}

void DaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac: ";
        cin >> n;
        if (n < 3) {
            cout << "So dinh phai lon hon hoac bang 3. Hay nhap lai.\n";
            continue;
        }
        dinh = new Diem[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap dinh thu " << i + 1 << ": ";
            dinh[i].Nhap();
        }
        if (!LaDaGiac(dinh, n)) {
            cout << "Cac dinh nhap vao khong tao thanh da giac. Hay nhap lai.\n";
            delete[] dinh;
            dinh = NULL;
        }
    } while (!LaDaGiac(dinh, n));
}


void DaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "Dinh thu " << i + 1 << ": ";
        dinh[i].Xuat();
    }
}

void DaGiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].TinhTien(dx, dy);
    }
}

void DaGiac::Quay(float angle) {
    for (int i = 0; i < n; i++) {
        dinh[i].Quay(angle);
    }
}

void DaGiac::PhongTo(float k) {
    for (int i = 0; i < n; i++) {
        dinh[i].PhongTo(k);
    }
}

void DaGiac::ThuNho(float k) {
    for (int i = 0; i < n; i++) {
        dinh[i].ThuNho(k);
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
    cout << "Da giac sau khi tinh tien: ";
    d.Xuat();
    float k;
    cout << "Nhap he so phong to k: ";
    cin >> k;
    d.PhongTo(k);
    cout << "Da giac sau khi phong to: ";
    d.Xuat();
    float n;
    cout << "Nhap he so thu nho n: ";
    cin >> n;
    d.ThuNho(n);
    cout << "Da giac sau khi thu nho: ";
    d.Xuat();
    float angle;
    cout << "Nhap goc quay (do): ";
    cin >> angle;
    d.Quay(angle);
    cout << "Da giac sau khi quay: ";
    d.Xuat();
    return 0;
}
