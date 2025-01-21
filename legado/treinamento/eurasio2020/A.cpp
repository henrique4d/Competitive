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

struct vertex{
    int v, l , r, cont, ln, rn;
};
ll cont1, cont2;
vector<vertex> resp;
int cont = 1;
bool compare(vertex a, vertex b){
    return a.cont < b.cont;
}

int dfs(int val){
    //cout << "chamando dfs para " << val << endl;
    if (val == 0) return 0;
    vertex aux;
    aux.cont = cont;
    cont++;
    if (val == 2 and cont2){
        aux.v = 2;
        aux.l = 0;
        aux.r = 0;
        aux.ln = 0;
        aux.rn = 0;
        resp.push_back(aux);
        cont2--;
        return aux.cont;
    }
    if(val == 1){
        if (cont1){
            aux.v = 1;
            aux.l = 0;
            aux.r = 0;
            aux.ln = 0;
            aux.rn = 0;
            resp.push_back(aux);
            cont1--;
        }
        else{
            cout << -1 << endl;
            exit(0);
        }
        return aux.cont;
    }

    if (cont2){
        aux.v = 2;
        val -= 2;
        cont2--;
    }
    else if (cont1){
        aux.v = 1;
        val -= 1;
        cont1--;
    }
    aux.l = (val+1)/2;
    aux.r = val/2;
    aux.ln = dfs((val+1)/2);
    aux.rn = dfs(val/2);
    
    resp.push_back(aux);
    
    return aux.cont;
}

void solve(){
    cin >> cont1 >> cont2;
    dfs(cont1 + 2*cont2);
    sort(all(resp), compare);
    for (int i=0; i<resp.size(); i++){
        //cout << resp[i].cont << " " << resp[i].v << " " << resp[i].l << " " << resp[i].r << " " << resp[i].ln << " " << resp[i].rn << endl;
        cout << resp[i].v << " " << resp[i].ln << " " << resp[i].rn << endl;
    }
}
 
int main() {
//    optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}