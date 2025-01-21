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
 
#define mod 998244353LL
 
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
struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

const ll MAXN = 1e5+10;
pair<ll,ll> a[MAXN];
ll aux[MAXN];
ll n,m,k;

bool eval2(ll numGolpes, ll posicao, ll monster){
    return (numGolpes * (m - abs(posicao - a[monster].second)) >= a[monster].first);
}

bool eval(ll numGolpes){
    // Bit fenw(n+100);
    // cout << "para o eval de " << numGolpes << endl;
    vector<pair<ll,ll>> events;
    for (int i=0; i<n; i++){
        // cout << "monstro " << i << endl;
        if (numGolpes * m >= a[i].first){
            ll l = a[i].second;
            ll r = INF;
            while (r-l > 1){
                ll mid = l + (r-l)/2;
                if (eval2(numGolpes, mid, i)) l = mid;
                else r = mid;
            }
            // cout << "o valor do l e " << l << endl;
            events.push_back({l,true});
            ll final = upper_bound(aux, aux+n, l) - aux - 1;


            l = -1;
            r = a[i].second;
            while (r-l > 1){
                ll mid = l + (r-l)/2;
                if (eval2(numGolpes, mid, i)) r = mid;
                else l = mid;
            }
            // cout << "o valor do r e " << r << endl;
            ll comeco = lower_bound(aux, aux+n, r) - aux;
            events.push_back({r,false});
            // cout << i << " " << comeco << " " << final << endl;
            // fenw.update(comeco, 1);
            // fenw.update(final+1, -1);
        }
    }
    sort(all(events));
    // cout << "//////\n";

    ll val_atual = 0;
    ll cont = 0;
    
    
    for (int i=0; i<events.size(); i++){
        if (events[i].second) val_atual--;
        else val_atual++;
        // cout << i << " " << val_atual << endl;
    
        if (val_atual >= k) return true;
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        cin >> a[i].first;
    }
    for (int i=0; i<n; i++){
        cin >> a[i].second;
        aux[i] = a[i].second;
    }

    ll l = 0;
    ll r = INF;
    // cout << eval(15) << endl;
    // exit(0);
    while (r-l > 1){
        ll mid = l + (r-l)/2;
        if (eval(mid)) r = mid;
        else l = mid;
    }
    if (r == INF) cout << -1 << endl;
    else cout << r << endl;
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