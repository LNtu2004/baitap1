#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Nhap chuoi : ";
    getline(cin, s);

    int n;
    cout << "Nhap do dai khoa: ";
    cin >> n;

    int key[100];
    cout << "Nhap khoa : ";
    for (int i = 0; i < n; i++) cin >> key[i];

    string cipher = s;
    for (int i = 0; i < n && i < (int)s.size(); i++)
        cipher[i] = s[key[i]];

    string plain = s;
    for (int i = 0; i < n && i < (int)s.size(); i++)
        plain[key[i]] = cipher[i];

    cout << "Ban ma: " << cipher << endl;
    cout << "Ban goc: " << plain << endl;
    return 0;
}

