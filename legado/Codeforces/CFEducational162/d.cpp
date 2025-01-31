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
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 

const ll MAXN = 3e5+10;
ll a[MAXN];
ll sum[MAXN];
ll sumDif[MAXN];

void solve(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        sum[i] = sum[i-1];
        sum[i] += a[i];
        sumDif[i] = sumDif[i-1];
        if (i < n and a[i] != a[i+1]) sumDif[i]++;
    }

    for (int i=1; i<=n; i++){
        ll left = INFLL;

        ll l = 0;
        ll r = i;
        // cout << "calculando para i = " << i << endl;
        while (r-l > 1){
            ll m = l + (r-l)/2;
            // cout << m << " " << sumDif[i-1] - sumDif[m-1] << " " << sum[i-1] - sum[m-1] << endl;
            if (i == 1) continue;
            if ( (sumDif[i-2] - sumDif[m-1] > 0 or i - m ==1 or a[m] > a[i]) and sum[i-1] - sum[m-1] > a[i] ){
                l = m;
                if (left == INFLL){
                    left = m;
                }
                left = max(left, m);
            }
            else{
                r = m;
            }
        }
        // cout << i << " " << left << endl;


        ll right = -1;
        l = i;
        r = n+1;
        // cout << "calculando para i = " << i << endl;
        
        while (r-l > 1){
            ll m = l + (r-l)/2;
            // cout << m << " " << sumDif[m] - sumDif[i] << " " << sum[m] - sum[i] << endl;
            if ( (sumDif[m-1] - sumDif[i] > 0 or m - i == 1  or a[m] > a[i]) and sum[m] - sum[i] > a[i]){
                r = m;
                if (right == -1){
                    right = m;
                }
                right = min(right, m);
            }
            else{
                l = m;
            }
        }

        ll resp = -1;
        if (left != INFLL){
            resp = i - left;
        }
        if (right != -1){
            if (resp == -1){
                resp = right - i;
            }
            resp = min(resp, right - i);
        }
        // cout << i << " " << left << " " << right << endl;
        cout << resp << " ";
    }
    cout << endl;

}

int main() {
    optimize; 
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}