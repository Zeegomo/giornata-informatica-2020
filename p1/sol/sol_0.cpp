#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int h, a, b;
	cin >> h >> a >> b;
	if (a == b){
		cout  << h/a + ((h%a) > 0) << " " << 0;
	} else {
		int nb = h / b;
		int na = 0;
		if(nb * b < h){
			if (nb * b + a >=  h){
				na++;
			}else{
				nb++;
			}
		}
		cout << na << " " << nb;
	}
}
