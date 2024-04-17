#include <iostream>
#include <iomanip>
using namespace std;

class ThoiGian
{
private:
    int iGio, iPhut, iGiay;
public:
    ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}  
    ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {} 
    int TinhGiay(); 
    void TinhLaiGio(int Giay); 
    friend istream& operator >> (istream& is, ThoiGian& T);
    friend ostream& operator << (ostream& os, ThoiGian& T);
    ThoiGian operator++ (); 
    ThoiGian operator-- (); 
    ThoiGian operator+(int Giay); 
    ThoiGian operator-(int Giay); 
    ThoiGian operator+(ThoiGian& Ts); 
    ThoiGian operator-(ThoiGian& Ts); 
    friend bool operator<(ThoiGian& T1, ThoiGian& T2);
    friend bool operator>=(ThoiGian& T1, ThoiGian& T2);
    friend bool operator<=(ThoiGian& T1, ThoiGian& T2);
    friend bool operator!=(ThoiGian& T1, ThoiGian& T2);
    friend bool operator==(ThoiGian& T1, ThoiGian& T2);
    friend bool operator>(ThoiGian& T1, ThoiGian& T2);
};

int ThoiGian::TinhGiay() 
{
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) 
{
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;
}

istream& operator >> (istream& is, ThoiGian& T) 
{
    do {
        cout << "Nhap gio (0-23): ";
        is >> T.iGio;
    } while (T.iGio < 0 || T.iGio > 23);

    do {
        cout << "Nhap phut (0-59) = ";
        is >> T.iPhut;
    } while (T.iPhut < 0 || T.iPhut > 59);

    do {
        cout << "Nhap giay (0-59) = ";
        is >> T.iGiay;
    } while (T.iGiay < 0 || T.iGiay > 59);

    return is;
}

ostream& operator << (ostream& os, ThoiGian& T) 
{
    os << setfill('0') << setw(2) << T.iGio << ":"
       << setfill('0') << setw(2) << T.iPhut << ":"
       << setfill('0') << setw(2) << T.iGiay << endl;
    return os;
}

ThoiGian ThoiGian::operator++ () 
{
    ++iGiay;        
    if (iGiay >= 60)
    {
        ++iPhut;
        iGiay -= 60;
    }
    if (iPhut >= 60)
    {
        ++iGio;
        iPhut -= 60;
    }
    return ThoiGian(iGio, iPhut, iGiay);
}

ThoiGian ThoiGian::operator-- () 
{
    --iGiay;        
    if (iGiay < 0)
    {
        --iPhut;
        iGiay += 60;
    }
    if (iPhut < 0)
    {
        --iGio;
        iPhut += 60;
    }
    return ThoiGian(iGio, iPhut, iGiay);
}

ThoiGian ThoiGian::operator+(int Giay) 
{
    ThoiGian T = *this;
    T.iGiay += Giay;
    while (T.iGiay >= 60)
    {
        ++T.iPhut;
        T.iGiay -= 60;
    }
    while (T.iPhut >= 60)
    {
        ++T.iGio;
        T.iPhut -= 60;
    }
    return T;
}

ThoiGian ThoiGian::operator-(int Giay) 
{
    ThoiGian T = *this;
    T.iGiay -= Giay;
    while (T.iGiay < 0)
    {
        --T.iPhut;
        T.iGiay += 60;
    }
    while (T.iPhut < 0)
    {
        --T.iGio;
        T.iPhut += 60;
    }
    return T;
}

ThoiGian ThoiGian::operator+(ThoiGian& Ts) 
{
    ThoiGian T;
    T.iGio = this->iGio + Ts.iGio;
    T.iPhut = this->iPhut + Ts.iPhut;
    T.iGiay = this->iGiay + Ts.iGiay;
    if (T.iGiay >= 60)
    {
        ++T.iPhut;
        T.iGiay -= 60;
    }
    if (T.iPhut >= 60)
    {
        ++T.iGio;
        T.iPhut -= 60;
    }
    return T;
}

ThoiGian ThoiGian::operator-(ThoiGian& Ts) 
{
    ThoiGian T;
    T.iGio = this->iGio - Ts.iGio;
    T.iPhut = this->iPhut - Ts.iPhut;
    T.iGiay = this->iGiay - Ts.iGiay;
    if (T.iGiay < 0)
    {
        --T.iPhut;
        T.iGiay += 60;
    }
    if (T.iPhut < 0)
    {
        --T.iGio;
        T.iPhut += 60;
    }
    return T;
}

bool operator<(ThoiGian& T1, ThoiGian& T2)
{
    if (T1.iGio < T2.iGio)
        return true;
    else if (T1.iGio == T2.iGio && T1.iPhut < T2.iPhut)
        return true;
    else if (T1.iGio == T2.iGio && T1.iPhut == T2.iPhut && T1.iGiay < T2.iGiay)
        return true;
    else
        return false;
}

bool operator>(ThoiGian& T1, ThoiGian& T2)
{
    return !(T1 < T2) && !(T1 == T2);
}

bool operator==(ThoiGian& T1, ThoiGian& T2)
{
    return T1.iGio == T2.iGio && T1.iPhut == T2.iPhut && T1.iGiay == T2.iGiay;
}

bool operator!=(ThoiGian& T1, ThoiGian& T2)
{
    return !(T1 == T2);
}

bool operator<=(ThoiGian& T1, ThoiGian& T2)
{
    return (T1 < T2) || (T1 == T2);
}

bool operator>=(ThoiGian& T1, ThoiGian& T2)
{
    return (T1 > T2) || (T1 == T2);
}
int main()
{
    ThoiGian T1, T2;
    cout << "Nhap thoi gian T1: " << endl;
    cin >> T1;
    cout << "Nhap thoi gian T2: " << endl;
    cin >> T2;

    cout << "T1: " << T1;
    cout << "T2: " << T2;

    ThoiGian T3 = T1 + T2;
    cout << "T1 + T2: " << T3;

    ThoiGian T4 = T1 - T2;
    cout << "|T1 - T2|: " << T4;

    ThoiGian T5 = T1 + 120;
    cout << "T1 + 120 giay: " << T5;

    ThoiGian T6 = T2 - 50;
    cout << "T2 - 50 giay: " << T6;

    ++T1;
    cout << "T1 sau khi tang 1 giay: " << T1;

    --T2;
    cout << "T2 sau khi giam 1 giay: " << T2;

    if (T1 > T2)
        cout << "T1 lon hon T2." << endl;
    else if (T1 < T2)
        cout << "T1 nho hon T2." << endl;
    else
        cout << "T1 bang T2." << endl;

    return 0;
}
