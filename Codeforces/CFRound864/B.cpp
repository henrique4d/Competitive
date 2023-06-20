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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> z;
    vector<vector<int>> table(1e3+10, vector<int>(1e3+10));
    vector<vector<int>> table2(1e3+10, vector<int>(1e3+10));
    
    while(z--){
        int n;
        int k;
        cin >> n >> k;
        
        f(i,0,n){
            f(j,0,n){
                cin >> table[i][j];
                table2[n-i-1][n-j-1] = table[i][j];
            }
        }
        int cont = 0;
        f(i,0,n){
            f(j,0,n){
                if (table[i][j] != table2[i][j]) cont++;
            }
        }
        if (n == 1){
            yes();
            continue;
        }
        cont/=2;
        //cout << cont << endl;
        if (cont <= k and (n%2 == 1 or (k-cont)%2 == 0)) yes();
        else no();
        
        
    }
}