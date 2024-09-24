#include "GiaSuc.cpp"

int main() {
    srand(time(0));
    
    Bo cow;
    Cuu sheep;
    De goat;

    std::cout << "Nhap so luong cho bo:\n";
    cow.Nhap();
    std::cout << "Nhap so luong cho cuu:\n";
    sheep.Nhap();
    std::cout << "Nhap so luong cho de:\n";
    goat.Nhap();

    std::cout << "Tieng keu trong nong trai:\n";
    std::cout << "Nhung con bo keu: ";
    cow.keu();
    std::cout << std::endl;
    std::cout << "Nhung con cuu keu: ";
    sheep.keu();
    std::cout << std::endl;
    std::cout << "Nhung con de keu: ";
    goat.keu();
    std::cout << std::endl;

    thongKe(&cow, &sheep, &goat);
    return 0;
}
