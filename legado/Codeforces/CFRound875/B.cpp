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
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
ll T,N,M,K;
ll MAXM = 1123456;

void solve(){
    int n;
    cin >> n;
    vector<int> cont(2*n + 50, 0);
    vector<int> cont2(2*n + 50, 0);

    int aux = 0;
    int val;
    int contAt = 0;
    for (int i=0; i<n; i++){
        cin >> val;
        if (val != aux){
            cont[aux] = max(cont[aux], contAt);
            contAt = 0;
            aux = val;
        }
        contAt++;
 
    }
    cont[val] = max(cont[val], contAt);
    


    aux = 0;
    contAt = 0;

    for (int i=0; i<n; i++){
        cin >> val;

        if (val != aux){
            cont2[aux] = max(cont2[aux], contAt);
            contAt = 0;
            aux = val;
        }
        contAt++;

    }
    //cout << endl;

    cont2[val] = max(cont2[val], contAt);
    

    int maior = 0;
    int resp = 0;

    for (int i=1; i<=2*n+10;i++){
        maior = max(maior, cont[i] + cont2[i]);
    }

    // for (int i=1; i<=5;i++){
    //     cout << cont[i] << " " << cont2[i] << endl;
    //     // maior = max(maior, cont[i] + cont2[i]);
    // }
    cout << maior << endl;
}
 
 
int main() {
 
    optimize;
 
    T = 1;
 
    cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}
