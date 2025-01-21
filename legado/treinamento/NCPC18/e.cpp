#include<bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
typedef long long ll;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628
#define MOD 1000000007

//------------------solution starts below------------------
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll f(ll n)
{
    ll ans = 1;
    for(ll i = 2 ; i <= n ; i++)
        ans = ( (ans%MOD) * (i%MOD))%MOD;
    return ans;
}

ll inv(ll a, ll p)
{
    return binpow(a, p-2, p);
}

ll comb(ll n, ll k)
{
    return (((f(n)*inv(f(k), MOD))%MOD)*inv(f(n-k), MOD))%MOD;
}

ll K, N;

ll cont(ll k)
{
    if(k == 1) return 0;
    return (( (( (comb(K, k)%MOD) * k)%MOD) * binpow(k-1, N-1, MOD)%MOD)%MOD + MOD - cont(k-1)%MOD)%MOD;
}


void solve(ll tt)
{
    cin >> N >> K;
    ll aux;
    for(ll i = 0 ; i < N-1 ; i++)
        cin >> aux;
    cout << cont(K) << endl;
}

int main()
{
    optimize;
    ll tt=1;
    //cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}