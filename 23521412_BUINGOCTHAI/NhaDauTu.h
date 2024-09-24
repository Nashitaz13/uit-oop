#pragma once
#include "DoiTuong.h"
#include "NhaCai.h"

class NhaDauTu : public DoiTuong {
public:
    NhaDauTu(int id, double sodu);
    void capNhatSoDuSauGiaoDich(double soTienLoi, NhaCai* nhaCai);
};
