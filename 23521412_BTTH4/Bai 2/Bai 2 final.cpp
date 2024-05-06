#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <cstdlib>
#include <ctime>

class GiaSuc {
protected:
    int soLuong;
    int* soLitSua;

public:
    GiaSuc(int sl) : soLuong(sl) {
        soLitSua = new int[soLuong];
        sinhCon();
        choSua();
    }

    virtual void keu() const = 0;

    int tinhTongLitSua() const {
        int tong = 0;
        for (int i = 0; i < soLuong; ++i) {
            tong += soLitSua[i];
        }
        return tong;
    }

    void sinhCon() {
        // Sinh con ngẫu nhiên từ 0 đến 2
        int oldSoLuong = soLuong;
        for (int i = 0; i < oldSoLuong; ++i) {
            soLuong += rand() % 3;
        }
        // Cập nhật kích thước của mảng soLitSua
        int* newSoLitSua = new int[soLuong];
        for (int i = 0; i < oldSoLuong; ++i) {
            newSoLitSua[i] = soLitSua[i];
        }
        delete[] soLitSua;
        soLitSua = newSoLitSua;
    }

    virtual void choSua() {
        // Số lít sữa mỗi gia súc ngẫu nhiên trong giới hạn
        for (int i = 0; i < soLuong; ++i) {
            soLitSua[i] = rand() % 21; // Bò: 0-20 lít
        }
    }

    int getSoLuong() const {
        return soLuong;
    }

    virtual ~GiaSuc() {
        delete[] soLitSua;
    }
};

class Bo : public GiaSuc {
public:
    Bo(int sl) : GiaSuc(sl) {}

    void keu() const override {
        std::cout << "Bo: Boo... ";
    }
};

class Cuu : public GiaSuc {
public:
    Cuu(int sl) : GiaSuc(sl) {}

    void keu() const override {
        std::cout << "Cuu: Mee... ";
    }

    void choSua() override {
        // Số lít sữa mỗi gia súc ngẫu nhiên trong giới hạn
        for (int i = 0; i < soLuong; ++i) {
            soLitSua[i] = rand() % 6; // Cừu: 0-5 lít
        }
    }
};

class De : public GiaSuc {
public:
    De(int sl) : GiaSuc(sl) {}

    void keu() const override {
        std::cout << "De: Maa... ";
    }

    void choSua() override {
        // Số lít sữa mỗi gia súc ngẫu nhiên trong giới hạn
        for (int i = 0; i < soLuong; ++i) {
            soLitSua[i] = rand() % 11; // Dê: 0-10 lít
        }
    }
};

void thongKe(const Bo* bo, const Cuu* cuu, const De* de) {
    int tongBo = bo->getSoLuong();
    int tongCuu = cuu->getSoLuong();
    int tongDe = de->getSoLuong();

    int tongLitSua = bo->tinhTongLitSua() + cuu->tinhTongLitSua() + de->tinhTongLitSua();

    std::cout << "Thong ke sau mot thoi gian chan nuoi:\n";
    std::cout << "So luong bo: " << tongBo << std::endl;
    std::cout << "So luong cuu: " << tongCuu << std::endl;
    std::cout << "So luong de: " << tongDe << std::endl;
    std::cout << "Tong so lit sua: " << tongLitSua << " lit" << std::endl;
}

int main() {
    srand(time(0));

    int slBo, slCuu, slDe;
    std::cout << "Nhap so luong bo: ";
    std::cin >> slBo;
    std::cout << "Nhap so luong cuu: ";
    std::cin >> slCuu;
    std::cout << "Nhap so luong de: ";
    std::cin >> slDe;

    Bo* bo = new Bo(slBo);
    Cuu* cuu = new Cuu(slCuu);
    De* de = new De(slDe);

    std::cout << "Tieng keu trong nong trai:\n";
    bo->keu();
    cuu->keu();
    de->keu();
    std::cout << std::endl;

    thongKe(bo, cuu, de);

    delete bo;
    delete cuu;
    delete de;

    return 0;
}
