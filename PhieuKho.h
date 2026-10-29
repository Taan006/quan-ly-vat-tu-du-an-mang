#pragma once
#include<iostream>
#include"TienichVangoaile.h"
#include"EntityVaRepository.h"
#include<string>
#include<sstream>
#include<limits>
#include<iomanip>

using namespace std;

class PhieuKho : public Entity{
    protected :
        string ngaylap;
        string maDT;
        string maVT;    
        int soluong;
        double dongia;
    public:
        string getmaVT() const {return maVT;}
        double getsoluong() const {return soluong;}

        void nhapphieukho(string doitac){
          
            cout << "MA phieu: "; 
            getline(cin,ma);
            ngaylap=NhapNgay("Ngay lap phieu: ");
            cout << doitac << ": " ;getline(cin,maDT);
            cout <<"Ma VT: ";getline(cin,maVT);
            soluong = (int)NhapSo("So luong: ");
            dongia = (longlong)NhapSo("Don gia: ");

        }
        void capnhatphieukho(string doitac){
            ngaylap = NhapNgaycapnhat("Sua ngay lap:", ngaylap);
            maDT = NhapChucapnhat("Sua" + doitac + ":",maDT);
            dongia = (long long)NhapSocapnhat("Sua don gia:", dongia);
            cout << "[!] Luu y: Khong cho phep sua ma VT va Soluong VT.Hay xoa phieu nay neu nhap sai !\n";

        }
        string basetoFile() const {
            return ma + "|" + ngaylap + "|" + maDT + "|" + maVT +"|"
            + to_string(soluong) + "|" + to_string(dongia);
        }
        void basefromFile(const string& line){
            stringstream ss(line);
            string t;
            getline(ss,ma,'|');
            getline(ss,ngaylap,'|');    
            getline(ss,maDT,'|');
            getline(ss,maVT,'|');
            getline(ss,t,'|'); soluong=stoi(t);
            getline(ss,t,'|'); dongia=stoll(t);

        }
        void xuatphieukho() const{
            cout << fixed << setprecision(0) <<left << setw(10) << ma << "| " << setw(20) << ngaylap << "| " 
            << setw(20) << maDT << "| " << setw(20) << maVT << "| " << setw(20) 
            << soluong << "| " << setw(20) << dongia << endl;
        }

};

class phieunhap : public PhieuKho{
    public:
        void Nhap() override {nhapphieukho("Ma nha cung cap"); }
        void Capnhat() override{capnhatphieukho("Ma nha cung cap");}
        void xuat() const override{xuatphieukho();}
        string toFile() const override { return basetoFile();}
        void fromFile(const string& line) override {basefromFile(line);}
};

class phieuxuat : public PhieuKho{
    public:
        void Nhap() override {nhapphieukho("Ma du an");}
        void Capnhat() override {capnhatphieukho("Ma du an");}
        void xuat() const override {xuatphieukho();}
        string toFile() const override { return basetoFile();}
        void fromFile(const string& line) override { basefromFile(line);}
};
