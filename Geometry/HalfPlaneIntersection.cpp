#include <bits/stdc++.h>
#define fv(x,v) for(auto& x: v)
#define fn(i,n) for(int i=0;i<n;++i)
#define pb(x) push_back(x)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
using ld = long double;
using pld = pair<ld, ld>;

const ld eps = 1e-8;

ld ccw(pld a, pld b, pld c){
	ld dx1 = b.X - a.X, dy1 = b.Y - a.Y;
	ld dx2 = c.X - a.X, dy2 = c.Y - a.Y;
	return dx1 * dy2 - dy1 * dx2;
}

bool z(ld x) { return fabs(x) < eps; };
struct line {
  ld a, b, c;
  bool operator<(const line &l) const {
    bool flag1 = pld(a, b) > pld(0, 0);
    bool flag2 = pld(l.a, l.b) > pld(0, 0);
    if(flag1 != flag2) return flag1 > flag2;
    ld t = ccw(pld(0, 0), pld(a, b), pld(l.a, l.b));
    return z(t) ? c * hypot(l.a, l.b) < l.c * hypot(a, b) : t > 0;
  }
  pld slope() { return pld(a, b); }
};

pld cross(line& a, line& b) {
  ld det = a.a * b.b - b.a * a.b;
  return pld((a.c*b.b - a.b*b.c)/det, (a.a*b.c - a.c*b.a)/det);
}

bool bad(line& a, line& b, line& c) {
  if(ccw(pld(0,0), a.slope(), b.slope()) <= 0) return false;
  pld crs = cross(a, b);
  return crs.X*c.a + crs.Y*c.b >= c.c;
}

bool HPI(vector<line> v, vector<pld> &solution) { // ax + by <= c
  sort(all(v));
  deque<line> dq;
  fv(i, v) {
    if(!dq.empty() && z(ccw(pld(0,0), dq.back().slope(), i.slope()))) continue;
    while(sz(dq) >= 2 && bad(dq[sz(dq)-2], dq.back(), i)) dq.pop_back();
    while(sz(dq) >= 2 && bad(i, dq[0], dq[1])) dq.pop_front();
    dq.pb(i);
  }
  while(sz(dq)>2 && bad(dq[sz(dq)-2], dq.back(), dq[0])) dq.pop_back();
  while(sz(dq)>2 && bad(dq.back(), dq[0], dq[1])) dq.pop_front();
  vector<pld> tmp;
  fn(i,sz(dq)) {
    line cur = dq[i], nxt = dq[(i+1)%sz(dq)];
    if(ccw(pld(0, 0), cur.slope(), nxt.slope()) <= eps) return false;
    tmp.pb(cross(cur, nxt));
  } 
  solution = tmp;
  return true;
}