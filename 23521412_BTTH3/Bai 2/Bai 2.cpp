#include <iostream>
using namespace std;

class SoPhuc {
private:
	float thuc, ao;
public:
	SoPhuc() : thuc(0), ao(0) {}
	SoPhuc(float thuc, float ao) : thuc(thuc), ao(ao) {}
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
	return SoPhuc(a.thuc + b.thuc, a.ao + b.ao);
}

SoPhuc operator - (SoPhuc a, SoPhuc b) {
	return SoPhuc(a.thuc - b.thuc, a.ao - b.ao);
}

SoPhuc operator * (SoPhuc a, SoPhuc b) {
	return SoPhuc(a.thuc * b.thuc - a.ao * b.ao, a.thuc * b.ao + a.ao * b.thuc);
}

SoPhuc operator / (SoPhuc a, SoPhuc b) {
	float mau = b.thuc * b.thuc + b.ao * b.ao;
	if (mau == 0) {
		cout << "Không thể chia cho số phức có giá trị bằng 0." << endl;
		return a;
	}
	return SoPhuc((a.thuc * b.thuc + a.ao * b.ao) / mau, (a.ao * b.thuc - a.thuc * b.ao) / mau);
}

bool operator == (SoPhuc a, SoPhuc b) {
	return a.thuc == b.thuc && a.ao == b.ao;
}

bool operator != (SoPhuc a, SoPhuc b) {
	return !(a == b);
}

istream& operator >> (istream &is, SoPhuc &p) {
	cout << "Nhap phan thuc: ";
	is >> p.thuc;
	cout << "Nhap phan ao: ";
	is >> p.ao;
	return is;
}

ostream& operator << (ostream &os, SoPhuc p)
{
	if (p.thuc == 0)
	{
		if (p.ao == 1)
			os << "(i)";
		if(p.ao == -1)
			os << "(-i)";
		if(p.ao != 1 && p.ao != -1)
			os << "(" << p.ao << "i)";
	}
	if(p.thuc != 0.0)
	{
		if((p.ao > 0 && p.ao < 1) || p.ao > 1)
			os << "(" << p.thuc << "+" << p.ao <<"i)";
		if(p.ao == 1)
			os << "(" << p.thuc << "+" <<"i)";
		if(p.ao == 0)
			os<<p.thuc;
		if(p.ao == -1)
			os << "(" << p.thuc << "-i)";
		if((p.ao >-1.0 && p.ao < 0) || p.ao < -1)
			os << "(" << p.thuc << p.ao << "i)";
	}
	return os;
}

int main() {
	SoPhuc a, b, c;
	cout << "Nhap so phuc a:" << endl;
	cin >> a;
	cout << "Nhap so phuc b:" << endl;
	cin >> b;

    cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a-b << endl;
	cout<< a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b <<endl;

	cout << "a == b: " << (a == b ? "Dung" : "Sai") << endl;
	cout << "a != b: " << (a != b ? "Dung" : "Sai") << endl;

	return 0;
}
