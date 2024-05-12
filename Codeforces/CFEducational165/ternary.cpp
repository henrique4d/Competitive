#include<bits/stdc++.h>
using namespace std;

// SHORT NAMES
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// Cout for debug
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
//

// CONSTANTS
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628
#define MOD 1000000007

//------------------solution starts below------------------

ll n, d;

ll f(ll x)
{
    return x+ceil((long double)d/(x+1));
}

ll tsearch(ll l, ll r)
{
    ll m1, m2;

    while (abs(r-l) > 3)
    {
        m1 = l+(r-l)/3;
        m2 = r-(r-l)/3;
        // cout << m1 << " " << m2 << " " << l << " " << r << " ";
        // cout << f(m1) << " " << f(m2) << endl;
        if(f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }

    ll ans = f(l);
    for(int i = l+1 ; i <= r ; i++)
        ans = min(ans, f(i));

    return ans;
}

void solve(ll tt)
{
    cin >> n >> d;
    if(d<=n)
    {
        yes();
        return;
    } 

    ll ans = tsearch(0, n);
    
    // for (int i=0; i<200; i++){
    //     cout << i << " " << f(i) << endl;
    // }
    // cout << ans << endl;

    if(ans <= n)
        yes();
    else
        no();
}

int main()
{
    optimize;
    ll tt=1;
    cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}