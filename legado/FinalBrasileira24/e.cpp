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
const ll MAXN = 1e5+10;
ll a[MAXN];
bool used[MAXN];
pair<ll,ll> proximo[MAXN];
pair<ll,ll> anterior[MAXN];
ll n;

void solve(){
    cin >> n;
    anterior[0] = {INFLL, INFLL};
    proximo[n+1] = {INFLL, INFLL};
    ll cresce = 0;
    ll decresce = n+1;

    for (int i=1; i<=n; i++){
        cin >> a[i];
        used[a[i]] = true;
        if (a[i]) anterior[i] = {a[i],0};
        else{
            anterior[i] = anterior[i-1];
            anterior[i].second++;
        }
    }
    for (int i=n; i>=1; i--){
        if (a[i]) proximo[i] = {a[i],0};
        else{
            proximo[i] = proximo[i+1];
            proximo[i].second++;
        }
    }
    for (int i = 2; i<=n; i++){
        if (a[i] > a[i-1]) cresce = i-1;
        else decresce = i-1;
    }
    if (cresce > decresce){
        cout << "*\n";
        return;
    }
    ll val = n;
    while (used[val]) val--;

    if (cresce != 0 and decresce != n+1){
        int i = cresce+1;
        while ()
    }
    ll l = 1;
    ll r = n;
    ll val = 1;
    while(used[val]) val++;
    while (a[l]) l++;
    while (a[r]) r--;

    while (l <= r){
        if (proximo[l] < anterior[r]){
            a[l] = val;
            used[val] = true;
        }
        else{
            a[r] = val;
            used[val] = true;
        }
        while(used[val]) val++;
        while (a[l]) l++;
        while (a[r]) r--;
    }
    // for (int i=1; i<=n; i++){
    //     cout << i << " " << proximo[i] << " " << anterior[i]<< endl;
    // }
    // cout << endl;    
    bool subindo = true;
    for (int i=2; i<=n; i++){
        if (a[i] < a[i-1]) subindo = false;
        if (!subindo and a[i] > a[i-1]){
            // cout << "*\n";
            // return;
        }
    }
    for (int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
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