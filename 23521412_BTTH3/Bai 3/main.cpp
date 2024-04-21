#include "ThoiGian.cpp"
#include <iostream>

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

