#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "EntityVaRepository.h"
#include <limits>
#include <iomanip>
#include <memory>
#include "PhieuKho.h"
#include "caclop.h"
#include <sstream>
#include "TienichVangoaile.h"

using namespace std;

template <class T>

void menudoithicong(Repository<doithicong>& repoDTC, Repository<DuAn>& repoDA) {
    int choice;
    do {
        cout << "\n--- QUAN LY DOI THI CONG ---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n5. Xem chi tiet (Kem thong tin Du An)\n0. Quay lai\nChon: ";
        choice = NhapSoMenu(); 

        try {
            if(choice == 1) {
                cout << "Ma DTC  | Ten DTC           | SO NC      | Ma Du An  PHU TRACH\n"
                     << string(80,'-') << endl;
                repoDTC.displayall();
            }
            else if(choice == 2) {
                shared_ptr<doithicong> dtc = make_shared<doithicong>();
                dtc->Nhap();
            
                repoDTC.add(dtc);
                cout << "Them thanh cong!\n";
            }
            else if(choice == 3) {
                string ma; cout << "Nhap Ma DTC can sua: "; getline(cin, ma);
                shared_ptr<doithicong> dtc = repoDTC.findById(ma);
                if(dtc) { dtc->Capnhat(); repoDTC.SaveToFile(); cout << "Sua thanh cong\n"; }
                else cout << "Khong tim thay DTC!\n";
            }
            else if(choice == 4) {
                string ma; cout << "Nhap ma DTC can xoa: "; getline(cin, ma);
                repoDTC.remove(ma);
            }
            else if(choice == 5) { 
                string ma; cout << "Nhap Ma DTC de xem chi tiet DA phu trach: "; getline(cin, ma);
                shared_ptr<doithicong> dtc = repoDTC.findById(ma);
                if(dtc) {
                    cout << string(50, '=') << endl;
                    dtc->xuatchitietDA(repoDA);
                    cout << string(50, '=') << endl;
                }
                else cout << "Khong tim thay doi thi cong!\n";
            }
        } catch(exception& e) { cout << "Loi: " << e.what() << endl; }
    } while(choice != 0);
}
