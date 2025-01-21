#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 3e5+10;
ll a[MAXN];
ll prefix[MAXN];
ll prefix2[MAXN];
ll prefix3[MAXN];
ll n;


bool eval(ll x, ll pos){
    ll limite = ((n + (n - x))*(x+1)) / 2;
    // cout << limite << endl;
    return pos <= limite;
}

void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        prefix[i] = prefix[i-1]+a[i];
        prefix2[i] = prefix[i] + prefix2[i-1];
    }
    ll acumulado = 0;
    for (int i=1; i<=n; i++){
        prefix3[i] = (prefix2[n] - prefix2[i-1] - prefix[i-1]*(n-i+1)) + prefix3[i-1];
    }
    for (int i=0; i<=n; i++){
        cout << i << " " << prefix3[i] << endl;
    }
    // cout << eval(1,5) << endl;
    // exit(0);
    ll q;
    cin >> q;
    while (q--){
        ll l = -1;
        ll r = n;
        ll pos1, pos2;
        cin >> pos1 >> pos2;
        while (r-l > 1){
            ll m = l + (r-l)/2;
            if (eval(m, pos1)) r = m;
            else l = m;
        }
        ll bucket1 = r;

        l = -1;
        r = n;
        while (r-l > 1){
            ll m = l + (r-l)/2;
            if (eval(m, pos2)) r = m;
            else l = m;
        }
        ll bucket2 = r;


        ll start1 = pos1 - ((n + (n - (bucket1 - 1)))*((bucket1 - 1)+1)) / 2;

        

        ll start2 = pos2 - ((n + (n - (bucket2 - 1)))*((bucket2 - 1)+1)) / 2;
        // cout << pos1 << " " << pos2 << " " <<  bucket1 << " " << bucket2 << " " << start1 << " " << start2 << endl;
        ll ans = 0;
        if (bucket1 == bucket2){
            ans = prefix2[start2] - prefix2[start1-1];
        }
        else{
            if (bucket2 - bucket1 > 1){
                // cout << bucket2 << " " << bucket1 << endl;
                // ans = prefix3[bucket2] - prefix3[bucket1+1];
                // cout << ans << endl;
            }
            ans += prefix2[n] - prefix2[bucket1 + start1];

            ans += prefix2[bucket2+ start2] - prefix2[bucket2];
        }
        
        cout << ans << endl;
    }
    // cout << ans << endl;

    
}


int main() {
    optimize; 
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}