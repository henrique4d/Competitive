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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
#define mod 998244353LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

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

class op{
    public: 
    bool operator()(pair<ll,list<pair<ll,ll>>::iterator> &a, pair<ll,list<pair<ll,ll>>::iterator> &b ){
        return a.first < b.first;
    }
};


void solve(){
    int n;
    cin >> n;
    priority_queue<pair<ll,list<pair<ll,ll>>::iterator>, vector<pair<ll,list<pair<ll,ll>>::iterator>>, op> pq;
    list<pair<ll, ll>> l;
    ll x;
    vector<bool> used(n+5, false);
    set<list<pair<ll,ll>>::iterator> s;
    
    for (int i=0; i<n; i++){
        cin >> x;
        l.push_back({x,i});
    }

    for (list<pair<ll,ll>>::iterator it = l.begin(); it!=l.end(); it++){
        if (it != l.begin()){
            auto itprev = it;
            itprev--;
            if ((*itprev).first + 1 == (*it).first){
                if (!used[it->second])
                    pq.push({(*it).first,it});
                used[it->second] = true;
                continue;
            }
        }
        auto itnext = it;
        itnext++;
        if (itnext != l.end() and (*itnext).first + 1 == (*it).first){
            if (!used[it->second])
                pq.push({(*it).first, it});
            used[it->second] = true;
        }
    }
    while (!pq.empty()){
        auto it = pq.top().second;
        pq.pop();
        
        bool prev = false;
        bool next = false;
        auto ita = it;
        auto itb = it;
        itb++;
        if (it != l.begin()){
            ita--;
            prev = true;
        }
        if (itb != l.end()){
            next = true;
        }
        l.erase(it);
        if (prev){
            it = ita;
            if (it != l.begin()){
                auto itprev = it;
                itprev--;
                if ((*itprev).first + 1 == (*it).first){
                    if (!used[it->second])
                        pq.push({(*it).first,it});
                    used[it->second] = true;
                    goto here;
                }
            }
            auto itnext = it;
            itnext++;
            if (itnext != l.end() and (*itnext).first + 1 == (*it).first){
                if (!used[it->second])
                    pq.push({(*it).first, it});
                used[it->second] = true;
            }
        }
        here:
        if (next){
            it = itb;
            if (it != l.begin()){
                auto itprev = it;
                itprev--;
                if ((*itprev).first + 1 == (*it).first){
                    if (!used[it->second])
                        pq.push({(*it).first,it});
                    used[it->second] = true;
                    continue;
                }
            }
            auto itnext = it;
            itnext++;
            if (itnext != l.end() and (*itnext).first + 1 == (*it).first){
                if (!used[it->second])
                    pq.push({(*it).first, it});
                used[it->second] = true;
            }
        }
    }
    if (l.size() > 1 or (*l.begin()).first != 0){
        no();
    }
    else yes();

}

int main() {
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}