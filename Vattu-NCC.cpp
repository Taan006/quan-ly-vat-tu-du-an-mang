#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include "TienichVangoaile.h"
#include "Entity&Repository.h"

using namespace std;

class Vattu : public Entity{
	private:
		string ten, donvi, maNCC;
		int soluong;
		double dongia;
	public:
		int getsoluong() const {return soluong;}
		void setsoluong(int sl1) {soluong = sl1;
		}
		void Nhap() override{
			string temp;
			cout << "MA VT:" ; getline(cin,ma);
            cout << "Ten VT:" ; getline(cin, ten);
            cout << "Don gia:"; getline(cin, temp); dongia = stod(temp);
            cout << "so luong:"; getline(cin, temp); soluong = stoi(temp);
            cout << "Don Vi:" ; getline(cin, donvi);
            cout << "MA NCC:" ; getline(cin, maNCC);
		}
		
		void Capnhat() override{
			ten = NhapChucapnhat("Sua ten VT", ten);
            dongia = NhapSocapnhat("Sua don gia", dongia);
            soluong = (int)NhapSocapnhat("Sua so luong", soluong);
            donvi = NhapChucapnhat("Sua don vi:", donvi);
            maNCC = NhapChucapnhat("Sua ma NCC:", maNCC);
		}
		
		void xuat() const override{
			cout << fixed << setprecision(0) << left << setw(10) << ma << "| "
			<< setw(20) << ten << "| "
			<< setw(20) << dongia << "| "
			<< setw(20) << soluong << "| "
			<< setw(20) << dongvi << "| " 
			<< setw(20) << ma NCC << "| " << endl;
		}
		
		string toFile() const override{
			return ma + "|" + ten + "|" + to_string((long long)dongia) + "|" + to_string(soluong) + "|" + donvi + "|" + maNCC;
		}
		
		void fromFile(const string& line) override{
			stringstream ss(line);
			string t;
			getline(ss, ma, '|');
            getline(ss, ten, '|');
            getline(ss, t, '|'); dongia=stod(t);
            getline(ss, t, '|'); soluong=stoi(t);
            getline(ss, donvi,'|');
            getline(ss, maNCC,'|');
		} 
		void xuatchitietNCC (Repository<Nhacungcap>& khoNCC){
                cout << "Vat tu :" << ten << "(MA:" << ma << ")\n";  
                shared_ptr<Nhacungcap> da= khoNCC.findById(maNCC);
                if(da != nullptr){
                    cout << "---Vat tu tu nha cung cap---\n";
                    da->xuat();
                }else{
                    cout << "Khong tim thay nha cung cap co ma:" << maNCC << " trong he thong"; 
                }
            }
};

class Nhacungcap : public Entity{
	private :
		string tenncc, diachi, vattucungcap;
	public :
		void Nhap() override{
			cout << "Ma NCC:"; getline(cin, ma);
			cout << "Dia chi NCC:"; getline(cin, diachi);
			cout << "Ten NCC:"; getline(cin, tenncc);
			cout << "Vat tu cung cap:"; getline(cin, vattucungcap);
		}
		
		void Capnhat() override{
			diachi = NhapChucapnhat("Sua ten NCC", tenncc);
			tenncc = NhapChucapnhat("Sua dia chi", diachi);
			vattucungcap = NhapChucapnhat("Sua vat tu cung cap", vattucungcap);
		}
		
		void xuat() const override {
			cout << left << setw(10) << ma << "| "
			<< setw(20) << diachi << "| "
			<< setw(20) << tenncc << "| "
			<< setw(20) << vattucungcap << "| " << endl;
		}
		
		string toFile() const override{
			return ma + "|" + diachi + "|" + tenncc + "|" + vattucungcap;
		}
		
		void fromFile(const string& line) override{
			stringstream ss(line);
			getline(ss, ma, '|');
			getline(ss, diachi, '|');
			getline(ss, tenncc, '|');
			getline(ss, vattucungcap, '|');
		} 
};
