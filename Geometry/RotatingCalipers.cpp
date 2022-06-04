#include <bits/stdc++.h>
#define fn(i,n) for(int i=0;i<n;++i)
#define sz(v) int(v.size())
#define X first
#define Y second
using namespace std;
using ld = long double;
using pld = pair<ld, ld>;

ld dist(pld a, pld b) {
  return hypotl((a.X-b.X), (a.Y-b.Y));
}

ld rotatingCalipers(vector<pld>& h) { // convex hull
  int n = sz(h);
  int pl = 0, pr = 0;
  fn(i,n) {
    if(h[pl].X > h[i].X) pl = i;
    if(h[pr].X < h[i].X) pr = i;
  }
  ld ret = dist(h[pl], h[pr]);
  //cout << h[pl].X << ' ' << h[pr].X << ' ' << ret << '\n';

  fn(i,n*2) {
    if(ccw(pld(0,0), 
    pld(h[(pl+1)%n].X-h[pl].X, h[(pl+1)%n].Y-h[pl].Y),
    pld(h[pr].X-h[(pr+1)%n].X, h[pr].Y-h[(pr+1)%n].Y)) >= 0) {
      pl = (pl+1)%n;
    } else {
      pr = (pr+1)%n;
    }
    ret = max(ret, dist(h[pl], h[pr]));
  }
  return ret;
}