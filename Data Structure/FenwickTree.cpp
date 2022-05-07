#include <bits/stdc++.h>
#define sz(v) int(v.size())

using namespace std;

using ll = long long;
using vll = vector<ll>;

int max_n;

vll v(max_n);
vll tree(max_n);
ll query (ll i) {
  ll ret = 0;
  for(; i; i -= i&-i) ret += tree[i];
  return ret;
};
void update(ll i,ll k) {
  for(; i<sz(tree); i += i&-i) tree[i] += k;
};
