#pragma once
#include <iostream>
#include <string>
#include <exception>


using namespace std;

class ValidationException : public exception {
    private:
        string message;
    public:
        ValidationException (const string& msg) : message(msg){}
        const char* what() const throw() {
            return message.c_str();
    }
};

inline string NhapChucapnhat(const string& prompt , const string& oldval){
    cout << prompt << "(Cu: " << oldval << "Nhan Enter de giu nguyen)";
    string input;
    getline(cin,input);
     return input.empty() ? oldval : input;

}

inline  long long NhapSo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            long long val = stoll(input);
            if (val <= 0) {
                throw ValidationException("Gia tri khong the la so am!");
            }
            return val;
        } catch (const ValidationException& e) {
            cout << "[Loi] " << e.what() << " Vui long nhap lai!\n";
        } catch (const invalid_argument& e) {
            cout << "[Loi] Ban phai nhap so, khong duoc nhap chu. Vui long nhap lai!\n";
        } catch (const out_of_range& e) {
            cout << "[Loi] So qua lon. Vui long nhap lai!\n";
        }
    }
}

inline long long NhapSocapnhat(const string& prompt, double oldval) {
    string input;
    while (true) {
        cout << prompt << " (Cu: " << oldval << " - Nhan Enter de giu nguyen) ";
        getline(cin, input);
        if (input.empty()) {
            return oldval;
        }
        try {
            long long newval = stod(input);
            if (newval <= 0) {
                throw ValidationException("Gia tri khong the la so am!");
            }
            return newval;
        } catch (const ValidationException& e) {
            cout << "[Loi] " << e.what() << " Vui long nhap lai!\n";
        } catch (const invalid_argument& e) {
            cout << "[Loi] Ban phai nhap so, khong duoc nhap chu. Vui long nhap lai!\n";
        } catch (const out_of_range& e) {
            cout << "[Loi] So qua lon. Vui long nhap lai!\n";
        }
    }
}


inline int NhapSoMenu() {
    int luaChon;
    cin >> luaChon;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Loi: Ban vua nhap chu. Vui long chi nhap so!\n";
        return -1;  
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return luaChon;
}

inline bool laNamNhuan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

inline void kiemTraNgayHopLe(const string& dateStr) {

    if (dateStr.length() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
        throw ValidationException("Dinh dang ngay phai la DD/MM/YYYY (Vi du: 19/10/2026)!");
    }

    int d, m, y;
    char c1, c2;
    stringstream ss(dateStr);

    if (!(ss >> d >> c1 >> m >> c2 >> y) || c1 != '/' || c2 != '/') {
        throw ValidationException("Ngay thang nam phai la cac con so!");
    }

    if (m < 1 || m > 12) {
        throw ValidationException("Thang phai nam trong khoang tu 1 den 12!");
    }


    int maxDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && laNamNhuan(y)) maxDays[2] = 29;

    if (d < 1 || d > maxDays[m]) {
        throw ValidationException("Thang " + to_string(m) + " nam " + to_string(y) + 
                                  " chi co " + to_string(maxDays[m]) + " ngay!");
    }
}

inline string NhapNgay(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            kiemTraNgayHopLe(input);
            return input; // Nhập đúng thì trả về
        } catch (const ValidationException& e) {
            cout << "[Loi Ngay Thang] " << e.what() << " Vui long nhap lai!\n";
        }
    }
}

inline string NhapNgayCapNhat(const string& prompt, const string& oldval) {
    string input;
    while (true) {
        cout << prompt << " (Cu: " << oldval << " - Nhan Enter de giu nguyen): ";
        getline(cin, input);
        if (input.empty()) return oldval;
        try {
            kiemTraNgayHopLe(input);
            return input;
        } catch (const ValidationException& e) {
            cout << "[Loi Ngay Thang] " << e.what() << " Vui long nhap lai!\n";
        }
    }
}


