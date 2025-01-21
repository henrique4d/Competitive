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
const ll MAXN = 2e5+10;
ll a[MAXN];

void solve(){
    cin >> n;
    ll x;
    multiset<ll> s1;
    int n;
    multiset<ll> s2;
    multiset<ll> s3;
    multiset<ll> s4;
    
    for (int i=0; i<n; i++){
        cin >> x;
        if (x <10) s1.insert(x);
        else s2.insert(x);
    }


    for (int i=0; i<n; i++){
        cin >> x;
        if (x <10) s3.insert(x);
        else s4.insert(x);
    }


    for (auto it = s1.begin(); it!=s1.end();){
        if (s3.find(*it) != s3.end()){
            s3.erase(s3.find(*it));
            auto next = it;
            next++;
            s1.erase(it);
            it = next;
        }
        else{
            it++;
        }
    }    

    for (auto it = s2.begin(); it!=s2.end();){
        if (s4.find(*it) != s4.end()){
            s4.erase(s4.find(*it));
            auto next = it;
            next++;
            s2.erase(it);
            it = next;
        }
        else{
            it++;
        }
    }
    

    ll resp = 0;
    for (auto it = s2.begin(); it!=s2.end(); it++){
        if (s3.find(log10(*it)+1) != s3.end()){
            s3.erase(s3.find(log10(*it)+1));
        }
        else{
            s1.insert(log10(*it)+1);
        }
        
        resp++;
 
    }


    for (auto it = s4.begin(); it!=s4.end(); it++){
        if (s1.find(log10(*it)+1) != s1.end()){
            s1.erase(s1.find(log10(*it)+1));
        }
        else{
            s3.insert(log10(*it)+1);
        }
        resp++;
    }

    for (auto it = s1.begin(); it!=s1.end();){
        if (s3.find(*it) != s3.end()){
            s3.erase(s3.find(*it));
            auto next = it;
            next++;
            s1.erase(it);
            it = next;
        }
        else{
            if (*it != 1) resp++;
            it++;
        }
    }


    for (auto it = s3.begin(); it!=s3.end(); it++){
        if (*it != 1) resp++;
    }
    cout << resp << endl;




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