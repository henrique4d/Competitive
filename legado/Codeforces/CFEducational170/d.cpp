#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef int ll;
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
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 


const ll MAXK = 5e3+10;
int prefixForca[MAXK][MAXK];
int prefixInteligencia[MAXK][MAXK];

ll dp[MAXK][2*MAXK];
ll n,k;
    
void init(){
    for (int i=0; i<k+5; i++){
        for (int j=-k-5; j<k+5; j++){
            dp[i][MAXK-j] = -1;
        }
    }
}

ll DP(ll pos, ll distribuicao){
    if (pos >= k) return 0;
    if (dp[pos][distribuicao] != -1) return dp[pos][distribuicao];
    
    distribuicao -= MAXK;
    ll strength, inte;

    if (distribuicao < 0){
        strength = abs(distribuicao) + (pos+1+distribuicao)/2;
        inte = (pos+1+distribuicao)/2;
    }
    else{
        inte = abs(distribuicao) + (pos+1-distribuicao)/2;
        strength = (pos+1-distribuicao)/2;
    }
    ll score = prefixForca[pos][strength] + prefixInteligencia[pos][inte];// (upper_bound(all(forca[pos]), strength) - forca[pos].begin()) + (upper_bound(all(inteligencia[pos]), inte) - inteligencia[pos].begin());  //forca[pos].order_of_key({strength, INFLL}) + inteligencia[pos].order_of_key({inte, INFLL});
    
    return dp[pos][distribuicao+MAXK] = max(DP(pos+1,distribuicao+MAXK+1),DP(pos+1,distribuicao+MAXK-1)) + score;
}


void solve(){
    cin >> n >> k;
    init();
    int pos = -1;
    ll x;
    for (int i=0; i<n; i++){
        cin >> x;
        if (!x) pos++;
        else if (x<0 and pos != -1) prefixForca[pos][-x]++;
        else if (pos != -1) prefixInteligencia[pos][x]++;
    }
    for (int i=0; i<k+5; i++){
        for (int j=1; j<MAXK; j++){
            prefixForca[i][j] += prefixForca[i][j-1];
            prefixInteligencia[i][j] += prefixInteligencia[i][j-1];
        
        }
    }
    
    cout << max(DP(0, MAXK+1), DP(0,MAXK-1)) << endl;

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