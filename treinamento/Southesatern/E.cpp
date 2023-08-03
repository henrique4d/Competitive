#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
 
 
void solve(){
    int n;
    cin >> n;
    string in;
    cin >> in;

    int conta = 0;
    int contb = 0;
    int contc = 0;
    for (int i=0; i<in.size(); i++){
        if (in[i] == 'A') conta++;
        if (in[i] == 'B') contb++;
        if (in[i] == 'C') contc++;
    }

    if (conta == contb and contb == contc){
        cout << 0 << endl;
        return;
    }

    int a = abs(n-conta);
    int b = abs(n-contb);
    int c = abs(n-contc);

    int ca = 0;
    int cb = 0;
    int cc = 0;


    int i=0;
    int j=0;

    if (in[0] == 'A') ca++;
    if (in[0] == 'B') cb++;
    if (in[0] == 'C') cc++;

    if ( conta >= n and contb >= n){
        while (true){
            if (ca == a and cb == b){
                cout << 1 << endl;
                cout << i+1 << " " << j+1 << " C\n";
                return;
            }
            if (ca > a or cb > b){
                if (in[i] == 'A') ca--;
                if (in[i] == 'B') cb--;
                if (in[i] == 'C') cc--;
                i++;
                if (i == in.size()) break;
            }
            else{
                j++;
                if (j == in.size()) break;
                if (in[j] == 'A') ca++;
                if (in[j] == 'B') cb++;
                if (in[j] == 'C') cc++;
            }
        }
    }
    if ( conta >= n and contc >= n){
        while (true){
            if (ca == a and cc == c){
                cout << 1 << endl;
                cout << i+1 << " " << j+1 << " B\n";
                return;
            }
            if (ca > a or cc > c){
                if (in[i] == 'A') ca--;
                if (in[i] == 'B') cb--;
                if (in[i] == 'C') cc--;
                i++;
                if (i == in.size()) break;
            }
            else{
                j++;
                if (j == in.size()) break;
                if (in[j] == 'A') ca++;
                if (in[j] == 'B') cb++;
                if (in[j] == 'C') cc++;
            }
        }
    }
    if ( contb >= n and contc >= n){
        while (true){
            if (cb == b and cc == c){
                cout << 1 << endl;
                cout << i+1 << " " << j+1 << " A\n";
                return;
            }
            if (cb > b or cc > c){
                if (in[i] == 'A') ca--;
                if (in[i] == 'B') cb--;
                if (in[i] == 'C') cc--;
                i++;
                if (i == in.size()) break;
            }
            else{
                j++;
                if (j == in.size()) break;
                if (in[j] == 'A') ca++;
                if (in[j] == 'B') cb++;
                if (in[j] == 'C') cc++;
            }
        }
    }

    conta = 0;
    contb = 0;
    contc = 0;
    for (int i=0; i<in.size(); i++){
    
        if (in[i] == 'A') conta++;
        if (in[i] == 'B') contb++;
        if (in[i] == 'C') contc++;

        if (conta == n){
            cout << 2 << endl;
            cout << i+2 << " " << 3*n << " B" << endl;
            cout << 3*n -(n-contc)+1 << " " << 3*n << " C" << endl;
            return;
        }

        if (contb == n){
            cout << 2 << endl;
            cout << i+2 << " " << 3*n << " A" << endl;
            cout << 3*n- (n-contc)+1 << " " << 3*n << " C" << endl;
            return;
        }

        if (contc == n){
            cout << 2 << endl;
            cout << i+2 << " " << 3*n << " A" << endl;
            cout << 3*n- (n-contb)+1 << " " << 3*n << " B" << endl;
            return;
        }
    
    }
}

int main() {
    //optimize;
    ll T = 1;
    //cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}