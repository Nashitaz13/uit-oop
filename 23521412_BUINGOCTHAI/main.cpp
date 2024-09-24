#include "DoiTuong.h"
#include "CoMoi.h"
#include "NhaDauTu.h"
#include "NhaCai.h"

void inSoDuDoiTuong(DoiTuong* doiTuongs[], int n);

int main() {
    int n, m;
    std::cin >> n >> m;

    DoiTuong* doiTuongs[MAX_DOITUONG] = {nullptr};

    for (int i = 0; i < n; i++) {
        int id, loai;
        std::cin >> id >> loai;
        if (loai == 1) {
            double sodu;
            std::cin >> sodu;
            doiTuongs[i] = new NhaCai(id, sodu);
        } else if (loai == 2) {
            int traderId;
            std::cin >> traderId;
            doiTuongs[i] = new CoMoi(id, traderId);
        } else if (loai == 3) {
            double sodu;
            std::cin >> sodu;
            doiTuongs[i] = new NhaDauTu(id, sodu);
        }
    }

    for (int i = 0; i < n; i++) {
        doiTuongs[i]->InThongTin();
    }

    int cuoc[MAX_CUOC][4];
    int soCuoc = 0;

    for (int i = 0; i < m; i++) {
        while (true) {
            int idNguoiChoi, loaiCuoc, huongCuoc, soTienCuoc;
            std::cin >> idNguoiChoi;
            if (idNguoiChoi == -1) break;
            std::cin >> loaiCuoc >> huongCuoc >> soTienCuoc;

            cuoc[soCuoc][0] = idNguoiChoi;
            cuoc[soCuoc][1] = loaiCuoc;
            cuoc[soCuoc][2] = huongCuoc;
            cuoc[soCuoc][3] = soTienCuoc;
            soCuoc++;
        }
	
        for (int j = 0; j < soCuoc; j++) {
        std::cout << cuoc[j][0] << " " 
                  << cuoc[j][1] << " " 
                  << cuoc[j][2] << " " 
                  << cuoc[j][3] << std::endl;
    	}

        for (int j = 0; j < n; j++) {
            if (doiTuongs[j] && doiTuongs[j]->layLoai() == 1) {
                NhaCai* nhaCai = static_cast<NhaCai*>(doiTuongs[j]);
                nhaCai->quyetDinhKetQua(doiTuongs, cuoc, soCuoc);
            }
        }
        soCuoc = 0;
    }

    inSoDuDoiTuong(doiTuongs, n);

    for (int i = 0; i < n; i++) {
        delete doiTuongs[i];
    }
}


void inSoDuDoiTuong(DoiTuong* doiTuongs[], int n) {
    for (int i = 0; i < n; i++) {
        if (doiTuongs[i]) {
            std::cout << doiTuongs[i]->layID() << " " 
                      << std::fixed << std::setprecision(1) << doiTuongs[i]->laySoDu() << std::endl;
        }
    }
}