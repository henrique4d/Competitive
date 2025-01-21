#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<long long int,long long int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRlong long long long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,long long int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,long long int b) { if (a>b) return a; return b; }
// ll max(long long int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"Yes\n"; }
void no() { cout<<"No\n"; }


bool dfs(vector<vector<char>> &m, vector<vector<int>> &cont, int i, int j, int n, int k, int atual, int ip, int jp){
    if (i < 0 or j < 0 or i >= n or j >= k ) return false;

    cont[i][j] = atual;
    if (i-1 >= 0  and i-1 != ip){
        if (m[i-1][j] == m[i][j]){
            if (cont[i-1][j] == -2){
                if (dfs(m,cont, i-1, j, n,k,atual+1, i, j)) return true;
            }
            else{
                return true;
            }
        }
    }


    if (i+1 < n and i+1 != ip){
        if (m[i+1][j] == m[i][j] ){
            if (cont[i+1][j] == -2){
                if (dfs(m,cont, i+1, j, n,k,atual+1, i, j)) return true;
            }
            else{
                return true;
            }
        }
    }


    if (j-1 >= 0 and j-1 != jp){
        if (m[i][j-1] == m[i][j] ){
            if (cont[i][j-1] == -2){
                if (dfs(m,cont, i, j-1, n,k,atual+1, i, j)) return true;
            }
            else{
                return true;
            }
        }
    }




    if (j+1 < k and j+1 != jp){
        if (m[i][j+1] == m[i][j]){
            if (cont[i][j+1] == -2){
                if (dfs(m,cont, i, j+1, n,k,atual+1, i, j)) return true;
            }
            else{
                return true;
            }
        }
    }


    return false;
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<char>> m(n, vector<char>(k));

    vector<vector<int>> cont(n, vector<int>(k, -2));

    f(i,0,n){
        f(j,0,k){
            cin >> m[i][j];
        }
    }

    f(i,0,n){
        f(j,0,k){
            if (cont[i][j] == -2 and dfs(m,cont, i,j,n,k,0,-5,-5)){
                //cout << i << " " << j << endl;
                yes();
                return 0;
            }
        }
    }
    no();
}