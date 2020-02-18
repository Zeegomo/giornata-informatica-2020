#include <bits/stdc++.h>

using namespace std;

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

	int n = stoi(argv[1]);

	if(n==-1){
		cout<<2<<endl<<5<<' '<<9<<endl;
		return 0;
	} else if(n==-2){
		cout<<1<<endl<<3<<endl;
		return 0;
	}

	assert(0<n&&n<1000000);
	random_boy randy = random_boy(stoi(argv[2]));
	cout<<n<<endl;
	while(--n){
		cout<<randy.rand_in(-999999999,999999999)<<' ';
	}
	cout<<randy.rand_in(-999999999,999999999)<<endl;
	return 0;
}
