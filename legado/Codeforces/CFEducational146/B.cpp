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
        ll a,b;
        cin >> a >> b;
        ll resp = INT64_MAX;
        ll val_anterior = INT64_MAX;
        ll val_atual = 0;
        vector<long long int> divisores;
        for (int i=1; i<= sqrt(a); i++){
            if (a%i == 0){
                divisores.push_back(i);
                divisores.push_back(a/i);
            }
        }
        for (int i=1; i<= sqrt(b); i++){
            if (b%i == 0){
                divisores.push_back(i);
                divisores.push_back(b/i);
            }
        }

        for(ll val: divisores){
            ll i = val-1;
            val_atual = (a+i)/(i+1) + (b+i)/(i+1) + i;
            resp = min(resp, val_atual);
        }
        
        // ll val_anterior2 = INT_MAX;
        // ll val_atual2 = 0;
        // for(int i=max(a,b)-1; i>=0; i--){
        //     //cout << a << " " << b << " " << i << " " <<  (a+i)/(i+1) << " " << (b+i)/(i+1) << " " << i << endl; 
        //     val_atual2 = (a+i)/(i+1) + (b+i)/(i+1) + i;
        //     //cout << i << " " << val_atual << endl;
        //     if (val_atual2 > val_anterior2) break;
        //     val_anterior2 = val_atual2;
        // }

        // resp = min (resp, val_anterior2);
        //cout << "resp parcial " << resp << endl;
        // for(int i=1; i<=b; i++){
        //     val_atual = (b+i-1)/i + i - 1;
        //     if (val_atual < val_anterior) break;
        //     val_anterior = val_atual;
        // }
        // resp += val_atual;

        cout << resp << endl;
    }
}