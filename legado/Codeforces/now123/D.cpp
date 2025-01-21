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
    int n;
    cin >> n;
    vector<ll> v(n+1);
    vector<int> cont(n+1, 0);
    v[0] = 0;
    ll a = -1;
    ll b = -1;
    ll c = -1;
    bool to_return = false;

    for (int i=1; i<n; i++){
        int aux = -1;
        cin >> v[i];
        //cout << " a diferenca e " << abs(v[i] - v[i-1]) << endl;
        if (abs(v[i] - v[i-1]) > n){
            aux = abs(v[i] - v[i-1]);
        }
        else{
            cont[ abs(v[i] - v[i-1])]++;
            if (cont[ abs(v[i] - v[i-1])] > 1){
                aux = abs(v[i] - v[i-1]);
            }
        }
        
        if (aux != -1){
            if (c != -1){
                to_return = true;
            }
            c = aux;
        }
    }
    if (to_return){
        no();
        return;
    }
    for (int i=1; i<= n; i++){
        if ( cont[i] == 0){
            int aux = i;
            if (a == -1) a = aux;
            else if (b == -1) b = aux;
            else{
                no();
                return;
            }
        }
    }
    if (b == -1 and c == -1 and a <= n){
        yes();
        return;
    }
    if ( a + b == c){
        yes();
    }
    else{
        no();
    }

    //cout << a << " " << b << " " << c << endl;

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