
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
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    cin >> z;
    while(z--){
        int n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> m(n);

        f(i,0,n){
            cin >> v[i];
        }
        f(i,0,n){
            cin >> m[i];
        }

        int it1 = 0;
        
        pair<int,int> best = {0,0};
        int tamanho = 0;
        bool tem_diferenca = false;

        m.push_back(INT_MIN);
        v.push_back(INT_MIN);


        f(i,1,n+1){
            
            if (m[i] < m[i-1]){
                it1 = i;
                tem_diferenca = false;
            }

            if (m[i] != v[i]) tem_diferenca = true;

            // cout << i << " "<< it1 << " "<< tem_diferenca << endl;
            if (i - it1 > tamanho and tem_diferenca){
                best = {it1, i};
                tamanho  = i - it1;
            }
        }
        cout << best.first+1 << " " << best.second+1 << endl;

    }

}
