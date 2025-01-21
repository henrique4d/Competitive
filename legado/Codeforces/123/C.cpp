#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
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
 
 
void solve(){
    string base;
    cin >> base;
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
 
    map<char, int> mmin;
    map<char, int> mmax;
 
    for (int i = '0'; i<='9'; i++){
        mmin[i] = INT_MAX;
        mmax[i] = INT_MAX; 
    }
 
    int lookin_forA = 0;
    int dist_endA = n-1;
    int lookin_forB = 0;
    int dist_endB = n-1;
 
    mmin[a[0]] = n;
    mmax[b[0]] = n;    
 
 
    for (int i=0; i<base.size(); i++){
        cout << i << endl;
        
 
 
        for (int j = '0'; j<='9'; j++){
            cout << "para o caractere " << (char)j << " o valor minimo/maximo e " << mmin[j] << " " << mmax[j] << endl;
            if (base[i] < j and base.size()-i >= mmin[j]){
                yes();
                return;
            }
            if (base[i] > j and base.size()-i >= mmax[j]){
                yes();
                return;
            }
        }
        if (base[i] == a[lookin_forA]){
            lookin_forA++;
            mmin[a[lookin_forA]] = dist_endA;        
            dist_endA--;
        }
        if (base[i] == b[lookin_forB]){
            lookin_forB++;
            mmax[b[lookin_forB]] = dist_endB;
            dist_endB--;
        }
    }
    no();
 
 
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