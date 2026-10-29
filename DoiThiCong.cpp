#pragma once
#include<iostream>
#include<string>
#include<limits>
#include<sstream> 
#include<iomanip> 
#include"EntityVaRepository.h"
#include"TienichVangoaile.h"

class doithicong : public Entity {
        private :
            string ten;
            int soluong;
            string maDA;
        public:
            int getsoluong() const {return soluong;}
            void setsoluong(int sl2) {soluong=sl2; }

            void Nhap() override {
                string temp;
                cout << "MA Doi thi cong :" ; getline(cin,ma);
                cout << "Ten doi thi cong:";getline(cin,ten);
                soluong = (int)NhapSo("So luong nhan cong: ");
                cout << "MA DA dang thi cong:"; getline(cin,maDA);
            }

            void Capnhat() override{
                ten = NhapChucapnhat("Sua ten DTC :",ten);
                soluong = NhapSocapnhat("Sua SL nhan cong:", soluong);
                maDA = NhapChucapnhat("Sua MA DA thi cong:", maDA);
            }

            void xuat() const override {
                cout << left << setw(20) << ma <<"| " << setw(20) << ten <<"| " 
                << setw(20) << soluong <<"| " << setw(20) << maDA <<"|" << endl;
            }

            string toFile() const override{
                return ma + "|" + ten + "|" + to_string(soluong) + "|" + maDA + "|";
            } 

            void fromFile(const string&line ) override{
                stringstream ss(line); string t;
                getline(ss,ma,'|');
                getline(ss,ten,'|');
                getline(ss,t,'|'); soluong=stoi(t);
                getline(ss,maDA,'|');
            }

            void xuatchitietDA (Repository<DuAn>& KhoDuAn){
                cout << "Doi thi cong :" << ten << "(MA:" << ma << ")\n";  

                shared_ptr<DuAn> da= KhoDuAn.findById(maDA);

                if(da != nullptr){
                    cout << "---MA Du An dang phu trach---\n";
                    da->xuat();
                }
                else{
                    cout << "Khong tim thay du an co MA:" << maDA << " trong he thong"; 
                }
            }

};

