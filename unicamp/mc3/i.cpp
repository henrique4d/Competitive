    #include <bits/stdc++.h>
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

    ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
    ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
    string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
    string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
    void yes() { cout<<"YES\n"; }
    bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
    void no() { cout<<"NO\n"; }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    //#define _DEBUG
    // #ifdef _DEBUG
    // #endif

    /* -------------------------------- Solution starts below -------------------------------- */ 

    bool compare1(pair<ll,ll> a, pair<ll,ll> b){
        if (atan((ld)a.second/(ld)a.first) != atan((ld)b.second/(ld)b.first)){
            return atan((ld)a.second/(ld)a.first) < atan((ld)b.second/(ld)b.first);
        }
        return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
    }
    bool compare2(pair<ll,ll> a, pair<ll,ll> b){
        return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
    }








    void solve(){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> quadrante1;
        vector<pair<ll,ll>> quadrante2;
        vector<pair<ll,ll>> quadrante3;
        vector<pair<ll,ll>> quadrante4;

        vector<pair<ll,ll>> axis1;
        vector<pair<ll,ll>> axis2;
        vector<pair<ll,ll>> axis3;
        vector<pair<ll,ll>> axis4;

        ll x,y;

        for (int i=0; i<n; i++){
            cin >> x >> y;
            if (x > 0 and y > 0){
                quadrante1.push_back({x,y});
            }
            else if (x < 0 and y > 0){
                quadrante2.push_back({x,y});
            }
            else if (x < 0 and y < 0){
                quadrante3.push_back({x,y});
            }
            else if (x > 0 and y < 0){
                quadrante4.push_back({x,y});
            }
            else if (x > 0 and y == 0){
                axis1.push_back({x,y});
            }
            else if (x == 0 and y > 0){
                axis2.push_back({x,y});
            }
            else if (x < 0 and y == 0){
                axis3.push_back({x,y});
            }
            else if (x == 0 and y < 0){
                axis4.push_back({x,y});
            }
        }

        sort(all(quadrante1),compare1);
        sort(all(quadrante2),compare1);
        sort(all(quadrante3),compare1);
        sort(all(quadrante4),compare1);
        sort(all(axis1), compare2);
        sort(all(axis2), compare2);
        sort(all(axis3), compare2);
        sort(all(axis4), compare2);

        for (auto [x,y]:axis1){
            cout << x << " " << y << endl;
        }
        for (auto [x,y]:quadrante1){
            cout << x << " " << y << endl;
        }
        for (auto [x,y]:axis2){
            cout << x << " " << y << endl;
        }
        for (auto [x,y]:quadrante2){
            cout << x << " " << y << endl;
        }

        for (auto [x,y]:axis3){
            cout << x << " " << y << endl;
        }
        for (auto [x,y]:quadrante3){
            cout << x << " " << y << endl;
        }
        
        for (auto [x,y]:axis4){
            cout << x << " " << y << endl;
        }
        for (auto [x,y]:quadrante4){
            cout << x << " " << y << endl;
        }



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