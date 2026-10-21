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
void menuCRUD(Repository<T>& repo , string title , string headers){
    int choice;
    do {
        cout << "\n--- QUAN LY " << title << "---\n";
        cout << "1. Xem danh sach\n2. Them moi\n3. Sua\n4. Xoa\n0. Quay lai\nchon:";
        choice = NhapSoMenu();
        try{
            if(choice == 1) {
                cout << headers << endl << string(80,'-') << endl; 
                repo.displayall();
            }
            else if(choice == 2){
                shared_ptr<T> obj = make_shared<T>();
                obj->Nhap();
                repo.add(obj);
                cout << "Them thanh cong !\n";
            }
            else if(choice == 3){
                string ma; cout << "Nhap ma:" ; getline(cin,ma);
                shared_ptr<T> obj = repo.findById(ma);
                if(obj) {
                    obj -> Capnhat();
                    repo.SaveToFile();
                    cout << "Sua thanh cong\n";
                }
                else{
                    cout << "Khong tim thay ! \n";
                }
            }
            else if(choice == 4){
                string ma ;
                cout << "Nhap ma :"; getline(cin,ma);
                repo.remove(ma);
            }
        }catch(exception& e) {
            cout << "Loi :" << e.what() << endl;
        }
    }while(choice !=0);
}
