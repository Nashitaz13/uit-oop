#include <iostream>
using namespace std;

class SoPhuc {
private:
	double dThuc, dAo;
public:
	SoPhuc() : dThuc(0), dAo(0) {}
	SoPhuc(double dThuc, double dAo) : dThuc(dThuc), dAo(dAo) {}
	friend SoPhuc operator + (SoPhuc a, SoPhuc b);
	friend SoPhuc operator - (SoPhuc a, SoPhuc b);
	friend SoPhuc operator * (SoPhuc a, SoPhuc b);
	friend SoPhuc operator / (SoPhuc a, SoPhuc b);
	friend bool operator == (SoPhuc a, SoPhuc b);
	friend bool operator != (SoPhuc a, SoPhuc b);
	friend istream& operator >> (istream &is, SoPhuc &p);
	friend ostream& operator << (ostream &os, SoPhuc p);
};

SoPhuc operator + (SoPhuc a, SoPhuc b) {
	double thuc = a.dThuc + b.dThuc;
	double ao = a.dAo + b.dAo;
	return SoPhuc(thuc, ao);
}

SoPhuc operator - (SoPhuc a, SoPhuc b) {
	double thuc = a.dThuc - b.dThuc;
	double ao = a.dAo - b.dAo;
	return SoPhuc(thuc, ao);
}

SoPhuc operator * (SoPhuc a, SoPhuc b) {
	double thuc = a.dThuc * b.dThuc - a.dAo * b.dAo;
	double ao = a.dThuc * b.dAo + a.dAo * b.dThuc;
	return SoPhuc(thuc, ao);
}

SoPhuc operator / (SoPhuc a, SoPhuc b) {
	double mau = b.dThuc * b.dThuc + b.dAo * b.dAo;
	if (mau == 0) {
		cout << "Khong the chia cho so phuc co gia tri bang 0." << endl;
		return a;
	}
	double thuc = (a.dThuc * b.dThuc + a.dAo * b.dAo) / mau;
	double ao = (a.dAo * b.dThuc - a.dThuc * b.dAo) / mau;
	return SoPhuc(thuc, ao);
}

bool operator == (SoPhuc a, SoPhuc b) {
	return a.dThuc == b.dThuc && a.dAo == b.dAo;
}

bool operator != (SoPhuc a, SoPhuc b) {
	return !(a == b);
}

istream& operator >> (istream &is, SoPhuc &p) {
	cout << "Nhap phan thuc: ";
	is >> p.dThuc;
	cout << "Nhap phan ao: ";
	is >> p.dAo;
	return is;
}

ostream& operator << (ostream &os, SoPhuc p)
{
	if (p.dThuc == 0)
	{
		if (p.dAo == 1)
			os << "(i)";
		if(p.dAo == -1)
			os << "(-i)";
		if(p.dAo != 1 && p.dAo != -1)
			os << "(" << p.dAo << "i)";
	}
	if(p.dThuc != 0.0)
	{
		if((p.dAo > 0 && p.dAo < 1) || p.dAo > 1)
			os << "(" << p.dThuc << "+" << p.dAo <<"i)";
		if(p.dAo == 1)
			os << "(" << p.dThuc << "+" <<"i)";
		if(p.dAo == 0)
			os<<p.dThuc;
		if(p.dAo == -1)
			os << "(" << p.dThuc << "-i)";
		if((p.dAo >-1.0 && p.dAo < 0) || p.dAo < -1)
			os << "(" << p.dThuc << p.dAo << "i)";
	}
	return os;
}

int main() {
	SoPhuc a, b, c;
	cout << "Nhap so phuc a:" << endl;
	cin >> a;
	cout << "Nhap so phuc b:" << endl;
	cin >> b;
	cout << "So phuc c: " << c << endl;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a-b << endl;
	cout<< a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b <<endl;
	cout << "a == b: " << (a == b ? "Dung" : "Sai") << endl;
	cout << "a != b: " << (a != b ? "Dung" : "Sai") << endl;
	return 0;
}
