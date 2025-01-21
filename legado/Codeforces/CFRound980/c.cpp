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

template<typename T> ll inv_count(vector<T> l, vector<T> r = {}) {
	if (!r.size()) {
		r = l;
		sort(r.begin(), r.end());
	}
	int n = l.size();
	vector<int> v(n), bit(n);
	vector<pair<T, int>> w;
	for (int i = 0; i < n; i++) w.push_back({r[i], i+1});
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(w.begin(), w.end(), make_pair(l[i], 0));
		if (it == w.end() or it->first != l[i]) return -1; // nao da
		v[i] = it->second;
		it->second = -1;
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		for (int j = v[i]-1; j; j -= j&-j) ans += bit[j];
		for (int j = v[i]; j < n; j += j&-j) bit[j]++;
	}
	return ans;
}

const ll MAXN = 2e5+10;
pair<ll,ll> a[MAXN];

map<ll,ll> contMenores;
map<ll,ll> contApp;

bool compare(pair<ll,ll> a, pair<ll,ll> b){
    return contMenores[a.first] + contMenores[a.second] < contMenores[b.first] + contMenores[b.second];
}

void init(){
    contMenores.clear();
    contApp.clear();
}
void solve(){
    ll n;
    cin >> n;
    init();
    for (ll i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
        // contMenores[a[i].first]++;
        contApp[a[i].first]++;
        // contMenores[a[i].second]++;
        contApp[a[i].second]++;
    }
    for (auto it = contApp.begin(); it!=contApp.end(); it++){
        contMenores[it->first] = 0;
        if (it == contApp.begin()) continue;
        auto itPrev = it;
        itPrev--;
        it->second += itPrev->second;
        contMenores[it->first] = itPrev->second;
    }

    sort(a, a+n, compare);
    for (int i=0; i<n; i++){
        cout << a[i].first << " " << a[i].second << " ";
    }
    cout << endl;
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