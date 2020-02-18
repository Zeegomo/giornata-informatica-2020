#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
  assert(argc == 5);

  int n = stoi(argv[1]);
  int m = stoi(argv[2]);
  int maxv = stoi(argv[3]);
  ll seed = stoll(argv[4]);

  if(seed == -1) {
    cout << "2 5 0 2" << '\n';

    cout << "4 3 0 7 6\n";
    cout << "1 3 4 1 1\n";
    return 0;
  } else if(seed == -2) {
    cout << "3 5 0 2" << '\n';
    
    cout << "1 2 0 1 2\n";
    cout << "3 2 1 3 4\n";
    cout << "2 4 3 1 5\n";
    return 0;
  }

  assert(n >= 2 && m >= 1);
  assert(n <= 5e2 && m <= 5e2);
  assert(maxv <= 100);



  random_boy randy(seed);

  int r = randy.rand_in(0, n - 2);
  int c = randy.rand_in(0, m-1);

  cout << n << ' ' << m << ' ' << r << ' ' << c << '\n';
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i == r && j == c) cout << 0 << ' ';
      else cout << randy.rand_in(1, maxv) << ' ';
    }
    cout << '\n';
  }
}
