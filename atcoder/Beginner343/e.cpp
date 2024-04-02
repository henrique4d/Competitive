#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

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

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 


void solve(){
    int v1, v2, v3;
    
    
    cin >> v1 >> v2 >> v3;

    for (int a = -7; a<=7; a++){
        for (int b = -7; b<=7; b++){
            for (int c = -7; c<=7; c++){
                for (int a2 = -7; a2 <= 7; a2++){
                    for (int b2 = -7; b2 <=7; b2++){
                        for (int c2 = -7; c2 <= 7; c2++){
                            int x = max(0,min({0, a, a2}) + 7 - max({0,a,a2}));
                            int y = max(0,min({0, b, b2}) + 7 - max({0,b,b2}));
                            int z = max(0,min({0, c, c2}) + 7 - max({0,c,c2}));

                            int area3 = max(0,x*y*z);


                            int area2 = 0;
                            x = max(0,min({0, a}) + 7 - max({0,a}));
                            y = max(0,min({0, b}) + 7 - max({0,b}));
                            z = max(0,min({0, c}) + 7 - max({0,c}));
                            area2 += max(0,x*y*z);

                            x = max(0,min({0, a2}) + 7 - max({0,a2}));
                            y = max(0,min({0, b2}) + 7 - max({0,b2}));
                            z = max(0,min({0, c2}) + 7 - max({0,c2}));
                            area2 += max(0,x*y*z);

                            x = max(0,min({a2, a}) + 7 - max({a2,a}));
                            y = max(0,min({b2, b}) + 7 - max({b2,b}));
                            z = max(0,min({c2, c}) + 7 - max({c2,c}));
                            area2 += max(0,x*y*z);

                            area2 -= 3*area3;

                            int area1 = 1029 - 3*area3 - 2*area2;

                            if (area1 == v1 and area2 == v2 and area3 == v3){
                                yes();
                                cout << "0 0 0 " << a << " " << b << " " << c << " " << a2 << " " << b2 << " " << c2 << endl;
                                return;
                            }

                        }
                    }
                }
            }
        }
    }
    no();
}

int main() {
    optimize; 
    
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}