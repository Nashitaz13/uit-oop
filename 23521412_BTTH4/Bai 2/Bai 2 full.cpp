#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// chua fix
class Animal {
public:
    static int count;
    double milk;
    virtual void makeSound() = 0;
    virtual int giveBirth() = 0;
    virtual double produceMilk() = 0;
    virtual void printStats() = 0;
};

int Animal::count = 0;

class Cow : public Animal {
public:
    static int count;
    Cow() { count++; }
    void makeSound() override {
        std::cout << "Bo keu: Moo!\n";
    }

    int giveBirth() override {
        int newborns = rand() % 2;  // Bò sinh 0 hoặc 1 con
        count += newborns;
        return newborns;
    }

    double produceMilk() override {
        milk = rand() % 21;  // Bò cho từ 0 đến 20 lít sữa
        return milk;
    }

    void printStats() override {
        std::cout << "So luong bo: " << count << '\n';
        std::cout << "So luong sua moi con bo: " << milk << " lit\n";
    }
};

int Cow::count = 0;

class Sheep : public Animal {
public:
    static int count;
    Sheep() { count++; }
    void makeSound() override {
        std::cout << "Cuu keu: Baa!\n";
    }

    int giveBirth() override {
        int newborns = rand() % 3;  // Cừu sinh từ 0 đến 2 con
        count += newborns;
        return newborns;
    }

    double produceMilk() override {
        milk = rand() % 6;  // Cừu cho từ 0 đến 5 lít sữa
        return milk;
    }

    void printStats() override {
        std::cout << "So luong cuu: " << count << '\n';
        std::cout << "So luong sua moi con cuu: " << milk << " lit\n";
    }
};

int Sheep::count = 0;

class Goat : public Animal {
public:
    static int count;
    Goat() { count++; }
    void makeSound() override {
        std::cout << "De keu: Maa!\n";
    }

    int giveBirth() override {
        int newborns = rand() % 3;  // Dê sinh từ 0 đến 2 con
        count += newborns;
        return newborns;
    }

    double produceMilk() override {
        milk = rand() % 11;  // Dê cho từ 0 đến 10 lít sữa
        return milk;
    }

    void printStats() override {
        std::cout << "So luong de: " << count << '\n';
        std::cout << "So luong sua moi con de: " << milk << " lit\n";
    }
};

int Goat::count = 0;

int main() {
    srand(time(0));  // Khởi tạo bộ sinh số ngẫu nhiên

    std::vector<Animal*> farm;
    // Thêm gia súc vào nông trại
    // (số lượng ban đầu của mỗi loại gia súc có thể thay đổi)
    for (int i = 0; i < 10; ++i) farm.push_back(new Cow());
    for (int i = 0; i < 10; ++i) farm.push_back(new Sheep());
    for (int i = 0; i < 10; ++i) farm.push_back(new Goat());

    // a) Tất cả gia súc trong nông trại đều đói
    for (Animal* animal : farm) {
        animal->makeSound();
    }

    // In ra số lượng gia súc ở mỗi loại
    std::cout << "So luong bo: " << Cow::count << '\n';
    std::cout << "So luong cuu: " << Sheep::count << '\n';
    std::cout << "So luong de: " << Goat::count << '\n';

    // b) Thống kê sau một lứa sinh và một lượt cho sữa
    int newBorns = 0;
    double totalMilk = 0;
    for (Animal* animal : farm) {
        newBorns += animal->giveBirth();
        totalMilk += animal->produceMilk();
//        animal->printStats();
    }
    
    std::cout << "So con vua sinh: " << newBorns << '\n';
    std::cout << "Tong so sua: " << totalMilk << " lit\n";

    // In ra số lượng gia súc ở mỗi loại sau một lứa sinh và một lượt cho sữa
    std::cout << "So luong bo sau mot lua sinh va mot luot cho sua: " << Cow::count << '\n';
    std::cout << "So luong cuu sau mot lua sinh va mot luot cho sua: " << Sheep::count << '\n';
    std::cout << "So luong de sau mot lua sinh va mot luot cho sua: " << Goat::count << '\n';

    // Xóa các đối tượng đã tạo
    for (Animal* animal : farm) {
        delete animal;
    }

    return 0;
}
