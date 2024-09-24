#include "Room.cpp"

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