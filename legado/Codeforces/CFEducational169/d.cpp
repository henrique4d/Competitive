#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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
const ll MAXN = 2e5+10;
map<string, set<int>> app;
string portais[MAXN];

void init(){
    app.clear();
}

void solve(){
    int n,q;
    init();
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> portais[i];
        app[portais[i]].insert(i);
    }

    while (q--){
        int l,r;
        cin >> l >> r;

        string s1 = portais[l];
        string s2 = portais[r];

        string s3;
        s3.push_back(s1[0]);
        s3.push_back(s2[0]);
        ll resp = INFLL;
        auto it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }

        s3 = "";
        s3.push_back(s1[0]);
        s3.push_back(s2[1]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        s3 = "";
        s3.push_back(s1[1]);
        s3.push_back(s2[0]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        s3 = "";
        s3.push_back(s1[1]);
        s3.push_back(s2[1]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        swap(s1,s2);
        s3 = "";
        s3.push_back(s1[0]);
        s3.push_back(s2[0]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }

        s3 = "";
        s3.push_back(s1[0]);
        s3.push_back(s2[1]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        s3 = "";
        s3.push_back(s1[1]);
        s3.push_back(s2[0]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        s3 = "";
        s3.push_back(s1[1]);
        s3.push_back(s2[1]);
        
        it = app[s3].lower_bound(l);
        if (it != app[s3].end()){
            resp = min(resp, (ll)abs(*it - l) + (ll)abs(*it - r));
            auto itnext = it;
            itnext++;
            if (itnext != app[s3].end()){
                resp = min(resp, (ll)abs(*itnext - l) + (ll)abs(*itnext - r));
            }
        }
        if (it != app[s3].begin()){
            auto itprev = it;
            itprev--;
            resp = min(resp, (ll)abs(*itprev - l) + (ll)abs(*itprev - r));
        }


        if (resp == INFLL) resp = -1;
        cout << resp << endl;
    }

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