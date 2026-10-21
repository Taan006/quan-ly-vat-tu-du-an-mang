#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "EntityVaRepository.h"
#include <limits>
#include <iomanip>
#include <memory>
#include "Phieukho.h"
#include "caclop.h"
#include <sstream>
#include "TienichVangoaile.h"

using namespace std;

template <class T>
void menuHoaDonXuat(Repository<hoadonxuat>& repoHDX, Repository<Vattu>& repoVT) {
    int choice;
    do {
        cout << "\n--- QUAN LY HOA DON XUAT ---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n5. Xem chi tiet (Kem thong tin Vat tu)\n0. Quay lai\nChon: ";
        cin >> choice; 
        if(cin.fail()) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); choice = -1; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            if(choice == 1) {
                cout << left << setw(10) << "Ma HD" << "| " << setw(20) << "Ten HD" << "| " 
                     << setw(20) << "Ngay Lap" << "| " << setw(20) << "So Luong" << "| " 
                     << setw(20) << "Don Gia" << "| " << "Tong Tien\n" << string(105,'-') << endl;
                repoHDX.displayall();
            }
            else if(choice == 2) {
                shared_ptr<hoadonxuat> hdx = make_shared<hoadonxuat>();
                hdx->Nhap();
                repoHDX.add(hdx);
                cout << "Them thanh cong!\n";
            }
            else if(choice == 3) {
                string ma; cout << "Nhap Ma HD can sua: "; getline(cin, ma);
                shared_ptr<hoadonxuat> hdx = repoHDX.findById(ma);
                if(hdx) { hdx->Capnhat(); repoHDX.SaveToFile(); cout << "Sua thanh cong\n"; }
                else cout << "Khong tim thay!\n";
            }
            else if(choice == 4) {
                string ma; cout << "Nhap ma HD can xoa: "; getline(cin, ma);
                repoHDX.remove(ma);
            }
            else if(choice == 5) {
                string ma; cout << "Nhap Ma HD de xem chi tiet: "; getline(cin, ma);
                shared_ptr<hoadonxuat> hdx = repoHDX.findById(ma);
                if(hdx) {
                    cout << string(50, '=') << endl;
                    hdx->xuatchitiet(repoVT); 
                    cout << string(50, '=') << endl;
                } else cout << "Khong tim thay hoa don!\n";
            }
        } catch(exception& e) { cout << "Loi: " << e.what() << endl; }
    } while(choice != 0);
}

void menuHoaDonNhanCong(Repository<hoadonnhancong>& repoHDNC, Repository<doithicong>& repoDTC) {
    int choice;
    do {
        cout << "\n--- QUAN LY HOA DON NHAN CONG ---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n5. Xem chi tiet (Kem thong tin Doi thi cong)\n0. Quay lai\nChon: ";
        cin >> choice; 
        if(cin.fail()) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); choice = -1; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            if(choice == 1) {
                cout << left << setw(10) << "Ma HD" << "| " << setw(20) << "Ten HD" << "| " 
                     << setw(20) << "Ngay Lap" << "| " << setw(20) << "So Luong" << "| " 
                     << setw(20) << "Don Gia" << "| " << "Tong Tien\n" << string(105,'-') << endl;
                repoHDNC.displayall();
            }
            else if(choice == 2) {
                shared_ptr<hoadonnhancong> hdnc = make_shared<hoadonnhancong>();
                hdnc->Nhap();
                repoHDNC.add(hdnc);
                cout << "Them thanh cong!\n";
            }
            else if(choice == 3) {
                string ma; cout << "Nhap Ma HD can sua: "; getline(cin, ma);
                shared_ptr<hoadonnhancong> hdnc = repoHDNC.findById(ma);
                if(hdnc) { hdnc->Capnhat(); repoHDNC.SaveToFile(); cout << "Sua thanh cong\n"; }
                else cout << "Khong tim thay!\n";
            }
            else if(choice == 4) {
                string ma; cout << "Nhap ma HD can xoa: "; getline(cin, ma);
                repoHDNC.remove(ma);
            }
            else if(choice == 5) {
                string ma; cout << "Nhap Ma HD de xem chi tiet: "; getline(cin, ma);
                shared_ptr<hoadonnhancong> hdnc = repoHDNC.findById(ma);
                if(hdnc) {
                    cout << string(50, '=') << endl;
                    hdnc->xuatchitiet(repoDTC);
                    cout << string(50, '=') << endl;
                } else cout << "Khong tim thay hoa don!\n";
            }
        } catch(exception& e) { cout << "Loi: " << e.what() << endl; }
    } while(choice != 0);
}

}