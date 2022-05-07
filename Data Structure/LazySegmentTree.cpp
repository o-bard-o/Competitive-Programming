#include <bits/stdc++.h>
#define sz(v) int(v.size())

using namespace std;

using ll = long long;
using vll = vector<ll>;

// Segment Tree with Lazy Propagation
const int max_n = 100001;
vll v(max_n << 2);
vll lazy(max_n << 2);
void p(int i,int nl,int nr) {
  if(lazy[i]) {
    if(nl != nr) {
      lazy[i << 1] += lazy[i];
      lazy[i << 1 | 1] += lazy[i];
    }
    v[i] += lazy[i];
    lazy[i] = 0;
  }
}
void update(int l, int r, ll k, int i, int nl, int nr) {
  p(i,nl,nr);
  if(nr<l || nl>r) return;
  if(l<=nl && nr<=r) {
    lazy[i] += k;
    p(i,nl,nr);
    return;
  }
  int mid = nl + nr >> 1;
  update(l,r,k,i<<1,nl,mid);
  update(l,r,k,i<<1|1,mid+1,nr);
  v[i] = min(v[i<<1], v[i<<1|1]);
}
ll query(int l, int r, int i, int nl, int nr) {
  p(i,nl,nr);
  if(nr<l||nl>r) return 1e9;
  if(l<=nl && nr<=r) return v[i];
  int mid = nl + nr >> 1;
  return min(query(l,r,i<<1,nl,mid), query(l,r,i<<1|1,mid+1,nr));
}