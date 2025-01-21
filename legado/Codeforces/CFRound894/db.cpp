#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;
 
const int maxn = 2e5 + 10, M = 1e9 + 7, inf = 1e18;
 
void solve() {
   int n; cin >> n;
   int l = 1, r = 2e9, ans = -1;
   while (l <= r) {
      int m = (l + r)/2;
      int q = m*(m-1)/2;
      if (q + m >= n) {
            ans = m;
            r = m - 1;
      } else {
            l = m + 1;
      }
   }
   int q = ans*(ans-1)/2;
//    cout << ans << '\n';
   int lucca = ans + (n - q);
   ans++;
   q = ans*(ans-1)/2;
   if (n >= q)
   lucca = min(lucca, ans + (n - q));
   cout << lucca << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}