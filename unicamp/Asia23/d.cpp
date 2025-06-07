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
    const ll MAXN = 200;
    ll ans [MAXN][MAXN];
    ll n,m;

    void init(){
        for (int i=0; i<n+10; i++){
            for (int j=0; j<m+10; j++){
                ans[i][j] = 0;
            }
        }
    }

    int cont = 0;

    void solve(){
        ll d1,d2;
        cin >> n >> m >> d1 >> d2;
        init();
        char c;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin >> c;
                if (c == 'V') ans[i][j] = -1;
            }
        }
        int movX[8] = {0,1,1,1,0,-1,-1,-1};
        int movY[8] = {-1,-1,0,1,1,1,0,-1};

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (ans[i][j] == -1) continue;
                for (int k=0; k<8; k++){
                    if (ans[i+movY[k]][j+movX[k]] == -1){
                        if (movY[k] == 0 or movX[k] == 0) ans[i][j] = max(ans[i][j], d1);
                        else ans[i][j] = max(ans[i][j], d2);
                    }
                }
            }
        }

        cont++;
        cout << "Airplane #" << cont << ":\n";

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (ans[i][j] == -1) cout << "V";
                else cout << ans[i][j];
            }
            cout << endl;
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