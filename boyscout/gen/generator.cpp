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
	if(argc != 4)
	 	return 1;

	int n, m, seed;
	n = stoi(argv[1]);
	m = stoi(argv[2]);
	seed = stoi(argv[3]);
	random_boy randy = random_boy(seed);

    // test cases
	if(n == -1){
		cout << "5 4\n0 1\n 0 2\n 1 3\n 4 5\n";
		return 0;
	}

	if(n == -2){
		cout << "4 3\n1 2\n2 3\n3 4\n";
		return 0;
    }

    // chain
    if(m == -1) {
        cout << n << ' ' << n << "\n";
        for(int i = 0; i < n; i++) {
            cout << i << ' ' << i+1 << '\n';
        }
        return 0;
    }

    // complete graph
    if (m == -2) {
        cout << n << ' ' << ((n * (n+1)) / 2) << '\n';
        for(int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << i << ' ' << j << '\n';
            }
        }
        return 0;
    }

    cout << n << ' ' << m << '\n';

    set<pair<int,int>> s;

    // zeeg is alone :(
    if(seed == -1) {
        for(int i = 0; i < m; i++) {
            bool ok = false;
            while(!ok) {
                int u = randy.rand_in(0, n);
                int v = randy.rand_in(0, n);

                if (u > v) swap(u, v);

                if (u != 0 && u != v && s.find({u, v}) == s.end()) {
                    ok = true;
                    cout << u << ' ' << v << '\n';
                    s.insert({u, v});
                }
            }
        }

        return 0;
    }

    // attach zeeg to someone
    int zeegFriends = randy.rand_in(0, ceil(m / (double)n) * 5);

    for(int i = 0; i < m && i < zeegFriends && i < n; i++) {
        bool ok = false;
        while(!ok) {
            int u = randy.rand_in(1, n);
            if (s.find({0, u}) == s.end()) {
                ok = true;
                cout << 0 << ' ' << u << '\n';
                s.insert({0, u});
            }
        }
    }

    m = m - zeegFriends;

    for(int i = 0; i < m; i++) {
        bool ok = false;
        while(!ok) {
            int u = randy.rand_in(0, n);
            int v = randy.rand_in(0, n);

            if (u > v) swap(u, v);

            if (u != v && s.find({u, v}) == s.end()) {
                ok = true;
                cout << u << ' ' << v << '\n';
                s.insert({u, v});
            }
        }
    }

    return 0;
}
