#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define endl "\n"
 
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
    vector<ll> adj[(n+5)*(m+5)];
    string linha;
    cin.ignore();
    ll start;
    ll finish;

    ll cont_i = 0;
    for (ll i=0; i<4*n+3; i++){
        getline(cin,linha);
        //cout << linha.size() << endl;
        //string aux = "          ";
        
        //cout << i << " " << linha << endl;
        if (i%4 == 0){
            for (ll j=0; j<(m+1)/2; j++){
                if (3 + j*12 < linha.size() and linha[3 + j*12] == ' '){
                    adj[cont_i*m + 2*j].push_back((cont_i-1)*m + 2*j);
                    adj[(cont_i-1)*m + 2*j].push_back(cont_i*m + 2*j);

                    //cout << "criando adjacencia de1 " << cont_i*m + 2*j << " " << (cont_i-1)*m + 2*j << endl;
                }
                if (10+j*12 < linha.size() and linha[10+j*12] == 'S'){
                    start = (cont_i-1)*m + 2*j+1;
                }
                if (10+j*12 < linha.size() and linha[10+j*12] == 'T'){
                    finish = (cont_i-1)*m + 2*j+1;
                }
            }
        }
        if (i%4 == 1){
            for (ll j=0; j<(m+1)/2; j++){
                if (1 + j*12 < linha.size() and linha[1 + j*12] != '/'){
                    adj[cont_i*m + 2*j].push_back((cont_i-1)*m + 2*j-1);
                    adj[(cont_i-1)*m + 2*j-1].push_back(cont_i*m + 2*j);
                    
                    //cout << "criando adjacencia de2 " << cont_i*m + 2*j << " " << (cont_i-1)*m + 2*j-1 << endl;

                }
                if (7 + j*12 < linha.size() and linha[7 + j*12] != '\\'){
                    adj[cont_i*m + 2*j].push_back((cont_i-1)*m + 2*j+1);
                    adj[(cont_i-1)*m + 2*j+1].push_back(cont_i*m + 2*j);

                    //cout << "criando adjacencia de3 " << cont_i*m + 2*j << " " << (cont_i-1)*m + 2*j+1 << endl;

                }
            }
        }
        if (i%4 == 2){
            for (ll j=0; j<m/2; j++){
                if (9 + j*12 < linha.size() and linha[9 + j*12] == ' '){
                    adj[cont_i*m + 2*j+1].push_back((cont_i-1)*m + 2*j+1);
                    adj[(cont_i-1)*m + 2*j+1].push_back(cont_i*m + 2*j+1);

                    //cout << "criando adjacencia de4 " << cont_i*m + 2*j+1 << " " << (cont_i-1)*m + 2*j+1 << endl;
                }

                if (4+j*12 < linha.size() and linha[4+j*12] == 'S'){
                    start = cont_i*m + 2*j;
                }
                if (4+j*12 < linha.size() and linha[4+j*12] == 'T'){
                    finish = cont_i*m + 2*j;
                }
            }
        }
        if (i%4 == 3){
            for (ll j=0; j<(m+1)/2; j++){
                if (1 + j*12 < linha.size() and linha[1 + j*12] != '\\'){
                    adj[cont_i*m + 2*j].push_back(cont_i*m + 2*j-1);
                    adj[cont_i*m + 2*j-1].push_back(cont_i*m + 2*j);
                    //cout << "criando adjacencia de5 " << cont_i*m + 2*j << " " << cont_i*m + 2*j-1 << endl;

                }
                if (7 + j*12 < linha.size() and linha[7 + j*12] != '/'){
                    adj[cont_i*m + 2*j].push_back(cont_i*m + 2*j+1);
                    adj[cont_i*m + 2*j+1].push_back(cont_i*m + 2*j);

                    //cout << "criando adjacencia de6 " << cont_i*m + 2*j << " " << cont_i*m + 2*j+1 << endl;
                }
            }
            cont_i++;
        }
    }
    // /cout << start << " " << finish << endl;


    queue<ll> to_process;
    vector<bool> used((m+5)*(n+5),false);
    
    to_process.push(start);
    used[start] = true;
    ll cont = 1;
    while(!to_process.empty()){
        ll tam = to_process.size();
        for (ll i=0; i<tam; i++){
            ll atual = to_process.front();
            //cout << "o atual e " << atual << endl;
            to_process.pop();
            for (auto next:adj[atual]){
                //if (next >= n*m or next <0) continue;
                if (next == finish){
                    cout << cont+1 << endl;
                    return;
                }
                if (!used[next]){
                    //cout << "adicionando " << next << endl;
                    to_process.push(next);
                    used[next] = true;
                }
            }
        }
        cont++;
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