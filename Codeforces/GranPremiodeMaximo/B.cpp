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
 
#define mod 1000000007LL
#define MAXN 200010
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
ll T,N,M,K;
 

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    f(i,0,n){
        cin >> v[i].first >> v[i].second;
    }
    map<pair<long double, long double>, set<pair<int,int>>> m;
    map<int,set<pair<int,int>>> vertical;
    int maior = 0;
    f(i,0,n){
        f(j,i+1,n){
            long double g = INT_MAX;
            if (v[j].first - v[i].first == 0){
                vertical[v[i].first].insert({v[i].first, v[i].second});
                vertical[v[i].first].insert({v[j].first, v[j].second});
                if (vertical[i].size() > maior){
                    maior = vertical[i].size();
                }
            }
            else{
                g = (long double) (v[j].second - v[i].second)/(v[j].first - v[i].first);        
                long double c = v[i].second - v[i].first*g;
                g = abs(g);
                c = abs(c);
                
                m[{g,c}].insert({v[i].first, v[i].second});
                m[{g,c}].insert({v[j].first, v[j].second});
                
                if (m[{g,c}].size() > maior){
                    maior = m[{g,c}].size();
                }
            }
            
        }
    }
    int resp = 0;
    
    if (maior/2 > n-maior){
        resp = n-maior;
    }
    else{
        resp = n/3;
    }
    cout << resp << endl;
}
 
 
int main() {
 
    optimize;
 
    T = 1;
 
    //cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}