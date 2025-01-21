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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    cin >> z;
    while(z--){
        int n, x1,x2,y1,y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        ll resp = 0;
        int meio = n/2;
        int val1;
        int val2;
        int dist_parede1 = 0;
        int dist_parede2 = 0;

        if (x1 > meio){
            dist_parede1 = n+1-x1;
        }
        else{
            dist_parede1 = x1;
        }
        if (y1 > meio){
            dist_parede1 = min(dist_parede1, n+1-y1);
        }
        else{
            dist_parede1 = min(dist_parede1, y1);
        }


        if (x2 > meio){
            dist_parede2 = n+1-x2;
        }
        else{
            dist_parede2 = x2;
        }
        if (y2 > meio){
            dist_parede2 = min(dist_parede2, n+1-y2);
        }
        else{
            dist_parede2 = min(dist_parede2, y2);
        }

        resp = abs(dist_parede1 - dist_parede2);
        cout << resp << endl;
    }
}