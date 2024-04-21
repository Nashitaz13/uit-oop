#pragma once
#include "SoPhuc.h"
#include <iostream>

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