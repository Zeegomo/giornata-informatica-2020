#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int h, a, b;
	cin >> h >> a >> b;
	int nb = h / b + ((h % b) > 0);
	int tot = nb * b;
	int na = 0;
	int diff = b - a;
	if(diff == 0){
		swap(na, nb);
	} else if((tot - diff >= h) && (nb > 0)){
		int o = min((tot-h)/diff, nb);
		na += o;
		nb -= o;
	}
	cout << na << " " << nb;
}
