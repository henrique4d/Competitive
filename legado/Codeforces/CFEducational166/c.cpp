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
const ll MAXN = 4e5+10;

ll a[MAXN];
ll b[MAXN];
ll grupo[MAXN];

int n,m;

void solve(){
    cin >> n >> m;
    ll contn = 0;
    ll contm = 0;
    
    vector<ll> resp(n+m+1);
    ll val_atual = 0;

    set<int> pos0;
    set<int> pos1;
    set<int> pos0_1;
    set<int> pos1_0;
    for (int i=0; i<n+m+1; i++){
        cin >> a[i];
    }
    for (int i=0; i<n+m+1; i++){
        cin >> b[i];
    }
    
    for (int i=1; i<n+m+1; i++){
        if (n == contn){
            val_atual += b[i];
            grupo[i] = 1;
            contm++;
        }
        else if (m == contm){
            val_atual += a[i];
            grupo[i] = 0;
            contn++;
        }
        else if (a[i] > b[i]){
            val_atual += a[i];
            grupo[i] = 0;
            contn++;
        }
        else{
            val_atual += b[i];
            grupo[i] = 1;
            contm++;    
        }
        if (grupo[i] == 0){
            pos0.insert(i);
            if (a[i] < b[i]) pos0_1.insert(i);
        }
        else{
            pos1.insert(i);
            if (a[i] > b[i]){
                pos1_0.insert(i);
            }
        }
    }

    contn = 0;
    contm = 0;
    resp[0] = val_atual;
    for (int i=1; i<n+m+1; i++){
        if (grupo[i] == 0){
            val_atual -= a[i];
        }
        else{
            val_atual -= b[i];
        }

        if (n == contn){
            val_atual += b[i-1];
            grupo[i-1] = 1;
            contm++;
        }
        else if (m == contm){
            val_atual += a[i-1];
            grupo[i-1] = 0;
            contn++;
        }
        else if (a[i-1] > b[i-1]){
            val_atual += a[i-1];
            grupo[i-1] = 0;
            contn++;
        }
        else{
            val_atual += b[i-1];
            grupo[i-1] = 1;
            contm++;    
        }

        if (grupo[i-1] == 1 and grupo[i] == 0){
            auto it = pos1_0.upper_bound(i);
            if (it != pos1_0.end()){
                val_atual -= b[*it];
                val_atual += a[*it];
                grupo[*it] = 0;
                pos0.insert(*it);
                pos1_0.erase(it);
                pos1.erase(*it);
            }
            else{
                it = pos1.end();
                it--;

                val_atual -= b[*it];
                val_atual += a[*it];
                grupo[*it] = 0;
                pos0.insert(*it);
                pos1.erase(*it);
                pos0_1.insert(*it);
            }
        }

        else if (grupo[i-1] == 0 and grupo[i] == 1){
            auto it = pos0_1.upper_bound(i);
            if (it != pos0_1.end()){
                val_atual -= a[*it];
                val_atual += b[*it];
                grupo[*it] = 1;
                pos1.insert(*it);
                pos0_1.erase(it);
                pos0.erase(*it);
            }
            else{
                it = pos0.end();
                it--;
                
                val_atual -= a[*it];
                val_atual += b[*it];
                grupo[*it] = 1;
                pos1.insert(*it);
                pos0.erase(*it);
                pos1_0.insert(*it);
            }
        }

        resp[i] = val_atual;

    }
    for (int i=0; i<n+m+1; i++){
        cout << resp[i] << " ";
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