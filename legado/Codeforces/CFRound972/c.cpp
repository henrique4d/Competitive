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
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
map<char,ll> value;
map<ll, char> letra;
vector<string> words;

const ll MAXN = 1e3+10;

ll dp[10][MAXN];
bool calc[10][MAXN];

ll n,m;

void init(){
    words.resize(n);
    for (int i=0; i<10; i++){
        for (int j=0; j<n+10; j++){
            calc[i][j] = false;
            dp[i][j] = 0;
        }
    }
}

ll DP(int pos, int searchingValue){
    ll resp = -searchingValue;
    if (pos == n) return resp;
    if (calc[searchingValue][pos]) return dp[searchingValue][pos];
   
    ll contNeg = 0;
    ll contPos = 0;
    ll aux = searchingValue;

    for (auto c:words[pos]){
        if (letra[aux] == c){
            aux++;
            if (aux == 5){
                aux = 0;
                contPos += 5;
            }
        }
        else if (value.find(c) != value.end()){
            contNeg++;
        }
    }
    calc[searchingValue][pos] = true;

    return dp[searchingValue][pos] = max({resp, DP(pos+1, searchingValue), contPos - contNeg + DP(pos+1, aux)});

}



void solve(){
    cin >> n >> m;
    init();
    for (int i=0; i<n; i++){
        cin >> words[i];
    }
    cout << DP(0,0) << endl;
}

int main() {
    optimize; 

    value['n'] = 0;
    value['a'] = 1;
    value['r'] = 2;
    value['e'] = 3;
    value['k'] = 4;
    
    letra[0] = 'n';
    letra[1] = 'a';
    letra[2] = 'r';
    letra[3] = 'e';
    letra[4] = 'k';
    
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}