#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())

#ifdef DEBUG
#define debug(x) cerr << #x << ": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// helper functions for debugging (optional)
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// ... (add more as needed)

template <class T>
void _print(vector<T> v) {
  cerr << "[";
  for (int i = 0; i < v.size(); ++i) {
    _print(v[i]);
    if (i != v.size() - 1) cerr << ", ";
  }
  cerr << "]";
}

// ... (add more template specializations for other data structures)

random_device rd;
mt19937 rng(rd());

// Math utility functions
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

// ... (add more math functions as needed)

void solve() {
  // Your problem solving code goes here
  int t;
    cin >> t;
    while(t--) {
        
    }
}

int main() {
#ifdef DEBUG
  freopen("error.txt", "w", stderr);
#endif
  fastIO();
  auto start = high_resolution_clock::now();
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
#ifdef DEBUG
  cerr << "Time: " << duration.count() / 1000 << " milliseconds" << endl;
#endif
  return 0;
}
