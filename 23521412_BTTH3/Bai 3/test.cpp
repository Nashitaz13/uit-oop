#include <iostream>
#include <iomanip>
#include <math.h>
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
    friend bool operator<(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator>=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator<=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator!=(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator==(const ThoiGian& T1,const ThoiGian& T2);
    friend bool operator>(const ThoiGian& T1, const ThoiGian& T2);
};

int ThoiGian::TinhGiay() 
{
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) 
{
    iGio = Giay / 3600;
    int GiayConLai = Giay % 3600;
    iPhut = GiayConLai / 60;
    iGiay = GiayConLai % 60;
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
    if (T.iGio == 24) {os << "00:";}
    else
    {
        os << setfill('0') << setw(2) << T.iGio << ":";
    }
       os << setfill('0') << setw(2) << T.iPhut << ":"
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
    if (T.iGio >= 24)
    {
       T.iGio = T.iGio % 24;
    }
    return T;
}

ThoiGian ThoiGian::operator-(ThoiGian& Ts) 
{
    ThoiGian T;
    T.iGio = this->iGio - Ts.iGio;
    T.iPhut = this->iPhut - Ts.iPhut;
    T.iGiay = this->iGiay - Ts.iGiay;

    // Đảo dấu nếu kết quả là âm
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
    if (T.iGio < 0)
    {
        T.iGio = abs(T.iGio);
        T.iPhut = abs(T.iPhut);
        T.iGiay = abs(T.iGiay);
    }
    return T;
}


bool operator<(const ThoiGian& T1, const ThoiGian& T2)
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

bool operator>(const ThoiGian& T1,const ThoiGian& T2)
{
    return !(T1 < T2) && !(T1 == T2);
}

bool operator==(const ThoiGian& T1, const ThoiGian& T2)
{
    return T1.iGio == T2.iGio && T1.iPhut == T2.iPhut && T1.iGiay == T2.iGiay;
}

bool operator!=(const ThoiGian& T1,const ThoiGian& T2)
{
    return !(T1 == T2);
}

bool operator<=(const ThoiGian& T1,const ThoiGian& T2)
{
    return (T1 < T2) || (T1 == T2);
}

bool operator>=(const ThoiGian& T1,const ThoiGian& T2)
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

    cout << "So giay cua thoi gian T1 la: " << T1.TinhGiay() << endl;

    int s;
    ThoiGian t;
    cout << "Nhap so giay 1: " << endl;
    cin >> s;
    t.TinhLaiGio(s);
    cout << "So gio ung voi so giay " << s << " la: " << t;

    ThoiGian T3 = T1 + T2;
    cout << "T3 = T1 + T2: " << T3;

    ThoiGian T4 = T1 - T2;
    cout << "T4 = T1 - T2: " << T4;

    ThoiGian T5 = T1 + 120;
    cout << "T5 = T1 + 120 giay: " << T5;

    ThoiGian T6 = T2 - 50;
    cout << "T6 = T2 - 50 giay: " << T6;

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
    if (T3 <= T4) {
        cout << "T3 nho hon hoac bang T4." << endl;
    } else if (T3 >= T4){
        cout << "T3 lon hon hoac bang T4." << endl;
    }

    if (T5 == T6){
        cout << "T5 bang T6" << endl;
    } else if (T5 != T6) {
        cout << "T5 khac T6" << endl;
    }

    return 0;
}
