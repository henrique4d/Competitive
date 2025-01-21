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
/* PRlong long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int get_luck(int n){
    int maior = 0;
    int menor = 100;

    while (n){
        maior = max(maior, n%10);
        menor = min(menor, n%10);
        n/=10;
    }

    return maior-menor;
}





int main(){
    int z;
    cin >> z;
    while(z--){
        int n, m;
        cin >> n >> m;
        vector<vector<long long int>> v(m, vector<long long int>(n));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> v[j][i];
            }
        }
        // f(i,0,m){
        //     print_v(v[i]);
        //     cout << endl;
        // }
        long long int resp = 0;
        if (n == 1){
            cout << resp << endl;
            continue;
        }
        f(i,0,m){
            sort(all(v[i]));
            
            for (int j=0; j<n; j++){
                resp -= (n-1-j)*v[i][j];
                resp += j*v[i][j];
            }
        }

        cout << resp << endl;
    }
}