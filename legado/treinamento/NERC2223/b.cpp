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
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> a(n+5, vector<char>(m+5, '#'));
    multiset<pair<int,pair<int,int>>> bestRow[n+5];
    multiset<pair<int,pair<int,int>>> bestColum[m+5];
    multiset<pair<int,pair<int,int>>> bestRowGeral;
    multiset<pair<int,pair<int,int>>> bestColumGeral;
    
    for (int i=1; i<=n; i++){
        int start = -1;
        int end = 0;
        bestRow[i].insert({0,{-1,-1}});
        bestRowGeral.insert({0,{-1,-1}});
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            if (a[i][j] == '.'){
                end = j;
                if (start == -1) start = j;
            }
            else{
                if (start != -1){
                    bestRow[i].insert({end-start+1, {start, end}});
                    bestRowGeral.insert({end-start+1, {start, end}});
                }
                start = -1;
            }
        }
        if (start != -1){
            bestRow[i].insert({end-start+1, {start, end}});
            bestRowGeral.insert({end-start+1, {start, end}});
        }
    }

    for (int j=1; j<=m; j++){
        int start = -1;
        int end = 0;
        bestColum[j].insert({0,{-1,-1}});
        bestColumGeral.insert({0,{-1,-1}});

        for (int i=1; i<=n; i++){
            if (a[i][j] == '.'){
                end = i;
                if (start == -1) start = i;
            }
            else{
                if (start != -1){
                    bestColum[j].insert({end-start+1, {start, end}});
                    bestColumGeral.insert({end-start+1, {start, end}});
                }
                start = -1;
            }
        }
        if (start != -1){
            bestColum[j].insert({end-start+1, {start, end}});
            bestColumGeral.insert({end-start+1, {start, end}});
        }
    }
    int resp = 0;

    auto it = bestColumGeral.rbegin();
    auto it2 = it;
    it2++;
    resp = max(resp, it->first + it2->first);

    it = bestRowGeral.rbegin();
    it2 = it;
    it2++;
    resp = max(resp, it->first + it2->first);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            auto itr = bestRow[i].rbegin();
            auto itr2 = itr;
            itr2++;

            auto itc = bestColum[j].rbegin();
            auto itc2 = itc;
            itc2++;
            if ((itr->second.first<= j and itr->second.second>=j) and (itc->second.first<= i and itc->second.second>=i)){
                resp = max(resp, itr->first + max(abs(itc->second.first -i), abs(itc->second.second - i)));
                resp = max(resp, itc->first + max(abs(itr->second.first -j), abs(itr->second.second - j)));
                resp = max(resp, itc->first + itr2->first);
                resp = max(resp, itr->first + itc2->first);
            }
            else{
                resp = max(resp, itc->first + itr->first);
            }
        }
    }    

    cout << resp << endl;
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