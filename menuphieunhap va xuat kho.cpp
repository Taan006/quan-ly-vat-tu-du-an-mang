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


void menuphieunhap(Repository<phieunhap>& repopn, Repository<Vattu>& repovt){
    int choice;
    do{
        cout << "\n---Phieu Nhap Kho---\n";
        cout << "1. Xem danh sach\n2. Lap phieu nhap\n3. Sua\n4. Xoa phieu\n0. Quay lai\nChon:";
        choice = NhapSoMenu();

        try{
            if(choice == 1){
               cout << left << setw(10) << "MA Phieu" << "| " << setw(15) << "Ngay Lap" << "| " 
                << setw(10) << "Ma NCC" << "| " << setw(20) << "MA VT" << "| " << setw(12) 
                << "So luong" << "| " << setw(15) << "Don gia\n" << string(90,'-')<< endl;
                repopn.displayall();
            
            }
            else if(choice == 2){
                shared_ptr<phieunhap> pn = make_shared<phieunhap>(); 
                pn ->Nhap();
                shared_ptr<Vattu> vt = repovt.findById(pn->getmaVT());

                if (!vt) throw ValidationException("Ma vat tu khong khong ton tai!");

                vt -> setsoluong(vt->getsoluong() + pn -> getsoluong() );
                repovt.SaveToFile(); 
                repopn.add(pn);
                cout << "-> Lap phieu thanh cong ! Da cong so vao kho.\n";
            }
            else if(choice == 3 ){
                string ma; cout << "Nhap ma PN can sua : "; getline(cin, ma);
               shared_ptr<phieunhap> pn = repopn.finById(ma);
                if(pn){
                    pn-> Capnhat();
                    repopn.Savetofile();
                    cout<<"Capnhatthanhcong.!\n";
            }
                esle{
                    cout << "Khong tim thay phieu nhap co ma:" << ma << "trong he thong\n";
                    }
            else if(choice == 4){
                string ma; cout << "Nhap Ma Phieu De Xoa:"; getline(cin,ma);
                shared_ptr<phieunhap> pn = repopn.findById(ma);
                if(pn){
                    shared_ptr<Vattu> vt = repovt.findById(pn->getmaVT());

                    if(vt) {vt->setsoluong(vt->getsoluong() - pn -> getsoluong());
                         repovt.SaveToFile();
                        }
                    repopn.remove(ma);
                        
                }
                else cout << "Khong tim thay Phieu!\n";
            }
        }catch (exception& e) { cout << "Loi :" << e.what() << endl;}
    }while(choice != 0);
}

void menuphieuxuat(Repository<phieuxuat>& repopx , Repository<Vattu>& repovt){
    int choice;
    do{
        cout << "\n---Phieu Xuat Kho---\n";
        cout << "1. Xem danh sach\n2. Lap Phieu Xuat\n3. Sua\n4. Xoa phieu\n0. Quay lai\nchon: ";
        choice = NhapSoMenu();
        try{
            if(choice == 1){
                cout << left << setw(10) << "MA Phieu" << "| " << setw(15) << "Ngay Lap" << "| " 
                << setw(10) << "Ma DA" << "| " << setw(20) << "MA VT" << "| " << setw(12) 
                << "So luong" << "| " << setw(15) << "Don gia\n" << string(90,'-')<< endl;
                repopx.displayall();

            }
            else if(choice == 2){
                shared_ptr<phieuxuat> px = make_shared<phieuxuat>(); px->Nhap();
                shared_ptr<Vattu> vt = repovt.findById(px->getmaVT());
                if(!vt) throw ValidationException("Ma Vat tu khong ton tai!");

                if(vt-> getsoluong() < px-> getsoluong()){
                    throw ValidationException("kho khong du so luong de xuat! (hien co :" + to_string(vt->getsoluong())+")");
                }
                vt-> setsoluong(vt->getsoluong() - px-> getsoluong());
                repovt.SaveToFile();
                repopx.add(px);

                cout << "-> Lap phieu thanh cong! Da tru so luong kho.\n";
            }
            else if(choice == 3){
               string ma; cout << "Nhap ma PX can sua : "; getline(cin, ma);
               shared_ptr<phieuxuat> px = repopx.finById(ma);
                if(px){
                    px-> Capnhat();
                    repopx.Savetofile();
                    cout<<"Capnhatthanhcong.!\n";
            }
                esle{
                    cout << "Khong tim thay phieu xuat co ma:" << ma << "trong he thong\n";
                    }
            }
            else if(choice == 4){
                string ma; cout << "Nhap ma Phieu Xuat de xoa:"; getline(cin,ma);
                shared_ptr<phieuxuat> px = repopx.findById(ma);
                if(px){
                    shared_ptr<Vattu> vt = repovt.findById(px->getmaVT());

                    if(vt) {
                        vt-> setsoluong(vt->getsoluong() + px-> getsoluong());
                        repovt.SaveToFile();
                    }
                    repopx.remove(ma);
                }
                else cout << "Khong tim thay phieu!\n";
            }
        }catch(exception& e) { cout << "Loi:" << e.what() << endl;}
    }while(choice !=0);
}

