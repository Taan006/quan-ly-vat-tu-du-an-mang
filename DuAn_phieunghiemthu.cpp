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
            ngaybatdau=NhapNgay("Ngay bat dau :");
            ngayketthuc=NhapNgay("Ngay ket thuc :");
            cout << "Trang thai:"; getline(cin, trangthai);
        }

        void Capnhat() override {
            ten = NhapChucapnhat("Sua ten DA", ten);
            ngaybatdau = NhapChucapnhat("Sua ngay bat dau", ngaybatdau);
            ngayketthuc = NhapChucapnhat("Sua ngay ket thuc", ngayketthuc);
            trangthai = NhapChucapnhat("Sua trang thai", trangthai);

        
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


class phieunghiemthu : public Entity {
    private:
        string ten;
        string ngaylap;
        string maDA;
        string danhgia;
    public:
        void Nhap() override {
            cout << "MA Phieu Nghiem Thu:" ; getline(cin,ma);
            cout << "Ten Phieu Nghiem Thu:"; getline(cin,ten);
            ngaylap=NhapNgay("Ngay lap phieu :");
            cout << "Ma DA nghiem thu :"; getline(cin,maDA);
            cout << "Danh Gia DA:"; getline(cin,danhgia);
        }

        void Capnhat() override{
            ten = NhapChucapnhat("Sua ten phieu nghiem thu:", ten);
            ngaylap= NhapNgayCapnhat("Sua ngay lap phieu:", ngaylap);
            maDA = NhapChucapnhat("Sua ma DA nghiem thu:", maDA);
            danhgia = NhapChucapnhat("Sua danh gia:", danhgia);

        }
        
        void xuat() const override {
            cout << left << setw(10) << ma << "| " <<setw(20) << ten <<"| " <<
            setw(15) << ngaylap <<"| " 
            << setw(20) << maDA <<"| " << setw(20) << danhgia <<"| " << endl;
        }

        string toFile() const override{
            return ma + "|" + ten + "|" + ngaylap + "|" + maDA + "|" + danhgia;
        }

        void fromFile(const string& line) override{
            stringstream ss(line);
            getline(ss,ma,'|');
            getline(ss,ten,'|');
            getline(ss,ngaylap,'|');
            getline(ss,maDA,'|');
            getline(ss,danhgia,'|');
        }
        
        void xuatchitietDA(Repository<DuAn>& KhoDuAn) const {
            cout <<"Phieu nghiem thu:" << ten << "\n" <<"(MA:" << ma << ")\n" 
            << "(Ngay lap phieu:" << ngaylap << ")\n";

            shared_ptr<DuAn> da = KhoDuAn.findById(maDA);
            if(da != nullptr){
                cout << "---Phieu nghiem thu cho du an---\n";
                da->xuat();
            }
            else{
                cout << "Khong tim thay phieu nghiem thu cua du an co MA:" << maDA 
                << " trong he thong\n";
            }
        }
};

