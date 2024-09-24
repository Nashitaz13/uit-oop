#include <bits/stdc++.h>

using namespace std;

string chuan(string name){
	stringstream ss(name);
	string res = "";
	string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i = 1; i < token.length(); i++) res += tolower(token[i]);
		res += " ";
	}
	res.erase(res.length() - 1);
	return res;
}

class ThiSinh {
    string Ten, MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    void Nhap();
    void Xuat();
    float Tong();
};

void ThiSinh::Nhap() {
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, Ten);
    Ten = chuan(Ten);
    cout << "Nhap MSSV: "; cin >> MSSV;
    cout << "Nhap ngay sinh: "; cin >> iNgay;
    cout << "Nhap thang sinh: "; cin >> iThang;
    cout << "Nhap nam sinh: "; cin >> iNam;
    cout << "Nhap diem Toan: "; cin >> fToan;
    cout << "Nhap diem Van: "; cin >> fVan;
    cout << "Nhap diem Anh: "; cin >> fAnh;
}

void ThiSinh::Xuat() {
    cout << "Ten: " << Ten;
    cout << ", MSSV: " << MSSV;
    cout << ", Ngay sinh: " << setfill('0') << setw(2) << iNgay;
    cout << "/" << setfill('0') << setw(2) << iThang << "/" << iNam;
    cout << ", Diem Toan: " << fToan;
    cout << ", Diem Van: " << fVan;
    cout << ", Diem Anh: " << fAnh << endl;
}


float ThiSinh::Tong() {
    return fToan + fVan + fAnh;
}

int main() {
    int n;
    cout << "Nhap so luong thi sinh: "; cin >> n;
    ThiSinh *arr = new ThiSinh[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh thu " << i+1 << ": " << endl;
        arr[i].Nhap();
    }

    cout << "Thi sinh co tong diem lon hon 15: " << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i].Tong() > 15) {
            arr[i].Xuat();
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].Tong() > arr[maxIndex].Tong()) {
            maxIndex = i;
        }
    }
    cout << "Thi sinh co diem cao nhat: " << endl;
    arr[maxIndex].Xuat();

    delete[] arr;
    return 0;
}



