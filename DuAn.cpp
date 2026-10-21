#pragma once
#include<iostream>
#include<string>
#include<limits>
#include<sstream> 
#include<iomanip> 
#include"EntityVaRepository.h"
#include"TienichVangoaile.h"
class DuAn : public Entity {

    private :
        string ten;
        string ngaybatdau;
        string ngayketthuc;
        string trangthai;
    public :
        void Nhap() override {
            cout << "MA DA :" ; getline(cin,ma);
            cout << "Ten DA:" ; getline(cin,ten);
            cout << "Ngay bat dau:" ; getline(cin,ngaybatdau);
            cout << "Ngay ket thuc:" ; getline(cin,ngayketthuc);
            cout << "Trang thai:"; getline(cin,trangthai);
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten DA",ten);
            ngaybatdau = NhapChucapnhat("Sua ngay bat dau",ngaybatdau);
            ngayketthuc = NhapChucapnhat("Sua ngay ket thuc",ngayketthuc);
            trangthai = NhapChucapnhat("Sua trang thai",trangthai);

        
        }

        void xuat() const override {
            cout << left << setw(10) << ma <<"| " << setw(25) << ten <<"| " 
            << setw(25) << ngaybatdau <<"| " << setw(25) << ngayketthuc <<"| " << setw(25) 
            << trangthai <<"| " << endl;

        }

        string toFile() const override {
            return ma + "|" + ten + "|" + ngaybatdau + "|" + ngayketthuc + "|" + trangthai;
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            getline(ss, ma, '|');
            getline(ss, ten,'|');
            getline(ss, ngaybatdau, '|');
            getline(ss, ngayketthuc,'|');
            getline(ss, trangthai,'|');    
        }
}; 
