#include "SoPhuc.cpp"
#include <iostream>

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