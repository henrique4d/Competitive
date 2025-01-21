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
#define MOD 998244353LL
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

ll n,k;
const ll MAXN = 5e5+10;
ll a[MAXN];
pair<ll,ll> valIndex[MAXN];
ll need = 0;

bool eval(ll pos){
    ll x = valIndex[pos].first;
    ll index = valIndex[pos].second;
    // cout << "fazendo busca binaria " << x << " " << index << endl;
    ll l = 0;
    ll contmenor = 0;
    ll contmaior = 0;
    ll contRemoves = 0;
    for (int i=0; i<n; i++){
        if (i == index){
            l = i+1;
            contmenor = 0;
            contmaior = 0;
        }
        if (a[i] < x) contmenor++;
        else contmaior++;
        if (i - l +1 == k){
            if (contmenor > contmaior){
                contRemoves++;
                l = i+1;
            }
            else{
                if (a[l] < x) contmenor--;
                else contmaior--;
                l++;
            }
        }
    }
    return contRemoves >= need;
}

void solve(){
    cin >> n >> k;
    need = n/k;
    if (n%k == 0) need--;

    for (int i=0; i<n; i++){
        cin >> a[i];
        valIndex[i].first = a[i];
        valIndex[i].second = i;
    }
    sort(valIndex, valIndex+n);

    ll l = -1;
    ll r = n;

    ll m;
    
    while (r-l > 1){
        m = l + (r-l)/2;
        cout <<l << " " << r << " " << m << " " << eval(m) << endl;
       
        if (eval(m)) r = m;
        else l = m;
    }
    

    cout << r << endl;
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