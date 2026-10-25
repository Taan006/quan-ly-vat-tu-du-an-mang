#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <iomanip>
#include <limits>
#include <sstream>
#include "EntityVaRepository.h"
#include "TienichVangoaile.h"
#include "caclop.h"

using namespace std;

void menuVattu(Repository<Vattu>& repoVT, Repository<Nhacungcap>& repoNCC){
	int choice;
	do{
		cout << "\n--- QUAN LY VAT TU ---\n";
		cout << "1. Xem danh sach \n2. Them moi \n3. Sua \n4. Xoa \n5. Xem chi tiet(kem thong tin nha cung cap) \n0. Quay lai \nChon: ";
		choice = NhapSoMenu();
		try{
			if(choice == 1) {
				cout << "Ma VT | Ten VT | Don gia | So luong | Don vi | Ma NCC \n"
				<< string(80,'-') << endl;
				repoVT.displayall();
			} else if (choice == 2){
				shared_ptr<Vattu> vt = make_shared<Vattu>();
				vt -> Nhap();
				repoVT.add(vt);
				cout << "Them thanh cong!" << endl;
			} else if (choice == 3){
				string ma;
				cout << "Nhap ma can sua:";
				getline (cin, ma);
				shared_ptr<Vattu> vt = repoVT.findById(ma);
				if(vt) {
					vt -> Capnhat();
					repoVT.SaveToFile();
					cout << "Sua thanh cong!" << endl;
				} else cout << "Khong tim thay vat tu!" << endl;
			} else if (choice == 4) {
				string ma;
				cout << "Nhap ma can xoa :";
				getline (cin, ma);
				repoVT.remove(ma);
			} else if( choice == 5){
				string ma;
				cout << "Nhap ma can xem chi tiet:";
				getline (cin, ma);
				shared_ptr<Vattu> vt = repoVT.findById(ma);
				if(vt){
					cout << string(50,'=') << endl;
					vt -> xuatchitietNCC(repoNCC);
					cout << string(50,'=') << endl;
				} else cout << "Khong tim thay vat tu!" << endl;
			}
		} catch (exception& e) {
			cout << "Loi: " << e.what() << endl;
		}
	} while(choice != 0);
}
