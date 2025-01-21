 #include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define endl "\n"
 
#define fi first 
#define se second 
#define pb push_back
 
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 2e5+10;
ll a[MAXN];

void solve(){
    ll l,r;
    cin >> l >> r;
    vector<ll> aux(20);
    aux[4] = 2;
    aux[5] = 2;
    aux[6] = 2;
    aux[7] = 2;
    aux[8] = 1;
    ll resp = 0;
    for (int i=l; i<=8 and i <= r; i++){
        resp += aux[i];
    }

    l = max(l, (ll)9);
    ll changes[9] = {728, 50624, 5153632, 594823320, 78364164095, 11688200277600, 1953124999999999, 430804206899405535, 1000000000000000002};

    for (int i=0; i<9; i++){
        cout << i << " " << l << " " << r << " " << changes[i] << " " <<  resp << " " << r-l+1 << " " << changes[i]-l+1 << endl;
        if (r <= changes[i]){
            resp +=  (((r - l + 1)%mod) * (i+2))%mod;
            resp%=mod;
            break;
        }
        resp += ( ((changes[i] - l + 1)%mod) * (i+2))%mod;
        resp%=mod;
        l = changes[i] + 1;
    }

    cout << resp << endl;
}


int main() {
    optimize; 
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}