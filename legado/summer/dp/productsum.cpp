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
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

struct Line {
    int64_t a,b, x_inter;
    bool operator <(int64_t x) const {
        return x_inter < x;
    }
};
deque<Line> cht;

int64_t intersection(Line x, Line y){
    assert(x.a != y.a);
    return (x.b - y.b)/(y.a - x.a);
}

void add_line_back(int64_t a, int64_t b){
    if (!cht.empty() and cht.back().a == a) cht.pop_back();

    while (cht.size() >= 2){
        auto x = cht[cht.size() - 2];
        auto y = cht[cht.size() - 1];
        if (intersection(y, {a,b,0}) < intersection(x,y)){
            cht.pop_back();
        }
        else break;
    }
    if (!cht.empty()){
        cht.back().x_inter = intersection(cht.back(), {a,b,0});
    }
    cht.push_back({a,b, INFLL});
}

int64_t query(int64_t x){
    int j = lower_bound(cht.begin(), cht.end(), x) - cht.begin();
    return cht[j].a*x + cht[j].b;
}


void add_line_front(int64_t a, int64_t b){
    if (!cht.empty() and cht[0].a == a) return;
    while (cht.size() >= 2){
        a   uto x = cht[0];
        auto y = cht[1];
        if (intersection (x, {a,b,0}) > intersection(x,y)){
            cht.pop_front();
        }
        else break;
    }
    cht.push_front({a,b,INFLL});
    if (cht.size() > 1){
        cht[0].x_inter = intersection(cht[0], cht[1]);
    }
}

const ll MAXN = 2e5 + 10;
int64_t prefixsum[MAXN];
int64_t a[MAXN];


void solve(){
    int n;
    cin >> n;
    ll total = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        total += a[i]*i;
        prefixsum[i] = prefixsum[i-1] + a[i];
    }

    add_line_back(1, -prefixsum[0]);

    int64_t best = 0;
    for (int i=1; i<=n; i++){
        best = max(best, prefixsum[i-1] - a[i]*i + query(a[i]));
        add_line_back(i,-prefixsum[i-1]);
    }

    cht.clear();

    add_line_front(n, -prefixsum[n]);
    for (int i=n; i>=1; i--){
        best = max(best, prefixsum[i] - a[i]*i + query(a[i]));
        add_line_front(i,-prefixsum[i]); 
    }


    cout << total + best << endl;



}

int main() {
    optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}