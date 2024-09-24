#pragma once
#include "DoiTuong.h"

class NhaCai : public DoiTuong {
public:
    NhaCai(int id, double sodu);
    void quyetDinhKetQua(DoiTuong* doiTuongs[], int cuoc[MAX_CUOC][4], int soCuoc);
};
