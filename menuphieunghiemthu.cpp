
#include <iostream>
#include <string>
#include <fstream>
#include "EntityVaRepository.h"
#include <limits>
#include <iomanip>
#include <memory>
#include "caclop.h"
#include <sstream>
#include "TienichVangoaile.h"


void menuPhieuNghiemThu(Repository<phieunghiemthu>& repoPNT, Repository<DuAn>& repoDA) {
    int choice;
    do {
        cout << "\n--- QUAN LY PHIEU NGHIEM THU ---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n5. Xem chi tiet (Kem thong tin Du An)\n0. Quay lai\nChon: ";
        choice = NhapSoMenu(); 

        try {
            if(choice == 1) {
                cout << "Ma Phieu  | Ten Phieu            | Ngay Lap       | Ma Du An       | Danh gia\n"
                     << string(80,'-') << endl;
                repoPNT.displayall();
            }
            else if(choice == 2) {
                shared_ptr<phieunghiemthu> pnt = make_shared<phieunghiemthu>();
                pnt->Nhap();
            
                repoPNT.add(pnt);
                cout << "Them thanh cong!\n";
            }
            else if(choice == 3) {
                string ma; cout << "Nhap Ma Phieu can sua: "; getline(cin, ma);
                shared_ptr<phieunghiemthu> pnt = repoPNT.findById(ma);
                if(pnt) { pnt->Capnhat(); repoPNT.SaveToFile(); cout << "Sua thanh cong\n"; }
                else cout << "Khong tim thay phieu!\n";
            }
            else if(choice == 4) {
                string ma; cout << "Nhap ma Phieu can xoa: "; getline(cin, ma);
                repoPNT.remove(ma);
            }
            else if(choice == 5) { 
                string ma; cout << "Nhap Ma Phieu Nghiem Thu de xem chi tiet: "; getline(cin, ma);
                shared_ptr<phieunghiemthu> pnt = repoPNT.findById(ma);
                if(pnt) {
                    cout << string(50, '=') << endl;
                    pnt->xuatchitietDA(repoDA);
                    cout << string(50, '=') << endl;
                }
                else cout << "Khong tim thay phieu nghiem thu!\n";
            }
        } catch(exception& e) { cout << "Loi: " << e.what() << endl; }
    } while(choice != 0);
}
