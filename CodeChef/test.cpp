#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n = 100;
    cin >> n;
    vector <int> arr;
    for (int i = 2; i <= n; i++) {
      bool prime = true;
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          prime = false;
        }
      }
      if (prime) {
        arr.push_back(i);
      }
    }
    ll l = 1, r = 1;
    multiset <ll> z;
    for (int x : arr) z.insert(x);
    ll lim = 2e18;
    while (z.size() > 2) {
      ll a = *z.begin();
      z.erase(z.begin());
      auto it = z.upper_bound(lim / a);
      it--;
      ll b = *it;
      z.erase(it);
      z.insert(a * b);
    }
    while (z.size() < 2) z.insert(1);
    vector <vector <int> > g(n);
    vector <int> d(n, -1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    d[0] = 0;
    vector <int> q = {0};
    for (int i = 0; i < (int) q.size(); i++) {
      int v = q[i];
      for (int j : g[v]) {
        if (d[j] == -1) {
          d[j] = d[v] + 1;
          q.push_back(j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (d[i] % 2 == 0) cout << *z.begin() << ' ';
      else cout << *z.rbegin() << ' ';
    }
    cout << '\n';
  }
}