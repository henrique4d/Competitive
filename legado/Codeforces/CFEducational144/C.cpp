#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
 
/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
 
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
 
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


long long int eval(long long int n, long long int x, long long int q){
    return n*x* pow(2, q-2);
}

long long int binary(long long int n, long long int q, long long int limite, long long int r){
    long long int l = 0;
    r = INT_MAX;
    long long int meio = l + (r-l)/2;

    while(true){
        //cout << l << " " << meio << " " << r << endl;
        if (eval(n, meio, q) <= limite){
            if (eval(n, meio+1,q) > limite) return meio;
            l = meio;
        }
        else{
            r = meio;
        }
        meio = l + (r-l)/2;
    }
}


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    int z;
    cin >> z;
    f(l,0,z){
        long long int a,b;
        cin >> a >> b;
        long long int tamanho = log2( (long double)b/a) +1;
        long long int quantidade = 0;
        if (tamanho == 1){
            quantidade = b-a+1;
        }
        else{
            for (int i=a; i<=b/2; i++){
                long long int resp = binary(i,tamanho, b, tamanho);
                if (resp <= 1) break;
                else{
                    if (resp == 3) quantidade += tamanho;
                    if (resp == 2) quantidade++;
                    quantidade%=998244353;
                    //quantidade += 1 *(binpow(i,resp-2,998244353)-1)/(resp-3)%998244353;// binpow(resp-2, quantidade, 998244353) %998244353;
                    //cout << i << " " << resp << endl;
            
                }
            }
        }
        //cout << "////\n";

        cout << tamanho << " " << quantidade << endl;

    }
}