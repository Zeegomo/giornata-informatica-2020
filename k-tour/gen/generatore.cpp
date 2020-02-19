#include <bits/stdc++.h>

using namespace std;
#define ll long long
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

int main(int argc, char** argv) {
	if(argc != 4) {
		return 1;
	}
	int n, w, seed, m;
	n = stoi(argv[1]);
	m = stoi(argv[2]);
	seed = stoi(argv[3]);
  
	random_boy randy(seed);

	if(seed == -1){
  		cout<<"8 9 4"<<endl
      		<<"7 2 5"<<endl
      		<<"8 4 3"<<endl
      		<<"6 5 2"<<endl
      		<<"6 4 10"<<endl
      		<<"1 4 1"<<endl
      		<<"1 5 3"<<endl
      		<<"2 3 4"<<endl
      		<<"2 4 6"<<endl
      		<<"4 5 4"<<endl;
  	} else{
      int limit = (int)min(400LL, (ll)n*(n-1)/2);
      set<pair<int, int>> s; 
	  	int k = randy.rand_in(1, limit);
   		cout << n << " " << m << " " << k << endl;
    		for(int i = 2; i <= n; i++){
     			int tmp = randy.rand_in(1, i-1);
          cout << i << " " << tmp;
          s.insert({i, tmp});
          s.insert({tmp, i});
        	cout << " " << randy.rand_in(1, 1e4);
      		cout<<" \n";

    		}
    		for (int i = 0; i < m-n +1; i++) {

      			int old = randy.rand_in(1, n);
            int next = randy.rand_in(1, n);
            while(s.count({old, next}) || old == next){
              old = randy.rand_in(1, n);
              next = randy.rand_in(1, n);
            }
            s.insert({old, next});
            s.insert({next, old});
            cout << old << " "<< next;
        		cout << " " << randy.rand_in(1, 1e4) <<"\n";
    		}
  	}
}
