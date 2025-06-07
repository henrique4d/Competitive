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

void solve(){
    vector<ll> cont(300, 0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    char maisAparece;
    ll contMaisAparece = 0;
    vector<bool> temMina(300, false);

    for (auto x :s){
        cont[x]++;
    }

    for (int tam = n; tam <= 3*n; tam++){
        if (tam%3 == 0){
            vector<ll> contAtual(300,0);
            vector<ll> ans;
            int offset = 1;
            deque<char> proximos;
            for (int i=1; i<n; i++){
                proximos.push_back(s[i]);
            }
            char atual = s[0];
            while (proximos.size()){
                
                if (atual != proximos.front() and contAtual[atual^proximos.front()^'L'^'T'^'I'] + cont[atual^proximos.front()^'L'^'T'^'I'] < tam/3){
                    ans.push_back(offset);
                    contAtual[atual^proximos.front()^'L'^'T'^'I']++;
                    proximos.push_front(atual^proximos.front()^'L'^'T'^'I');
                    continue;
                }
                atual = proximos.front();
                proximos.pop_front();
                offset++;
            }
            

            if (contAtual['L'] + cont['L'] == tam/3 and contAtual['I'] + cont['I'] == tam/3 and contAtual['T'] + cont['T'] == tam/3){
                cout << ans.size() << endl;
                for (auto x:ans){
                    cout << x << endl;
                }
                return;
            }
        }
    }
    cout << -1 << endl;

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