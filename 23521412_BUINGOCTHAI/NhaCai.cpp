
#include "NhaCai.h"
#include "CoMoi.h"
#include "NhaDauTu.h"

NhaCai::NhaCai(int id, double sodu) : DoiTuong(id, 1, sodu) {}

void NhaCai::quyetDinhKetQua(DoiTuong* doiTuongs[], int cuoc[MAX_CUOC][4], int soCuoc) {
    double tongLen = 0;
    double tongXuong = 0;

    for (int i = 0; i < soCuoc; i++) {
      int traderID = cuoc[i][0];
      int loaiCuoc = cuoc[i][1];
      int huongCuoc = cuoc[i][2];
      double soTienCuoc = cuoc[i][3];

      for (int j = 0; j < MAX_DOITUONG; j++) {
        if (doiTuongs[j] && doiTuongs[j]->layID() == traderID) {
          if (doiTuongs[j]->laySoDu() >= soTienCuoc) {
            if (huongCuoc == 1) {
              tongLen += soTienCuoc;
            } else if (huongCuoc == 0) {
              tongXuong += soTienCuoc;
            }
          }
        }
      }
    }

    bool ketQuaLen = tongLen < tongXuong;
    for (int i = 0; i < soCuoc; i++) {
      int traderID = cuoc[i][0];
      int loaiCuoc = cuoc[i][1];
      int huongCuoc = cuoc[i][2];
      double soTienCuoc = cuoc[i][3];

      for (int j = 0; j < MAX_DOITUONG; j++) {
        if (doiTuongs[j] && doiTuongs[j]->layID() == traderID) {
          if (doiTuongs[j]->laySoDu() >= soTienCuoc) {
            for (int k = 0; k < MAX_DOITUONG; k++) {
              if (doiTuongs[k] && doiTuongs[k]->layLoai() == 2) {
                CoMoi* coMoi = static_cast<CoMoi*>(doiTuongs[k]);
                if (coMoi->layTraderID() == doiTuongs[j]->layID()) {
                  coMoi->ChiaSeHoaHong(soTienCuoc);
                  SoDu -= soTienCuoc * 0.01; // Tr? s? du c?a NhaCai theo hoa h?ng
                }
              }
            }
            if (huongCuoc == ketQuaLen) {
              double tienThuong = soTienCuoc * (loaiCuoc == 0 ? 1 : 1.5);
              if (SoDu >= tienThuong) {
                doiTuongs[j]->capNhatSoDu(tienThuong);
                SoDu -= tienThuong;
                if (doiTuongs[j]->layLoai() == 3) {
                  NhaDauTu* nhaDauTu = static_cast<NhaDauTu*>(doiTuongs[j]);
                  nhaDauTu->capNhatSoDuSauGiaoDich(tienThuong, this);
                }
              }
            } else {
              doiTuongs[j]->capNhatSoDu(-soTienCuoc);
              SoDu += soTienCuoc;
            }
          }
        }
      }
    }
}
