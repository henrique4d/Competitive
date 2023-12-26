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
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << bitset<10>(x) << ","; cout << "\b}\n"; }
#define MOD 998244353
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

const int MAXN = 1e5 + 10;
struct vertex{
    int pos;
    int next;
};

int a[MAXN];
int valores[MAXN];

vertex st[4*MAXN];
vertex combine(vertex a, vertex b){
    vertex resp;
    if (a.next < b.next) resp = a;
    else resp = b;
    return resp;
}

void build(int v, int tl, int tr){
    if (tl == tr){
        st[v].pos = tl;
        st[v].next = a[tl];
        return;
    }
    int tm = tl + (tr - tl)/2;
    build (2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = combine(st[2*v], st[2*v+1]);
}

void update(int v, int tl, int tr, int pos, int new_val){
    if (tl == tr){
        st[v].next = new_val;
        st[v].pos = tl;
        return;
    }
    int tm = tl + (tr - tl)/2;
    if (pos <= tm){
        update(2*v, tl, tm, pos, new_val);
    }
    else{
        update(2*v+1, tm+1, tr, pos, new_val);
    }
    st[v] = combine(st[2*v], st[2*v+1]);
}

vertex query(int v, int tl, int tr, int l, int r){
    if (l > r){
        vertex trash;
        trash.pos = INT_MAX;
        trash.next = INT_MAX;
        return trash;
    }
    if (tl == l and tr == r) return st[v];
    int tm = tl + (tr - tl)/2;
    return combine(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(tm+1,l), r) );
}

 
void solve(){
    int n,q;
    cin >> n >> q;
    map<int, set<int>> app;
    int aux;
    for (int i=0; i<n; i++){
        cin >> aux;
        valores[i] = aux;
        app[aux].insert(i);
    }

    for (auto val:app){
        val.second.insert(INT_MAX);
        
        auto it = val.second.begin();

        int atual = *it;
        it++;
        for (; it!=val.second.end(); it++){
            a[atual] = *it;
            atual = *it;
        }
    }
    int t,l,r,val;
    build(1,0,n-1);
    while (q--){
        cin >> t;
        if (t == 1){
            cin >> l >> r;
            l--;
            r--;
            vertex v1 = query(1,0,n-1,l,r);
            if (v1.next > r){
                cout << -1 << endl;
                goto here;
            }

            int savenext = a[v1.next];
            int savepos = a[v1.pos];
            update(1, 0, n-1, v1.next, INT_MAX);
            update(1, 0, n-1, v1.pos, INT_MAX);


            vertex v2 = query(1,0,n-1, l, r);

            update(1, 0, n-1, v1.next, savenext);
            update(1, 0, n-1, v1.pos, savepos);
            
            
            if (v2.next > r){
                cout << -1 << endl;
                goto here;
            }
            cout << v1.pos+1 << " " << v1.next+1 << " " << v2.pos+1 << " " << v2.next+1 << endl;
        }
        else{
            cin >> l;
            l--;
            cin >> val;

            auto it = app[valores[l]].lower_bound(l);
            if (it == app[valores[l]].begin()){
                app[valores[l]].erase(l);
            }
            else{
                auto itprev = it;
                itprev--;
                a[*itprev] = a[*it];
                update(1,0,n-1, *itprev, a[*it]);
                app[valores[l]].erase(l);
            }

            valores[l] = val;
            app[valores[l]].insert(l);
            app[valores[l]].insert(INT_MAX);
            it = app[valores[l]].lower_bound(l);

            auto itnext = it;
            itnext++;
            a[*it] = *itnext;
            update(1,0,n-1, *it, *itnext);
            if (it == app[valores[l]].begin()){
                goto here;
            }
            auto itprev = it;
            itprev--;
            a[*itprev] = *it;
            update(1,0,n-1, *itprev, *it);
        }
        here:
        int asuhdfhua;
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