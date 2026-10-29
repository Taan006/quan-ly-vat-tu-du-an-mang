#pragma once
#include <iostream>
#include<string>
#include<sstream>
#include<limits>
#include<iomanip>
#include"TienichVangoaile.h"
#include"EntityVaRepository.h"
#include"caclop.h"

using namespace std;

class hoadonnhap : public Entity{
    protected:
        string ten;
        string mancc;
        string ngaylap;
        int soluong;
        long long dongia;
    public:
        int getsoluong() const {return soluong;}
        long long getdongia() const {return dongia;}


        void Nhap() override {
            string temp;
            cout << "MA hoa don:" ;
            getline(cin,ma);
            cout <<"Ten hoa don:"; getline(cin,ten);
            ngaylap = NhapNgay("Nhap ngay lap phieu:");
            cout << "Ma NCC:"; getline(cin,mancc);
            soluong =(int)Nhapso("so luong: ");
            dongia = (long long)Nhapso("don gia: ");
            
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten hoa don:", ten);
            ngaylap= NhapNgayCapNhat("Sua ngay lap:", ngaylap);
            mancc = NhapChucapnhat("Sua Ma NCC:", mancc);
            soluong= NhapSocapnhat("Sua tong tien:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }
        
        string toFile() const override  {
            return ma + "|" + ten + "|" + ngaylap +"|" + mancc + "|" + to_string((long long)soluong) +"|" + to_string(dongia); 
        }

        void fromFile(const string& line) override {
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,mancc,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stoll(t);
        }
        
        void xuat() const override  {
            cout << fixed << setprecision(0) << left << setw(10) << ma << "| " << setw(20) 
            << ten <<"| " << setw(20) << ngaylap << "| "
            << setw(20) << soluong << "| " << setw(20)
            <<dongia << "| " << setw(20) << getsoluong()*getdongia() << endl;
        }

        void xuatchitiet(Repository<Nhacungcap>& khoncc ){
            cout << "Hoa Don:" << ten << "\n" << "(MA:" << ma << ")\n";


            shared_ptr<Nhacungcap> da = khoncc.findById(mancc);

            if(da != nullptr){
                cout << "---hoa don nhap tu nha cung cap ---\n";
                da-> xuat();
            }
            else{
                cout <<"khong tim thay hoa don nhap tu nha cung cap vat tu co ma:" << mancc << "trong he thong\n";
            }
        }

};



class hoadonxuat : public Entity{
    private:
        string ten;
        string mavt;
        string ngaylap;
        int soluong;
        double dongia;
    public:
        double getsoluong() const {return soluong;}
        double getdongia() const {return dongia;}

        void Nhap() override{
            string temp;
            cout << "MA hoa don:";getline(cin,ma);
            cout << "Ten hoa don:"; getline(cin,ten);
            cout << "Ngay lap:"; getline(cin,ngaylap);
            cout << "Ma VT:"; getline(cin,mavt);
            dongia = (long long)NhapSo("Don gia: ");
            soluong = (int)NhapSo("So luong: ");
        }

        void Capnhat() override{
            ten = NhapChucapnhat("Sua ten hoa don:", ten);
            ngaylap = NhapChucapnhat("Sua ngay lap:", ngaylap);
            mavt = NhapChucapnhat("Sua ma vt:", mavt);
            soluong = NhapSocapnhat("Sua so luong:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }

        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + mavt + "|"
            + to_string(soluong) + "|" + to_string((long long)dongia);
        }

        void fromFile(const string& line) override {
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss, ten ,'|');
            getline(ss,ngaylap,'|');
            getline(ss,mavt,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);
        }
        
        void xuat() const override {
            cout << fixed  <<  setprecision(0) << left << setw(10) << ma << "| " << setw(20) << ten << "| "
            << setw(20) << ngaylap << "| " << setw(20) << soluong
            << "| " << setw(20) << dongia << "| " << getsoluong()*getdongia() << endl;
        }

        void xuatchitiet(Repository<Vattu>& KhoVT){
            cout << "hoa don xuat:" << ten << "(Ma:" << ma << ")\n";

            shared_ptr<Vattu> da = KhoVT.findById(mavt);

            if(da != nullptr){
                cout << "---hoa don xuat vat tu---\n";
                da->xuat();
            }
            else{
                cout << "Khong tim thay hoa don xuat vat tu co ma:" << mavt << " trong he thong\n";
            }
        }
};

class hoadonnhancong : public Entity{
    private:
        string ten;
        string ngaylap;
        string madtc;
        int soluong;
        double dongia;
    public:

        double getsoluong() const{return soluong;}
        double getdongia() const {return dongia;} 

        void Nhap() override {
            string temp;    
            cout << "Ma hoa don:";  getline(cin,ma);
            cout << "Ten hoa don:"; getline(cin,ten);
            cout << "Ngay lap:";    getline(cin,ngaylap);
            cout << "Ma DTC:" ;     getline(cin,madtc);
            soluong = (int)NhapSo("So luong: ");
            dongia = (long long)NhapSo("Don gia: ");
        }
        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten:", ten);
            ngaylap = NhapChucapnhat("Sua ngay lap:", ngaylap);
            madtc = NhapChucapnhat("Sua Ma DTC:", madtc);
            soluong = NhapSocapnhat("Sua so luong:", soluong);
            dongia = NhapSocapnhat("Sua don gia:", dongia);
        }
    
        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + madtc + "|" + to_string((long long)soluong) + "|" + to_string(dongia);
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,madtc,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stod(t);
        }

        void xuat() const override {
            cout << fixed << setprecision(0) <<left << setw(10) << ma <<"| " << setw(20) << ten << "| "
            << setw(20) << ngaylap << "| " << setw(20) << soluong << "| "
            << setw(20) << dongia << "| " << getsoluong()*getdongia() << endl; 
        }

        void xuatchitiet(Repository<doithicong>& khothicong){
            cout << "Ten hoa don:" << ten << "(Ma:" << ma << ")\n";

            shared_ptr<doithicong> da =khothicong.findById(madtc);

            if(da !=nullptr){
                cout << "---hoa don nhan cong cua doi thi cong---\n";
                da->xuat();
            }
            else{
                cout << " khong tim thay hoa don nhan cong cua doi thi cong co ma:" << madtc << " trong he thong\n";
            }
        }
};

