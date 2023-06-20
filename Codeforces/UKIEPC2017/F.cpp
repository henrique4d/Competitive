#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int n;

long double memorization[450][450];

long double dp (int heads, int flips){
    //cout << heads << " " << flips << endl;
    
    if (memorization[heads][flips] != -1) return memorization[heads][flips];
    
    if (!flips) memorization[heads][flips] = heads;
    else if (heads < n){
        memorization[heads][flips] = (0.5*dp(heads+1, flips-1) + 0.5* dp(heads, flips-1));
    }
    else{
        memorization[heads][flips] = (0.5*dp(heads-1, flips-1) + 0.5*dp(heads,flips-1));
    }

    return memorization[heads][flips];
}


int main(){
    int flips;
    f(i,0,450){
        f(j,0,450){
            memorization[i][j] = -1;
        }
    }
    cin >> n >> flips;
    //cout << memorization[10][10] << endl;
    long double resp = dp(0, flips);
    cout << fixed << setprecision(7) << resp << endl;
}