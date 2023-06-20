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

vector<int> dp (1e7,0);

ll tab[1123][112312];
vector<pii> book;

ll knapsack(int obj,int aguenta){
    if(obj==-1) return 0;

    if(tab[obj][aguenta]>=0){
        return tab[obj][aguenta];
    }
    if(!aguenta){
        return tab[obj][aguenta] = 0;
    }

    int nao = knapsack(obj-1,aguenta);

    if(book[obj].fi<=aguenta){
        int coloca = book[obj].se + knapsack(obj-1,aguenta-book[obj].fi);
        return tab[obj][aguenta]=max(nao,coloca); 
    }

    return tab[obj][aguenta] = nao;
}


int main(){
    int n,x;
    cin>>n>>x;

    for(int i=0;i<n;i++){
        for(int j=0;j<x+10;j++){
            tab[i][j] = -1;
        }
    }

    book.resize(n);
    
    //tab.resize(n+10,vector<ll>(x+10,-1));

    for(int i=0;i<n;i++){
        cin>>book[i].fi;
    }

    for(int i=0;i<n;i++){
        cin>>book[i].se;
    }

    ll res = knapsack(n-1,x);

    cout << res << endl;


}