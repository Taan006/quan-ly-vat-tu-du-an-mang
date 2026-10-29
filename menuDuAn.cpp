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
void menuDuAn(Repository<T>& repoDA ){
    int choice;
    do {
        cout << "\n--- QUAN LY DU AN " << title << "---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n0. Quay lai\nchon:";
        choice = NhapSoMenu();
        try{
            if(choice == 1) {
                cout << left << setw(10) << "MA DA" <<"| " << setw(60) << "Ten DA" <<"| " 
                << setw(15) <<"Ngay Bat Dau" <<"| " << setw(15) << "Ngay Ket Thuc" <<"| " << setw(25) 
                << "Trang Thai" <<"| \n" << string(150,'-') << endl;
 				repoDA.displayall();
            }
            else if(choice == 2){
                while (true) {
                    try {
                        shared_ptr<Vattu> vt = make_shared<Vattu>();
                        vt->Nhap();
                    
                        repoVT.add(vt);
                        cout << "Them thanh cong!\n";
                        break; 
                    } catch(const exception& e) {
                        cout << "[Loi] " << e.what() << " Vui long nhap lai!\n";
                    }
                }
            }
            else if(choice == 3){
                string ma; 
                cout << "Nhap ma du an can sua:" ;
                getline(cin,ma);
                shared_ptr<DuAn> da = repoDA.findById(ma);
                if(da) {
                    da -> Capnhat();
                    repoDA.SaveToFile();
                    cout << "Sua thanh cong!"<< endl;
                }
                else{
                    cout << "Khong tim thay ! \n";
                }
            }
            else if(choice == 4){
                string ma ;
                cout << "Nhap ma du an can xoa:"; 
                getline(cin,ma);
                repoDA.remove(ma);
                cout << "Xoa thanh cong!\n";
            }
        }catch(exception& e) {
            cout << "Loi :" << e.what() << endl;
        }
    }while(choice !=0);
}
