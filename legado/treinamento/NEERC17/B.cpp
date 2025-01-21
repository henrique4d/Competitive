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
 
#define mod 998244353LL
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
 
 
void solve(){
    vector<int> tam(3);
    for (int i=0; i<3; i++){
        cin >> tam[i];
    }
    sort(all(tam));
    int altura, largura;
    cin >> altura >> largura;
    do{
        int a = tam[0];
        int b = tam[1];
        int c = tam[2];
        int size1 = a;
        int size2 = 2*b + c;

        int aux1 = size1 + 2*b + a;
        int aux2 = size2;
        if (min(aux1, aux2) <= min (altura, largura) and max(aux1, aux2) <= max(altura, largura)){
            //cout << "here1 " << a << " " << b << " " << c << endl;
            yes();
            return;
        }

        aux1 = size1 + 2*b;
        aux2 = size2 + c;
        if (min(aux1, aux2) <= min (altura, largura) and max(aux1, aux2) <= max(altura, largura)){
            //cout << "here2 " << a << " " << b << " " << c << endl;
            yes();
            return;
        } 



        aux1 = size1 + 2*c;
        aux2 = size2 + a;
        if (min(aux1, aux2) <= min (altura, largura) and max(aux1, aux2) <= max(altura, largura)){
            //cout << "here3 " << a << " " << b << " " << c << endl;
            yes();
            return;
        } 


        aux1 = size1 + 2*c;
        aux2 = size2 + c;
        if (min(aux1, aux2) <= min (altura, largura) and max(aux1, aux2) <= max(altura, largura)){
            //cout << "here4 " << a << " " << b << " " << c << endl;
            yes();
            return;
        }



        aux1 = size1 + c;
        aux2 = size2 + a + b;
        if (min(aux1, aux2) <= min (altura, largura) and max(aux1, aux2) <= max(altura, largura)){
            //cout << "here5 " << a << " " << b << " " << c << endl;
            yes();
            return;
        } 


    }while(next_permutation(all(tam)));

    no();
}
 
 
 
int main() {
    optimize;
    ll T = 1;
    //cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}