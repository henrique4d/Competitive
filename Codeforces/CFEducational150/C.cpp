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
 
const ll MAXN = 2e3+5;


ll getVal(string & in){
    vector<int> signal(in.size());
    ll maior = 0;
   
    for (int i=in.size()-1; i>=0; i--){
        if (pow(10, in[i]-'A') >= maior){
            maior = pow(10, in[i]-'A');
            signal[i] = 1;
        }
        else{
            signal[i] = -1;
        }
    }
//    cout << signal << endl;

    ll sum = 0;
    for (int i=0; i<in.size(); i++){
        sum += pow(10, in[i] - 'A')*signal[i];
    }
    //cout << in << " " << sum << endl;
    return sum;
}
 
void solve(){
   // string gamb = "EBCDEEDCBA";
    
    // getVal(gamb);
    // return;
    string in;
    cin >> in;
    int menor = INT_MAX;
    int maior = INT_MIN;
    ll best = getVal(in);

    for (int i=0; i<in.size(); i++){
        if (i == 0 or i ==in.size()-1 or in[i] >= maior or in[i] <= menor){
            char aux = in[i];
            for (int j='A'; j<='E'; j++){
                in[i] = j;
                best = max(best, getVal(in));
            }
            in[i] = aux;
            maior = max(maior, (int)in[i]);
            menor = min(menor, (int)in[i]);
        }
        //cout << in << endl;
    }

    menor = INT_MAX;
    maior = INT_MIN;
    
    for (int i=in.size()-1; i>=0; i--){
        if (i == 0 or i ==in.size()-1 or in[i] >= maior or in[i] <= menor){
            char aux = in[i];
            for (int j='A'; j<='E'; j++){
                in[i] = j;
                best = max(best, getVal(in));
            }
            in[i] = aux;
            maior = max(maior, (int)in[i]);
            menor = min(menor, (int)in[i]);
        }
        //cout << in << endl;
    }
    cout << best << endl;
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