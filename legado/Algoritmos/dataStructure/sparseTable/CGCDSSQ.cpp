//link: https://codeforces.com/contest/475/problem/D

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
 
const int K = 30;
const int MAXN = 1e5+10;

int st[K+1][MAXN];
int n;
   
void build(int arr[], int n){
    for (int i=0; i<n; i++){
        st[0][i] = arr[i];
    }
    for (int i=1; i<K; i++){
        for(int j=0; j + (1<<i) <= n; j++){
            st[i][j] = __gcd(st[i-1][j], st[i-1][ j+( 1<<(i-1) )] );
        }
    }
}

map<int,ll> cont;
void fill_query(){
    for (int left=0; left<n; left++){
        int g = st[0][left];
        int l = left;
        while (l < n){
            g = __gcd(g, st[0][l]);
            int l_orig = l;
        
            for (int aux = K; aux >= 0; aux--){
                if ( l + (1<<aux) <= n){
                    if ( __gcd(st[aux][l], g) == g){
                        l += (1<<aux);
                    }
                }
            }
            cont[g] += l - l_orig;
        }       
    }
}

void solve(){
    cin >> n;
    int arr[n];
    f(i,0,n){
        cin >> arr[i];
    }

    build(arr,n);
    int q;
    cin >> q;
    int x;
    fill_query();
    while(q--){
        cin >> x;
        cout << cont[x] << endl;
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