
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
#include "hoadon.h"

void menuHoaDonNhap(Repository<hoadonnhap>& repoHDN, Repository<Nhacungcap>& repoNCC) {
    int choice;
    do {
        cout << "\n--- QUAN LY HOA DON NHAP ---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n5. Xem chi tiet (Kem thong tin Vat tu)\n0. Quay lai\nChon: ";
        cin >> choice; 
        if(cin.fail()) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); choice = -1; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            if(choice == 1) {
                cout << left << setw(10) << "Ma HD" << "| " << setw(20) << "Ten HD" << "| " 
                     << setw(20) << "Ngay Lap" << "| " << setw(20) << "So Luong" << "| " 
                     << setw(20) << "Don Gia" << "| " << "Tong Tien\n" << string(105,'-') << endl;
                repoHDN.displayall();
            }
            else if(choice == 2) {
                shared_ptr<hoadonnhap> hdn = make_shared<hoadonnhap>();
                hdn->Nhap();
                repoHDN.add(hdn);
                cout << "Them thanh cong!\n";
            }
            else if(choice == 3) {
                string ma; cout << "Nhap Ma HD can sua: "; getline(cin, ma);
                shared_ptr<hoadonnhap> hdn = repoHDN.findById(ma);
                if(hdn) { hdn->Capnhat(); repoHDN.SaveToFile(); cout << "Sua thanh cong\n"; }
                else cout << "Khong tim thay!\n";
            }
            else if(choice == 4) {
                string ma; cout << "Nhap ma HD can xoa: "; getline(cin, ma);
                repoHDN.remove(ma);
            }
            else if(choice == 5) {
                string ma; cout << "Nhap Ma HD de xem chi tiet: "; getline(cin, ma);
                shared_ptr<hoadonnhap> hdn = repoHDN.findById(ma);
                if(hdn) {
                    cout << string(50, '=') << endl;
                    hdn->xuatchitiet(repoNCC);
                    cout << string(50, '=') << endl;
                } else cout << "Khong tim thay hoa don!\n";
            }
        } catch(exception& e) { cout << "Loi: " << e.what() << endl; }
    } while(choice != 0);
}
