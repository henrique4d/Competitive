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
    int64_t a,b;
    mutable int64_t x_inter;

    bool operator <(const Line &o) const {
        return make_pair(a,b) < make_pair(o.a, o.b);
    }

    bool operator<(int64_t x) const {
        return x_inter < x;
    }

    int64_t getVal(int64_t x){
        return a*x + b;
    }
};

set<Line, less<>> cht;


int64_t intersection(Line x, Line y){
    assert(x.a != y.a);
    return (x.b - y.b)/(y.a - x.a);
}


void fix_x_inter(auto it){
    if (next(it) != cht.end()){
        it->x_inter = (next(it)->b - it->b)/(it->a - next(it)->a);
    }
}


void add_line(int64_t a, int64_t b){

    auto it = cht.insert({a,b,INFLL}).first;
    if (next(it) != cht.end() and next(it)->a == a){
        cht.erase(it);
        return;
    }
    if (it != cht.begin() and prev(it)->a == a){
        cht.erase(prev(it));
        if (it != cht.begin()) fix_x_inter(prev(it));
    }

    if (it != cht.begin() and next(it) != cht.end()){
        if (intersection(*it, *prev(it)) >= intersection(*it, *next(it))){
            cht.erase(it);
            return;
        }
    }

    while(it != cht.begin() and prev(it) != cht.begin()){
        auto y = prev(it);
        auto x = prev(y);
        if (intersection(*x, *it) <= intersection(*x, *y)) cht.erase(y);
        else break;
    }

    while (next(it) !=cht.end() and next(next(it)) != cht.end()){
        auto x = next(it);
        auto y = next(x);
        if (intersection(*x, *it) > intersection(*x,*y)) cht.erase(x);
        else break;
    }

    fix_x_inter(it);
    
    if (it != cht.begin()) fix_x_inter(prev(it));
}

int64_t query(int64_t x){
    auto line = *cht.lower_bound(x);
    return line.a*x + line.b;
}


const ll MAXN = 5e4 + 10;

Line pos[MAXN];


void solve(){
    int n,q;
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        add_line(0,0);
        Line aux;
        aux.a = 0;
        aux.b = 0;
        pos[i] = aux;
    }

    int t;
    while(q--){
        cin >> t;
        if (t == 1){
            int64_t time, ciclista, newspeed;
            
            cin >> time >> ciclista >> newspeed;
            ll a = newspeed;
            ll b = pos[ciclista].getVal(time) - newspeed*time;
            Line aux;
            aux.a = a;
            aux.b = b;
            pos[ciclista] = aux;
            add_line(a,b);       
        }
        if (t == 2){
            ll time;
            cin >> time;
            cout << query(time) << endl;
        }
    }

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