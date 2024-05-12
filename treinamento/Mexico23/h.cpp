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
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif
#define MAXN 212345
#define MAXC 26

int go[MAXN][MAXC];
int out[MAXN];
int nxt = 1;
int linkk[MAXN];
int exitlinkk[MAXN];

void init() {
    memset(go, -1, sizeof go);
    memset(out, -1, sizeof out);
    memset(exitlinkk, -1, sizeof exitlinkk);
    nxt = 1;
}

void add(string s, int i) {
    int cur = 0;
    for(char c : s) {
        if(go[cur][c - 'a'] == -1) go[cur][c - 'a'] = nxt++;
        cur = go[cur][c - 'a'];
    }
    out[cur] = i;
}

void ahoCorasick() {
    linkk[0] = 0;
    queue<int> q;
    for(int i=0; i<MAXC; ++i) {
        if(go[0][i] == -1) go[0][i] = 0;
        else linkk[go[0][i]] = 0, q.push(go[0][i]);
    }
    while(q.size()) {
        int v = q.front(); q.pop();
        int l = linkk[v];
        
        if(out[l] != -1) exitlinkk[v] = l;
        else exitlinkk[v] = exitlinkk[l];

        for(int i=0; i<MAXC; ++i) {
            if(go[v][i] == -1) go[v][i] = go[l][i];
            else linkk[go[v][i]] = go[l][i], q.push(go[v][i]);
        }
    }
}

ll dp[MAXN];
string a[MAXN];

void match(string t) {
    int cur = 0;
    for(int i=0; i<(int)t.size(); ++i) {
        char c = t[i];
        cur = go[cur][c - 'a'];
        for(int v = cur; v != -1; v = exitlinkk[v]) {
            if(out[v] != -1) {
                if (i - (int)a[out[v]].size() < 0){
                    dp[i]++;
                }
                else dp[i] += dp[i - (int)a[out[v]].size()];
                dp[i] %= mod;    
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    init();

    for (int i=0; i<n; i++){
        cin >> a[i];
        add(a[i], i);
    }
    ahoCorasick();
    
    string s;
    cin >> s;
    
    match(s);
    
    cout << dp[s.size()-1] << endl;
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