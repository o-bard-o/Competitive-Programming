#include <bits/stdc++.h>
#define sz(v) int(v.size())

using namespace std;

using ll = long long;
using vll = vector<ll>;

void solve() {
  ll n;

  // Fenwick Tree
  vll v(n+1);
  vll tree(n+1);
  auto query = [&](ll i) {ll ret = 0; for(; i; i -= i&-i) ret += tree[i]; return ret;};
  auto update = [&](ll i,ll k) {for(; i<sz(tree); i += i&-i) tree[i] += k;};

}