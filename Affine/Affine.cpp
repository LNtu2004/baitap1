#include <iostream>
#include <string>
using namespace std;

// Ham tinh ngh?ch ??o modular
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1; // khong t?n t?i ngh?ch ??o
}

// Ham ma hoa Affine Cipher
string encryptAffine(string s, int a, int b) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalpha(s[i])) {
            char base = isupper(s[i]) ? 'A' : 'a';
            s[i] = (char)((a * (s[i] - base) + b) % 26 + base);
        }
    }
    return s;
}

// Ham gi?i ma Affine Cipher
string decryptAffine(string s, int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        return "Khong ton tai nghich dao cua a voi modulo 26!";
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalpha(s[i])) {
            char base = isupper(s[i]) ? 'A' : 'a';
            int y = s[i] - base;
            int x = (a_inv * ((y - b + 26) % 26)) % 26;
            s[i] = (char)(x + base);
        }
    }
    return s;
}

int main() {
    string s;
    int a, b;
    int choice;

    cout << "=== MA HOA AFFINE ===" << endl;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    cout << "Nhap khoa a, b: ";
    cin >> a >> b;

    cout << "\n1. Ma hoa" << endl;
    cout << "2. Giai ma" << endl;
    cout << "Chon: ";
    cin >> choice;   // ??c luon s? l?a ch?n, khong con l?i nu?t Enter n?a

    if (choice == 1) {
        string c = encryptAffine(s, a, b);
        cout << "Ban ma: " << c << endl;
    } else if (choice == 2) {
        string p = decryptAffine(s, a, b);
        cout << "Ban goc: " << p << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}

