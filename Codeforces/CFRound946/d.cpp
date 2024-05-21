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
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAX = 2e5+10;
char a[MAX];
int n;

void solve(){
    int contn = 0;
    int conts = 0;
    int conte = 0;
    int contw = 0;

    cin >> n;
    char x;
    for (int i=0; i<n; i++){
        cin >> x;
        a[i] = x;
        if ( x == 'N') contn++;
        if ( x == 'S') conts++;
        if ( x == 'E') conte++;
        if ( x == 'W') contw++; 
    }
    if ((contn&1) != (conts&1) or (conte&1) != (contw&1)){
        no();
        return;
    }
    vector<char> resp(n);
    resp[0] = 'H';

    pair<int,int> posh = {0,0};
    pair<int,int> posr = {0,0};

    posh.first += a[0] == 'N';
    posh.first -= a[0] == 'S';
    posh.second += a[0] == 'W';
    posh.second -= a[0] == 'E';

    for (int i=1; i<n; i++){
 
        if (a[i] == 'N'){
            if (posh.first < posr.first) resp[i] = 'H';
            else resp[i] = 'R';
        }
        if (a[i] == 'S'){
            if (posh.first > posr.first) resp[i] = 'H';
            else resp[i] = 'R';
        }

        if (a[i] == 'W'){
            if (posh.second < posr.second) resp[i] = 'H';
            else resp[i] = 'R';
        }
        if (a[i] == 'E'){
            if (posh.second > posr.second) resp[i] = 'H';
            else resp[i] = 'R';
        }

        if (resp[i] == 'H'){
            posh.first += a[i] == 'N';
            posh.first -= a[i] == 'S';
            posh.second += a[i] == 'W';
            posh.second -= a[i] == 'E';
        }else{
            posr.first += a[i] == 'N';
            posr.first -= a[i] == 'S';
            posr.second += a[i] == 'W';
            posr.second -= a[i] == 'E';
        }
    }



    bool temr = false;
    bool temh = false;
    for (auto c:resp){
        if (c == 'R') temr = true;
        else temh = true;
    }
    if (!temr or !temh){
        no();
        return;
    }
    for (auto c:resp){
        cout << c;
    }
    cout << endl;
    
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