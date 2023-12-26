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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
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
const ll MAXN = 2e5 + 10;

ll l[MAXN];
ll r[MAXN];
ll c[MAXN];

struct event{
    bool op = false;
    int pos = 0;
    int index = 0;
};


bool compare(event &a, event &b){
    return a.pos < b.pos;
}

bool compare2(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second-a.first < b.second-b.first;
}

void solve(){
    int n;
    cin >> n;
    vector<event> ev;
    for (int i=0; i<n; i++){
        cin >> l[i];
    }
    sort(l, l+n);
    for (int i=0; i<n; i++){
        event aux;
        aux.op = true;
        aux.index = i;
        aux.pos = l[i];
        ev.push_back(aux);
    }

    for (int i=0; i<n; i++){
        cin >> r[i];
    }
    sort(r, r+n);
    for (int i=0; i<n; i++){
        event aux;
        aux.op = false;
        aux.index = i;
        aux.pos = r[i]+1;
        ev.push_back(aux);
    }
    sort(all(ev), compare);
    vector<pair<ll,ll>> intervals(n,{0,0});

    ll atual = 0;
    ll cont = 0;

    for (int i=0; i<ev.size(); i++){
        if (i) atual += cont*(ev[i].pos - ev[i-1].pos);

        // cout << "tratando o evento " << ev[i].pos << " " << ev[i].op << " " << ev[i].index << endl;
        // cout << "o cont e atual " << cont << " " << atual << endl;
        if (ev[i].op) {
            cont++; 
            intervals[ev[i].index].first = atual;
        }
        else{
            cont--;
            intervals[ev[i].index].second = atual;
        }    
    }


    for (int i=0; i<n; i++){
        cin >> c[i];
    }

    sort(c, c+n, greater<ll>());

    ll resp = 0;
    sort(all(intervals), compare2);

    for (int i=0; i<n; i++){
        // cout << intervals[i] << " " << l[i] << " " << r[i] << endl;
        resp += (r[i] - l[i])*c[i];
    }
    // cout << "////////\n";
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