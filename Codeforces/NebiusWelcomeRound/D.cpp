#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<long long int, int>
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
 
long long int gcd(long long int a, long long int b, long long int& x, long long int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long int x1, y1;
    long long int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
int main(){
        long long int n,m;
        cin >> n >> m;
        char aux2 = 0;
        long long int cont = 0;
        char aux;
        vector<vector<char>> v(n, vector<char>(m));
        for (long long int i=0; i<n; i++){
            for (long long int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }

        long long int minimo = 0;
        long long int maximo = 0;
        for (long long int i=0; i<n; i++){
            long long int single = m/2;
            long long int duplo = m/4;
            for (long long int j=0; j<m; j++){
                if (v[i][j] == '1'){
                    if (j == m-1){
                        minimo++;
                    }
                    else if (v[i][j+1] == '1' and duplo){
                        duplo--;
                        j++;
                        minimo++;
                    }
                    else{
                        minimo++;
                    }
                }
            }
            //cout << i << " " <<  minimo << endl;
        }

        for (long long int i=0; i<n; i++){
            long long int single = m/2;
            long long int duplo = m/4;
            vector<bool> used(m, false);
            for (long long int j=0; j<m; j++){
                if (v[i][j] == '1'){
                    maximo++;
                    if ( j <m-1 and v[i][j+1] == '0' and duplo and !used[j] and !used[j+1]){
                        duplo--;
                        used[j] = true;
                        used[j+1] = true;
                        j++;
                    }
                }
                if (v[i][j] == '0'){
                    if ( j <m-1 and v[i][j+1] == '1' and duplo and !used[j] and !used[j+1]){
                        maximo++;
                        duplo--;

                        used[j] = true;
                        used[j+1] = true;
                        j++;
                    }
                }
                if (v[i][j] == '0'){
                    if ( j <m-1 and v[i][j+1] == '0' and duplo and !used[j] and !used[j+1]){
                        used[j] = true;
                        used[j+1] = true;
                        duplo--;
                        j++;
                    }
                }
            }
            
            maximo -= duplo;
        }
        cout << minimo << " " << maximo << endl;

        
    }
