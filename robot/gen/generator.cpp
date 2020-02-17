#include <bits/stdc++.h>

using namespace std;
#define int long long
struct random_boy{
	 mt19937 rng;
	 uniform_int_distribution<int> gen;
	 random_boy() : rng(chrono::steady_clock::now().time_since_epoch().count()){}
	 random_boy(int seed) : rng(seed){}

	 int rand32() { return gen(rng);}
  
	 // return value in [l, r]
	 int rand_in(int l, int r){
	 // to avoid breaking things
	 if(l > r) swap(l, r);
		return rand32() % (r - l + 1) + l;
	 }
};

signed main(int argc, char** argv) {
	if(argc != 3)
	 	return 1;

	int tc = stoi(argv[1]);
	random_boy randy = random_boy(stoi(argv[2]));
	int h, a, b;
	switch(tc){
		case -1:
			h = 4, a = 2, b = 4;
			break;
		case -2:
			h = 2, a = 2, b = 2;	
			break;
		case -3:
			h = 10, a = 4, b = 6;
			break;
		case 1:
			h = randy.rand_in(1, 1e6);
			a = b = randy.rand_in(1, 1e6);
			break;
		case 2:
			h = randy.rand_in(1, 1e6);
			b = randy.rand_in(1, 1e6);
			a = randy.rand_in(1, 1e6) % b + 1;
			break;
		case 3: 
			h = randy.rand_in(1, 1e18);
			b = randy.rand_in(1, 1e18);
			a = randy.rand_in(1, 1e18) % b + 1;
	       	break; 
	    case 4:
	    	h = 1000000000000000001;
	    	a = 1e9-1;
	    	b = 1e9;
	    	break;
	}	
	cout << h << " " << a << " " << b;
}
