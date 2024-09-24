#pragma once
#include "DoiTuong.h"

class CoMoi : public DoiTuong {
protected:
    int TraderID;
public:
    CoMoi(int id, int traderId);
    void InThongTin() override;
    void ChiaSeHoaHong(double giaoDich);
    int layTraderID() const;
};