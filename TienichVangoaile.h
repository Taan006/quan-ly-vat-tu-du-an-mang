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

inline double NhapSo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            double val = stod(input);
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

inline double NhapSocapnhat(const string& prompt, double oldval) {
    string input;
    while (true) {
        cout << prompt << " (Cu: " << oldval << " - Nhan Enter de giu nguyen) ";
        getline(cin, input);
        if (input.empty()) {
            return oldval;
        }
        try {
            double newval = stod(input);
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
