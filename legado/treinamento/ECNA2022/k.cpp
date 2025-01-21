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

map<int, vector<int>> g1;
map<int, vector<int>> g2;

void solve(){
    string s;
    getline(cin,s);
    string s2;
    set<int> elements;
    set<int> elements1;
    set<int> elements2;
    for (auto c:s){
        if (c == '(') s2.push_back(' ');
        else if (c == ')'){
            s2.push_back(' ');
            s2.push_back('0');
        }
        else s2.push_back(c);
    }
    stringstream ss(s2);
    int v;
    stack<int> st;
    while (ss >> v){
        if (v){
            elements.insert(v);
            elements1.insert(v);
        }
        if (st.empty()){
            st.push(v);
        }
        else if (!v){
            st.pop();
        }
        else{
            g1[st.top()].push_back(v);
            st.push(v);
        }
    }


    getline(cin,s);
    s2.clear();
    for (auto c:s){
        if (c == '(') s2.push_back(' ');
        else if (c == ')'){
            s2.push_back(' ');
            s2.push_back('0');
        }
        else s2.push_back(c);
    }

    stringstream ss2(s2);
    while (!st.empty()){
        st.pop();
    }
    while (ss2 >> v){
        if (v){
            elements.insert(v);
            elements2.insert(v);
        }
        if (st.empty()){
            st.push(v);
        }
        else if (!v){
            st.pop();
        }
        else{
            g2[st.top()].push_back(v);
            st.push(v);
        }
    }

    if (elements1 != elements2){
        no();
        return;
    }
    for (auto v:elements){
        sort(all(g1[v]));
        sort(all(g2[v]));
        if (g1[v] != g2[v]){
            no();
            return;
        }
    }
    yes();
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