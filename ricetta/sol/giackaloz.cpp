#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    while(n--) {
        string s; cin >> s;

        vector<char> nastro(1000, '-');
        set<char> used;
        nastro[0] = s[0];
        used.insert(s[0]);

        int pos = 0;
        bool ok = true;
        for(int i = 1; i < s.size(); i++) {
            char next = s[i];
            
            if (used.find(next) == used.end()) {
                if (nastro[pos + 1] == '-') {
                    nastro[pos + 1] = next;
                    pos++;
                } else if (pos > 0 && nastro[pos - 1] == '-') {
                    nastro[pos - 1] = next;
                    pos--;
                } else {
                    cout << "NO\n";
                    ok = false;
                    break;
                }

                used.insert(next);
            } else {
                if (nastro[pos + 1] == next) {
                    pos++;
                } else if (pos > 0 && nastro[pos - 1] == next) {
                    pos--;
                } else {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            cout << "YES\n";
        }
    }
}