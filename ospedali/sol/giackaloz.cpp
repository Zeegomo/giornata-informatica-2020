#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int l = 1e9, r = -1e9;
    while(n--){
        int a; cin >> a;
        l = min(l, a);
        r = max(r, a);
    }

    cout << r - l << endl;
}