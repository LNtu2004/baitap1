#include <iostream>
#include <string>
using namespace std;

string encrypt(string s, int k) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalpha(s[i])) {
            char base = isupper(s[i]) ? 'A' : 'a';
            s[i] = (s[i] - base + k) % 26 + base;
        }
    }
    return s;
}

string decrypt(string s, int k) {
    return encrypt(s, 26 - k);
}

int main() {
    string s;
    int k;
    cout << "Nhap chuoi: ";
    getline(cin, s);
    cout << "Nhap khoa k: ";
    cin >> k;

    string c = encrypt(s, k);
    cout << "Ban ma: " << c << endl;
    cout << "Ban goc: " << decrypt(c, k) << endl;
    return 0;
}

