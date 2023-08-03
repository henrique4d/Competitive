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
    #define MOD 998244353
    ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
    ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
    // string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
    // string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
    // void yes() { cout<<"Yes\n"; }
    //bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
    void no() { cout<<"No\n"; }
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    
    //#define _DEBUG
    // #ifdef _DEBUG
    // #endif
    
    /* -------------------------------- Solution starts below -------------------------------- */ 
    const ll MAXN = 3e3 + 100;
    ll dp[MAXN][2*MAXN];
    ll k[MAXN];
    ll color[MAXN];
    ll s[MAXN];
    ll subtree[MAXN];
    ll auxiliar[2*MAXN];
    ll desloc[MAXN];

    vector<ll> neighbor[MAXN];
    ll resp = 0;
    void calculate_subtree(ll v, ll p){
        subtree[v] = 1;
        for (auto u:neighbor[v]){
            if (u == p) continue;
            calculate_subtree(u,v);
            subtree[v] += subtree[u];
        }
    }

    void dfs(ll v, ll p, ll c){
        subtree[v] = 1;
        for (auto u:neighbor[v]){
            if (u == p) continue;
            dfs(u, v, c);
            subtree[v] += subtree[u];
        }
        ll hmm = min(k[c], subtree[v]);
        desloc[v] = hmm;
        //ll desloc = max(k[c], subtree[v]);
        //ll hmm = k[c];
        

        //cout << k[c] << " " << subtree[v] << endl;
        
        for (ll val = -hmm - 1; val<= hmm + 1; val++){
            auxiliar[val + desloc[v] + 1] = 0;
            dp[v][val + desloc[v] + 1] = 0;
        }
      
        if (color[v] == c){
            dp[v][1 + desloc[v]+1] += 1;
            //dp[v][1 + desloc[v]+1]%= MOD;
        }
        else{
            dp[v][-1 + desloc[v]+1] += 1;
            //dp[v][-1 + desloc[v]+1] %= MOD;
        }
            
        for (auto u:neighbor[v]){
            if (u == p) continue;
            //leaf = false;
            //cout << "ESTOU NO VERTICE " << v << " E NO FILHO " << u << endl;
            for (ll val1 = -hmm-1; val1<= hmm+1; val1++){

                //for (ll val2 = val1 -hmm; val1 + val2 <= hmm; val2++){
                // -val1 - val2 <= kc + 1
                // -val2 = kc + 1 + val1
                for (ll val2 = max(-desloc[u]-1, -val1 - hmm-1); val1 + val2 <=hmm; val2++){
                    //cout << val1 << " " << val2 << " " << dp[v][val1 + hmm + 1] << " " << dp[u][val2 + hmm + 1] << endl;
                    if (val1 + val2 == hmm + 1) break;
                    if ( -val1 - val2 <= hmm and val1 + val2 <= hmm and dp[v][val1 + desloc[v] + 1] and dp[u][val2 + desloc[u] + 1]){
                        //cout << " entrou no if\n";
                        //cout << "somando na posicao " << val1 + val2 + + hmm << " o valor " << dp[v][val1 + hmm] + dp[u][val2 + hmm] << endl;
                        //cout << val1 << " " << val2 << " " << dp[u][val2 + hmm+1] <<   endl;
                        auxiliar[val1 + val2 + desloc[v]+1] += ((dp[v][val1 + desloc[v]+1]) * (dp[u][val2 + desloc[u] + 1]));
                        auxiliar[val1 + val2 + desloc[v]+1] %= MOD;           
                    }
                }
            }
            for (ll val1 = -hmm-1; val1<= hmm+1; val1++){
                dp[v][val1 + desloc[v]+1] += auxiliar[val1 + desloc[v]+1];
                dp[v][val1 + desloc[v]+1]%=MOD;
                auxiliar[val1 + desloc[v]+1] = 0;
            }
            // cout << "estado atual da dp\n";
            // for (ll val = -hmm-1; val<= hmm+1; val++){
            //     cout << dp[v][val + hmm+1] << " ";
            // }
            // cout << endl;
        }

        for (ll val1 = 1; val1<= hmm+1; val1++){
                resp += dp[v][val1 + desloc[v]+1]; 
                resp %= MOD;
        }

        // if (leaf){
        //     dp[v][s[v] + hmm+1] += 1;
        // }
        // cout << "vertice " << v << " cor " << c << " tamanho " << hmm << " " << s[v] << endl;
        // for (ll val = -hmm-1; val<= hmm+1; val++){
        //     cout << dp[v][val + desloc[v]+1] << " ";
        // }
        // cout << endl;

    }

    void solve(){
        ll n;
        cin >> n;

        for (ll i=0; i<n ;i++){
            cin >> color[i];
            color[i]--;
            k[color[i]]++;
        }
        ll a,b;
        for (ll i=0; i<n-1; i++){
            cin >> a >> b;
            a--;
            b--;
            neighbor[a].push_back(b);
            neighbor[b].push_back(a);
        }

        //calculate_subtree(0,-1);
     
        
        for (ll i=0; i<n; i++){
            if (!k[i]) continue;
            dfs(0,-1, i);

            
            // for (ll j=1; j<= k[i]; j++){
            //     resp += dp[0][j + k[i]+1];
            //     resp %= MOD;
            // }
            
            //cout << "cor " << i << " " << resp << endl;
        }
        // for (ll i=0; i<n; i++){
        //     cout << subtree[i] << " ";
        // }
        // cout << endl;
        cout << resp << endl;

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