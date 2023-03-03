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



int main(){
    int z;
    scanf("%d", &z);

    while (z--){
        
        long long int n;
        scanf("%lli", &n);
        vector<long long int> quantidades(n);
        //cout << n << endl;
        f(i,0,n) scanf("%lli", &quantidades[i]);

        //return 0;
        vector<long long int> consumidaores(n);
        vector<long long int> acumulado(n);
     
        f(i,0,n){
            scanf("%lli", &consumidaores[i]);
            acumulado[i] = consumidaores[i];
            //cout << acumulado[i] << endl;
            if (i) acumulado[i] += acumulado[i-1];
            //cout << acumulado[i] << endl;
            //cout << "////////\n";
        }

        // f(i,0,n){
        //     cout << quantidades[i] << " ";
        // }        
        // cout << endl;


        // f(i,0,n){
        //     cout << consumidaores[i] << " ";
        // }        
        // cout << endl;

        // f(i,0,n){
        //     cout << acumulado[i] << " ";
        // }        
        // cout << endl;

        vector<long long int> dosesTotais(2*n,0);
        vector<long long int> restos(2*n,0);
        f(i,0,n){
            long long int prev = 0;
            if (i) prev = acumulado[i-1];
            auto it = lower_bound(acumulado.begin(), acumulado.end(), quantidades[i] + prev);
            
            dosesTotais[i] += 1;
            dosesTotais[ it-acumulado.begin()] -= 1;
            
            restos[it-acumulado.begin()] +=  quantidades[i] + prev;

            if (it != acumulado.begin() ) restos[it-acumulado.begin()] -= *(it-1); 
            // cout << quantidades[i] - prev << " " << *(it-1) << endl;
            // cout << i <<"  " <<  restos[it-acumulado.begin()] << endl;;
        }
        // f(i,0,n){
        //     cout << dosesTotais[i] << " ";
        // }
        // cout << endl;
        
        // f(i,0,n){
        //     cout << restos[i] << " ";
        // }
        // cout << endl;
        long long int cont = 0;
        f(i,0,n){
            cont += dosesTotais[i];
            long long int resp = cont*consumidaores[i] + restos[i];
            if (i) cout << " ";
            cout << resp;
        }
        cout << "\n";
    }
}
