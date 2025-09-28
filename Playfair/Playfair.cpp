#include <iostream>
#include <string>
using namespace std;

char table[5][5];

void createTable(string key) {
    bool used[26] = {0};
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int r = 0, c = 0;
    for (int i = 0; i < (int)key.size(); i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            table[r][c++] = ch;
            used[ch - 'A'] = 1;
            if (c == 5) { c = 0; r++; }
            if (r == 5) break;
        }
    }
}

pair<int,int> pos(char ch) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (table[i][j] == ch) return make_pair(i,j);
    return make_pair(-1,-1);
}

string process(string text, bool enc) {
    string res;
    for (int i = 0; i < (int)text.size(); i++) if (isalpha(text[i])) res += toupper(text[i]);
    for (int i = 0; i < (int)res.size(); i+=2) {
        if (i+1 == (int)res.size() || res[i] == res[i+1]) res.insert(i+1, "X");
    }
    string out;
    for (int i = 0; i < (int)res.size(); i+=2) {
        pair<int,int> a = pos(res[i]), b = pos(res[i+1]);
        if (a.first == b.first) {
            out += table[a.first][(a.second + (enc?1:4))%5];
            out += table[b.first][(b.second + (enc?1:4))%5];
        } else if (a.second == b.second) {
            out += table[(a.first + (enc?1:4))%5][a.second];
            out += table[(b.first + (enc?1:4))%5][b.second];
        } else {
            out += table[a.first][b.second];
            out += table[b.first][a.second];
        }
    }
    return out;
}

int main() {
    string key, text;
    cout << "Nhap khoa: ";
    getline(cin, key);
    createTable(key);

    cout << "Nhap chuoi: ";
    getline(cin, text);

    string c = process(text, true);
    cout << "Ban ma: " << c << endl;
    cout << "Ban goc: " << process(c, false) << endl;
    return 0;
}

