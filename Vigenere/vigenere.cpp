#include <iostream>
#include <string>
using namespace std;

string clean(string s) {
    string r;
    for (int i = 0; i < (int)s.size(); i++)
        if (isalpha(s[i])) r += toupper(s[i]);
    return r;
}

string encrypt(string s, string key) {
    s = clean(s); key = clean(key);
    for (int i = 0; i < (int)s.size(); i++) {
        int p = s[i] - 'A';
        int k = key[i % key.size()] - 'A';
        s[i] = (p + k) % 26 + 'A';
    }
    return s;
}

string decrypt(string s, string key) {
    s = clean(s); key = clean(key);
    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] - 'A';
        int k = key[i % key.size()] - 'A';
        s[i] = (c - k + 26) % 26 + 'A';
    }
    return s;
}

int main() {
    string s, k;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "Nhap khoa: ";
    getline(cin, k);

    string c = encrypt(s, k);
    cout << "Ban ma: " << c << endl;
    cout << "Ban goc: " << decrypt(c, k) << endl;
    return 0;
}

