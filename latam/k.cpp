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
// calcular o numero de rodadas. Junto com a vida do monstro e o power dele.
// se so tiver soma -> 
// se tiver multiplicação

// testar com brute force o novo problema


ll n,p,life;
vector<ll> soma;
vector<ll> mult;
ll ataques;

__int128_t multiplica(__int128_t x, __int128_t y){
    return min(x*y, (__int128_t)INF);
}

__int128_t calcDano(__int128_t k, __int128_t s){
    return (((p + s) + (p + (k)*s))*k*ataques)/2;  
}

const ll MAXN = 70;
ll prefixSoma[MAXN];
ll prefixMult[MAXN];


void solve(){
    cin >> n >> p >> life;

    ll ans = 0;
    
    for (int i=0; i<n; i++){
        char op;
        ll value;
        cin >> op;
        if (op == '!'){
            ataques++;
        }
        else{
            cin >> value;
            if (op == '+') soma.push_back(value);
            else mult.push_back(value);
        }
    }
    sort(soma.rbegin(), soma.rend());
    sort(mult.rbegin(), mult.rend());

    for (int i=0; i<soma.size(); i++){
        prefixSoma[i+1] = prefixSoma[i];
        prefixSoma[i+1] += soma[i];
    }
    prefixMult[0] = 1;
    for (int i=0; i<mult.size(); i++){
        prefixMult[i+1] = prefixMult[i];
        prefixMult[i+1] = multiplica(prefixMult[i+1], mult[i]);
    }

    if (!ataques){
        cout << '*' << endl;
        return;
    }

    if (prefixMult[mult.size()] < 2){
        ll soma_total = 0;
        for (auto x:soma) soma_total += x;
        ll l = 0;
        ll r = INF;
        
        while (r-l > 1){
            ll m = l + (r-l)/2;
            if ( calcDano(m,soma_total) >= life ) r = m;
            else l = m;
        }

        // cout << "l = " << l << " " << endl;
        // precisamos pre processar l movimentos antes.
        life -= calcDano(l, soma_total);
        p += l*soma_total;
        ans += l*n;
    }
    else{
        ll soma_total = 0;
        for (auto x:soma) soma_total += x;
        ll multTotal = 1;
        for (auto x:mult){
            multTotal *= x;
            multTotal = min(multTotal, (ll)INF);
        }

        while (life - multiplica(p+soma_total, multTotal)*ataques > 0){
            life -= multiplica(p+soma_total, multTotal)*ataques;
            p += soma_total;
            p = multiplica(p, multTotal);
            ans += n;
        }
    }
    
    ll bestFinalMov = INFLL;

    for (ll quantSomas = 0; quantSomas <= soma.size(); quantSomas++){
        for (ll quantMult = 0; quantMult <= mult.size(); quantMult++){
            for (ll quantAtaques = 1; quantAtaques <= ataques; quantAtaques++){
                ll pAux = p;

                pAux += prefixSoma[quantSomas];
                pAux = multiplica(pAux, prefixMult[quantMult]);

                if (pAux * quantAtaques >= life){
                    bestFinalMov = min(bestFinalMov, quantSomas + quantMult + quantAtaques);
                }
            }
        }
    }
    if (bestFinalMov >= INFLL){
        cout << "*" << endl;
        return;
    }

    cout << ans + bestFinalMov << endl;

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