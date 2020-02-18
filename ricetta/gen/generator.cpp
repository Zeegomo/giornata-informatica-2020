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
random_boy randy;

string rand_test(){
	int n = randy.rand_in(10, 200);
	string s = "";
	for(int i = 0; i < n; i++){
		char nxt = randy.rand_in(0, 25)+'a';
		while(nxt == s.back()){
			nxt = randy.rand_in(0, 25)+'a';
		}
		s += nxt;
	}
	return s;
}
string good_test(){
	int n = randy.rand_in(10, 200);
	string t = "qwertyuioplkjhgfdsazxcvbnm";
	random_shuffle(t.begin(), t.end());
	string s = "";
	int pos = 0;
	for(int i = 0; i < n; i++){
		s += t[pos];
		if(pos == 0){
			pos++;
		}else if(pos == 25){
			pos--;
		}else{
			if(randy.rand_in(0, 1) < 1){
				pos++;
			}else{
				pos--;
			}
		}
	}
	return s;
}
signed main(int argc, char** argv) {
	if(argc != 3)
	 	return 1;

	int n, t, seed;
	t = stoi(argv[1]);
	seed = stoi(argv[2]);
	randy = random_boy(seed);
	if(t == -1){
		cout <<"5\nababa\ncodedoca\nabcda\nzxzytyz\nabcdefghijklmnopqrstuvwxyza\n";
		return 0;
	}else if(t == -2){
		cout <<"1\ne";
		return 0;
	}
	cout << t << "\n";
	for(int i = 0; i < t; i++){
		if(randy.rand_in(0, 1) > 0){
			cout << good_test() << "\n";
		} else{
			cout << rand_test() << "\n";
		}
	}

}
