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

string pad(int n, int digits) {
  if (n < 0) {
    return "-" + pad(-n, digits-1);
  }
  string x = to_string(n);
  while(x.length() < digits) x = "0" + x;
  return x;
}

int main(int argc, char** argv) {
  if(argc != 3) {
    return 1;
  }

  ll SEED = stoll(argv[1]);
  ll S = stoll(argv[2]); // bool: 1 = show seconds

  random_boy randy(SEED);

  vector<string> month {
    "gennaio",
    "febbraio",
    "marzo",
    "aprile",
    "maggio",
    "giugno",
    "luglio",
    "agosto",
    "settembre",
    "ottobre",
    "novembre",
    "dicembre"
  };

  ll N = S ? 1500000 : 300000;
  cout<<N<<'\n';
  for(int i = 0; i < N; i++) {
    cout
      <<pad(randy.rand_in(0, 23), 2)
      <<':'
      <<pad(randy.rand_in(0, 60), 2);
      if (S) {
        cout<<':'<<pad(randy.rand_in(0, 60), 2);
      }
      cout
        <<' '<<month[randy.rand_in(0, 11)]
        <<' '<<pad(randy.rand_in(-1000, 2000), 4)
        <<'\n';
  }
}
