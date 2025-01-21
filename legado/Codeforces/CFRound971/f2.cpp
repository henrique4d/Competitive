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

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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
const ll MAXN = 2e5+10;
ll a[MAXN];
ll ans[MAXN];
map<ll,ll> cont;
ll n,k,q;
pair<ll,ll> st[25][MAXN];

void build(){
    for (int i=0; i<n; i++){
        st[0][i].first = ans[i];
        st[0][i].second = ans[i];
    }
    for (int i=1; i<25; i++){
        for (int j=0; j+(1<<i) <= n; j++){
            st[i][j] = st[i-1][j] + st[i-1][j+(1<<(i-1))];
            cout << i << " --- " << j << " " << st[i][j] << " " << st[i-1][j] << " " << st[i-1][j+(1<<i)] << endl;
            
        }
    }
}
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

ll query(ll l, ll r){
    ll ans = 0;
    cout << "teste " <<  st[1][5] << " " << st[0][5] << " " << st[0][6] << endl;
    for (int i=25; i>=0; i--){
        cout << i << " " << l << " " << r << endl;
        if (r-l+1 >= (1<<i)){
            ans += st[i][l];
            l += (1<<i);
        }
    }
    return ans;
}

void init(){
    cont.clear();
    for (int i=0; i<n+10; i++){
        a[i] = 0;
        ans[i] = 0;
    }
}



void solve(){
    cin >> n >> k >> q;
    init();
    multiset<ll> m;

    for (int i=0; i<n; i++){
        cin >> a[i];
        a[i] -= i;
        if (cont[a[i]]){
            m.erase(m.find(cont[a[i]]));
        }
        cont[a[i]]++;
        m.insert(cont[a[i]]);

        if (i >= k-1){
            ans[i] = k - *m.rbegin();
            m.erase(m.find(cont[a[i-(k-1)]]));
            cont[a[i-(k-1)]]--;
            if (cont[a[i-(k-1)]]) m.insert(cont[a[i-(k-1)]]);
        }
    }
    build();
    for (int i=0; i<n; i++){
        cout << i << " " << ans[i] << endl;
    }

    while (q--){
        ll l,r;
        cin >> l >> r;
        l--,r--;
        cout << l+k-1 << " " << r << " " << query(l+k-1,r) << endl;    
        exit(0);
        // cout << ans[r-1] << endl;
    }
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