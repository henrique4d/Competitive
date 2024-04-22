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
#define MOD 998244353LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

const ll MAXN = 200;
ll val[MAXN];
char ranks[MAXN];
ll cont[50];
ll contsuits[270];
ll n;

void solve(){
    cin >> n;
    cont[0] = 1;
    ll resp2 = 0;
    for (ll i=0; i<n; i++){
        cin >> ranks[i];
        if (ranks[i] == 'A') val[i] = 1;
        else if (ranks[i] == 'T' or ranks[i] == 'J' or ranks[i] == 'Q' or ranks[i] == 'K') val[i] = 10;
        else val[i] = ranks[i]-'0';
        for (ll j=15; j>=0; j--){
            cont[j+val[i]] += cont[j];
        }
        if (ranks[i] == 'T') ranks[i] = 10;
        else if (ranks[i] == 'J') ranks[i] = 11;
        else if (ranks[i] == 'Q') ranks[i] = 12;
        else if (ranks[i] == 'K') ranks[i] = 13;
        else if (ranks[i] == 'A') ranks[i] = 1;
        else ranks[i] = ranks[i] - '0';

        resp2 += contsuits[ranks[i]];
        contsuits[ranks[i]]++;
    }
    resp2*=2;

    ll resp1 = cont[15]*2;

    vector<ll> breaks;
    breaks.push_back(0);
    for (ll i=1; i<=13; i++){
        if (!contsuits[i]) breaks.push_back(i);
    }
    breaks.push_back(14);
    ll resp3 = 0;

    for (ll i=0; i<breaks.size()-1; i++){
        ll start = breaks[i]+1;
        ll end = breaks[i+1]-1;
        ll val = 1;
        while (start <= end){
            val *= contsuits[start];
            start++;
        }
        if (breaks[i+1]- breaks[i] - 1 >= 3){
            resp3 += val*(breaks[i+1]- breaks[i] - 1);
        }
    }
    cout << resp1 + resp2 + resp3 << endl;
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