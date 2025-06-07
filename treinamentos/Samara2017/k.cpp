#include <bits/stdc++.h>
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
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 4e5+10;

struct Node{
    ll value;
    ll tempo;
    int competicao;
    int last;
    int pos;
    Node(){
        value = 0;
        tempo = 0;
        competicao = -1;
        last = -1;
        pos = 0;
    }
};
struct Comp{
    int l;
    int r;
    int value;
    int duracao;
    int indice;
};
Comp quer[MAXN];
bool compare(Comp a, Comp b){
    return a.r < b.r;
}

Node st[4*MAXN];
Node combine(Node a, Node b){
    if (a.value != b.value){
        return a.value>b.value?a:b;
    }
    return a.tempo<b.tempo?a:b;
}

void build(int v, int tl, int tr){
}

void update(int v, int tl, int tr, int pos, Node x){
    // cout << v << " " << tl << " " << tr << endl;

    if (tl == tr and tl == pos){
        st[v] = combine(st[v],x);
        return;
    }
    int tm = tl + (tr-tl)/2;
    if (pos <= tm) update(2*v, tl, tm, pos, x);
    else update(2*v+1, tm+1, tr, pos, x);
    st[v] = combine(st[2*v], st[2*v+1]);
}

Node query(int v, int tl, int tr, int l, int r){
    if(l > r){
        Node thrash;
        thrash.value = -1;
        return thrash;
    }
    if (tl == l and tr == r) return st[v];
    int tm = tl + (tr-tl)/2;
    return combine(query(2*v, tl, tm,l,min(r,tm)), query(2*v+1, tm+1,tr,max(l,tm+1), r));
}

void solve(){
    ll n;
    cin >> n;
    vector<int> vals;
    for (int i=0; i<n; i++){
        cin >> quer[i].l;
        cin >> quer[i].r;
        cin >> quer[i].value;
        quer[i].duracao = quer[i].r-quer[i].l;
        quer[i].indice = i+1;
        vals.push_back(quer[i].l);
        vals.push_back(quer[i].r);
    }
    sort(all(vals));
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i=0; i<n; i++){
        quer[i].l = lower_bound(all(vals), quer[i].l) - vals.begin() + 1;
        quer[i].r = lower_bound(all(vals), quer[i].r) - vals.begin() + 1;
    }

    
    sort(quer, quer+n, compare);

    // for (int i=0; i<n; i++){
    //     cout << i << " " << quer[i].l << " " << quer[i].r << " " << quer[i].value << endl;
    // }
    // cout << "///////////\n";

    for (int i=0; i<n; i++){
        // cout << "here\n" << endl;
        Node aux = query(1,0,2*n,0,quer[i].l);
        // cout << i << " " << quer[i].l << " " << quer[i].value << endl;

        aux.tempo += quer[i].duracao;
        aux.value += quer[i].value;
        aux.last = aux.pos;
        aux.competicao = quer[i].indice;
        aux.pos = quer[i].r;
        // cout << "dando update no value " << quer[i].r << " " <<  aux.value << " " << aux.competicao << endl;
        update(1,0,2*n, quer[i].r, aux);
    }

    // return;
    vector<int> ans;
    // return;
    Node aux = query(1,0,2*n,0,2*n);
    ll tempo_total = aux.tempo;
    ll value_final = aux.value;


    while (aux.competicao != -1){
        ans.push_back(aux.competicao);
        aux = query(1,0,2*n, aux.last, aux.last);
    }

    cout << ans.size() << " " <<  value_final << " " << tempo_total << endl;
    for (auto x:ans) cout << x << " ";
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