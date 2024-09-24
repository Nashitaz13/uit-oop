#include <iostream>

class Room {
protected:
    int soDem;
    int phiDichVu;
public:
    Room(int soDem, int phiDichVu = 0) : soDem(soDem), phiDichVu(phiDichVu) {}
    virtual int doanhThu() = 0;
    virtual std::string loaiPhong() = 0;
};

class Deluxe : public Room {
private:
    int phiPhucVu;
public:
    Deluxe(int soDem, int phiDichVu, int phiPhucVu)
    : Room(soDem, phiDichVu), phiPhucVu(phiPhucVu) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};

int Deluxe::doanhThu() {
    return soDem * 750000 + phiDichVu + phiPhucVu;
}

std::string Deluxe::loaiPhong() {
    return "Deluxe";
}

class Premium : public Room {
public:
    Premium(int soDem, int phiDichVu) 
    : Room(soDem, phiDichVu) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};

int Premium::doanhThu() {
    return soDem * 500000 + phiDichVu;
}

std::string Premium::loaiPhong() {
    return "Premium";
}

class Business : public Room {
public:
    Business(int soDem) : Room(soDem) {}
    int doanhThu() override;
    std::string loaiPhong() override;
};

int Business::doanhThu() {
    return soDem * 300000;
}

std::string Business::loaiPhong() {
    return "Business";
}


Room* taoPhong(int loaiPhong, int soDem, int phiDichVu = 0, int phiPhucVu = 0) {
    if (loaiPhong == 1) {
        return new Deluxe(soDem, phiDichVu, phiPhucVu);
    } else if (loaiPhong == 2) {
        return new Premium(soDem, phiDichVu);
    } else if (loaiPhong == 3) {
        return new Business(soDem);
    } else {
        return NULL;
    }
}

int main() {
    int soPhong;
    std::cout << "Nhap so phong: ";
    std::cin >> soPhong;

    Room* dsPhong[soPhong];
    int tongDeluxe = 0, tongPremium = 0, tongBusiness = 0;

    for (int i = 0; i < soPhong; ++i) {
        int loaiPhong;
        std::cout << "Chon loai phong (1 - Deluxe, 2 - Premium, 3 - Business): ";
        std::cin >> loaiPhong;

        int soDem;
        std::cout << "Nhap so dem: ";
        std::cin >> soDem;

        if (loaiPhong == 1) {
            int phiDichVu, phiPhucVu;
            std::cout << "Nhap phi dich vu: ";
            std::cin >> phiDichVu;
            std::cout << "Nhap phi phuc vu: ";
            std::cin >> phiPhucVu;
            dsPhong[i] = taoPhong(loaiPhong, soDem, phiDichVu, phiPhucVu);
            tongDeluxe += dsPhong[i]->doanhThu();
        } else if (loaiPhong == 2) {
            int phiDichVu;
            std::cout << "Nhap phi dich vu: ";
            std::cin >> phiDichVu;
            dsPhong[i] = taoPhong(loaiPhong, soDem, phiDichVu);
            tongPremium += dsPhong[i]->doanhThu();
        } else if (loaiPhong == 3) {
            dsPhong[i] = taoPhong(loaiPhong, soDem);
            tongBusiness += dsPhong[i]->doanhThu();
        }

        std::cout << "Doanh thu cua phong " << i+1 << ", loai phong ";
        std::cout << dsPhong[i]->loaiPhong() << ": " << dsPhong[i]->doanhThu() << "\n";
    }

    std::string loaiPhongDoanhThuCaoNhat;
    int doanhThuCaoNhat;

    if (tongDeluxe > tongPremium && tongDeluxe > tongBusiness) {
        loaiPhongDoanhThuCaoNhat = "Deluxe";
        doanhThuCaoNhat = tongDeluxe;
    } else if (tongPremium > tongDeluxe && tongPremium > tongBusiness) {
        loaiPhongDoanhThuCaoNhat = "Premium";
        doanhThuCaoNhat = tongPremium;
    } else if (tongBusiness > tongDeluxe && tongBusiness > tongPremium) {
        loaiPhongDoanhThuCaoNhat = "Business";
        doanhThuCaoNhat = tongBusiness;
    } else if (tongDeluxe == tongPremium && tongDeluxe > tongBusiness) {
        loaiPhongDoanhThuCaoNhat = "Deluxe and Premium";
        doanhThuCaoNhat = tongDeluxe;
    } else if (tongDeluxe == tongBusiness && tongDeluxe > tongPremium) {
        loaiPhongDoanhThuCaoNhat = "Deluxe and Business";
        doanhThuCaoNhat = tongDeluxe;
    } else if (tongPremium == tongBusiness && tongPremium > tongDeluxe) {
        loaiPhongDoanhThuCaoNhat = "Premium and Business";
        doanhThuCaoNhat = tongPremium;
    } else {
        loaiPhongDoanhThuCaoNhat = "Cac doanh thu cua cac loai phong bang nhau.";
        doanhThuCaoNhat = tongDeluxe; // equal revenue
    }
    std::cout << "Loai phong co doanh thu cao nhat la: " << loaiPhongDoanhThuCaoNhat << " voi doanh thu la: " << doanhThuCaoNhat << "\n";

    for (int i = 0; i < soPhong; ++i) {
        delete dsPhong[i];
    }
    return 0;
}
