
#include "NhaDauTu.h"
#include <cmath>

NhaDauTu::NhaDauTu(int id, double sodu) : DoiTuong(id, 3, sodu) {}

void NhaDauTu::capNhatSoDuSauGiaoDich(double soTienLoi, NhaCai* nhaCai) {
    double phiDuyTriSan = soTienLoi * 0.01;
    phiDuyTriSan = std::round(phiDuyTriSan * 100) / 100;
    SoDu -= phiDuyTriSan;
    nhaCai->capNhatSoDu(phiDuyTriSan); // Cập nhật số dư của NhaCai
}
