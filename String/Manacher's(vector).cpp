#include <bits/stdc++.h>
#define fab(i,a,b) for(int i=a;i<=b;++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
using namespace std;

int cir[300005];

void solve() {
  int n;
  cin >> n;
  vll h(n);
  cv(h);
  vll s;
  s.pb(-1); // should not be included in v
  reverse(all(h));
  while(sz(h)) {
    s.pb(h.back()), s.pb(-1), h.pop_back();
  }
  int n = sz(s);

  auto mana = [&](){
    int r = 0, p = 0;
    fab(i, 0, n-1){
      cir[i] = i <= r ? min(cir[2 * p - i], r - (int)i) : 0;

      while (i - cir[i] - 1 >= 0 && i + cir[i] + 1 < n && s[i - cir[i] - 1] == s[i + cir[i] + 1])
        ++cir[i];

      if (r < i + cir[i])
        r = i + cir[i], p = i;
    }
  };
  mana();
}
