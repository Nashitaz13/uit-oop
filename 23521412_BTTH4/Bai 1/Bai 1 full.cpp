#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

std::string chuan(std::string name){
	std::stringstream ss(name);
	std::string res = "";
	std::string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i = 1; i < token.length(); i++) res += tolower(token[i]);
		res += " ";
	}
	res.erase(res.length() - 1);
	return res;
}

class NhanVien {
protected:
    std::string maSo;
    std::string ten;
    double luongCoBan;

public:
    NhanVien() {
        std::cout << "Nhap ma so: ";
        std::cin >> maSo;
        std::cout << "Nhap ten: ";
        std::cin.ignore();
        std::getline(std::cin, ten);
        ten = chuan(ten);
        std::cout << "Nhap luong co ban: ";
        std::cin >> luongCoBan;
    }

    virtual double TienThuong() = 0;

    void Xuat() {
        std::cout << "Ma so: " << maSo << "\n";
        std::cout << "Ten: " << ten << "\n";
        std::cout << "Luong co ban: " << std::fixed << std::setprecision(0) << luongCoBan << "\n";
        std::cout << "Tien thuong: " << std::fixed << std::setprecision(0) << TienThuong() << "\n";
    }
};

class QuanLy : public NhanVien {
private:
    double tyLeThuong;

public:
    QuanLy() : NhanVien() {
        std::cout << "Nhap ty le thuong (ghi dang so thap phan vi du: 0.5 (50%)): ";
        std::cin >> tyLeThuong;
    }

    double TienThuong() override {
        return luongCoBan * tyLeThuong;
    }
};

class KySu : public NhanVien {
private:
    int soGioLamThem;

public:
    KySu() : NhanVien() {
        std::cout << "Nhap so gio lam them: ";
        std::cin >> soGioLamThem;
    }

    double TienThuong() override {
        return soGioLamThem * 100000;
    }
};

int main() {
    std::cout << "Nhap thong tin Quan Ly:\n";
    QuanLy ql;
    std::cout << "\nNhap thong tin Ky Su:\n";
    KySu ks;

    std::cout << "\nThong tin Quan Ly:\n";
    ql.Xuat();

    std::cout << "\nThong tin Ky Su:\n";
    ks.Xuat();

    return 0;
}
