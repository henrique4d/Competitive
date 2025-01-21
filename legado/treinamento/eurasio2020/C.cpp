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
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << bitset<10>(x) << ","; cout << "\b}\n"; }
#define MOD 998244353
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

const int MAXN = 25;
vector<int> neighbor[MAXN];
vector<int> solutions[MAXN];
int degree[MAXN];
vector<int> auxiliar;
bool compare(int a, int b){
    return __popcount(a) < __popcount(b);
}

void print(int u){
    for (auto x:solutions[u]){
        cout << bitset<6>(x) << " ";
    }
    cout << endl;
}

void construct_solution(int u){    
    if (!degree[u]){
        solutions[u].push_back(1<<u);
        return;
    }

    auxiliar.clear();

    int base = (1<<u);
    solutions[u].push_back(base);
    
    for (auto v:neighbor[u]){
        construct_solution(v);
        auxiliar.clear();
        bool descendo = true;

        for (auto s1:solutions[u]){
            if (descendo){
                auxiliar.push_back(s1);
                for (auto s2:solutions[v]){
                    auxiliar.push_back(s1|s2);
                }
            }
            else{
                for (auto it2 = solutions[v].rbegin(); it2 != solutions[v].rend(); it2++){
                    auxiliar.push_back(s1|*it2);
                }
                auxiliar.push_back(s1);
                
            }
            descendo = !descendo;    
        }   
        solutions[u] = auxiliar;
        auxiliar.clear();
    }
}

void solve(){
    int n;
    cin >> n;
    int aux;
    for (int i=1; i<=n-1; i++){
        cin >> aux;
        aux--;
        neighbor[aux].push_back(i);
        degree[aux]++;    
    }
    construct_solution(0);
    auto it1 = solutions[0].begin();
    auto it2 = it1;
    it2++;
    cout << (int)solutions[0].size()-1 << endl;
    for (;it2!=solutions[0].end(); it2++){
        int xoor = ((*it2)^(*it1));
        for (int i=0; i<=20; i++){
            if (xoor & (1<<i)){
                cout << i+1 << " ";
                break;
            }
        }
        it1 = it2;
    }  
    cout << endl;
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