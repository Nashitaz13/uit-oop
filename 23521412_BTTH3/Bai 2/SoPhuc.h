#pragma once 
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