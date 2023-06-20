#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<long long int,long long int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRlong long long long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,long long int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,long long int b) { if (a>b) return a; return b; }
// ll max(long long int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
 
 
vector<vector<long long int>> up;
vector<vector<long long int>> d1; //valor para "descer"
vector<vector<long long int>> d2; //valor para "subir"
long long int n;
long long int LOG;
 
vector<long long int> depth;
vector<bool> visited;

int main(){
    int z;
    cin >> z;
    while(z--){
        int n,m;
        cin >> n >> m;
        int x1, y1, x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int resp = INT_MAX;

        if (x1 != x2){
            resp = min(resp,m);          
        }
        if (y1 != y2){
            resp = min(resp, n);
        }

        int cicloA = min(x1,n-x1+1) + min(y1,m-y1+1);

        int cicloB = min(x2,n-x2+1) + min(y2,m-y2+1);
        
        resp = min(resp, cicloA);
        resp = min(resp, cicloB);

        resp = min(resp,4);


        if (x1 == 1 or x1 == n or y1 == 1 or y1 == m or x2 == 1 or x2 == n or y2 == 1 or y2 == m){
            resp = min(resp,3);
        }
        cout << resp << endl;
    }
}