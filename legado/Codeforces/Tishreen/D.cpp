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


int girl[20];
int best = 0;
vector<int> masks;

void backtracking(vector<bool> &v, int pos){
    //cout << best << endl;
    if (pos == v.size()){
        int resp = -1;
        int cont = 0;
        f(i,0,v.size()){
            if (v[i]){
                cont++;
                //cout << i << " entrou aqui " << resp << " " << masks[i] << endl;
                if (resp == -1){
                    
                    resp = masks[i];
                    //cout <<"mascara apos ser setada pela primeira vez " << resp << endl;
                } 
                else
                    resp = (resp&masks[i]);
        
            }
        }
        //cout << resp << endl;
        int aux = __popcount(resp);
     
        if (resp != -1)
            best = max(best, aux);
   
        return;
    }    
    backtracking(v, pos+1);
    
    v[pos] = true;
    
    backtracking(v, pos+1);

    v[pos] = false;
    return;
}


int main(){
    int z;
    scanf("%d", &z);

    while(z--){
        int p, n;
        
        scanf("%d %d", &p,&n);
        int a,b;
        masks.resize(0);
        masks.resize(p,0);
        f(i,0,n){
            scanf("%d %d", &a,&b);
            a--;
            b--;
            masks[a] = (masks[a] | (1<<b));
            cout << "a nova mascara e " << masks[a] << endl;
        }
        vector<bool> aux(p, false);
        best = 0;
        backtracking(aux, 0);
        printf("%d\n", best);
    }
}