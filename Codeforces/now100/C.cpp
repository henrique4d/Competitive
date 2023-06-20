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
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    a--;
    b--;
    c--;
    bool trocou = false;
    if (a < b ){
        swap(a,b);
        trocou = true;
    }
    if (c > max(a,b)+1 or c < max(a,b)){
        cout << -1 << endl;
        return;
    }

    ll menorA = pow(10,a);
    ll menorB = pow(10,b);
    ll menorC = pow(10,c);
    
    ll Borigi = pow(10,b);
    
    ll limiarA = pow(10, a+1) - menorA -1;
    ll limiarB = pow(10, b+1) - menorB -1;
    ll limiarC = pow(10, c+1) - menorC -1;

    ll limiarAorig = limiarA;
    ll limiarBorig = pow(10, b+1)-1;
    ll limiarCorig = limiarC;
    
  
    ll diff = menorC - (menorA + menorB);
    if (diff < 0){
        menorC -= diff;
        limiarC += diff;
    }
    if (limiarC < 0){
        cout << -1 << endl;
        return ;
    }

    if (diff > 0){
        ll aux = min(limiarB, diff);
        menorB += aux;
        limiarB -= aux;
        diff -= aux;
    }

    if (diff > 0){
        ll aux = min(limiarA, diff);
        menorA += aux;
        limiarA -= aux;
        diff -= aux;
    }
    cout << menorA << " " << menorB << " " << menorC << endl;
    k;
    cout << limiarA << " " << limiarB << " " << limiarC << endl;
    if (k < limiarB){
        menorB += k;
        cout << "printando dentro do if: ";
        cout << menorA << " " << menorB << " " << menorC << endl;
        // printa
    }
    else if (limiarB){
        k-= limiarB;
        menorA++;
        limiarA--;
    }
    else{
        menorB = Borigi;
    }
    limiarB = limiarBorig;
        
    cout << "o limiar b e: " << limiarB << endl;
    
    ll aumentarA = (k+limiarB)/limiarB;
    ll aumentarB = k%limiarB;
    ll aumentarC = aumentarA + aumentarB;
    
    menorC = menorA + aumentarA + menorB+aumentarB;

//    cout << menorA << " " << menorB << " " << menorC << " " << aumentarA << " " << aumentarB << " " << aumentarC << endl;
    cout << menorA + aumentarA << " " << menorB+aumentarB << " " << menorC << endl;

//    cout << menorA << " " << menorB << " " << menorC << " " << limiarA << " " << limiarB << " " << limiarC << endl;
//    cout << diff << endl;
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