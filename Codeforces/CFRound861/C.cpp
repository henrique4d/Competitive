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
/* PRlong long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
long long int get_luck(long long int l, long long int r){
    
    long long int dif = r-l;
    long long int number_times = log10(dif);
    //cout << dif << " " << number_times << endl;
    f(i,0,number_times){
        l/=10;
        r/=10;
    }
 
    long long int maior = 0;
    long long int menor = 100;
    long long int less = 100;
    long long int resp = 0;
    //cout << l << " " << r << endl;
    for (long long int i=l; i<=r; i++){
        long long int aux = i;
        maior = 0;
        menor = 100;
        while (aux){
            maior = max(maior, aux%10);
            menor = min(menor, aux%10);
            aux/=10;
        }
        if (maior-menor < less and menor != 100){
            less = maior-menor;
            resp = i;
        }
   
        if (less == 0) break;
    }
    //cout << "resp: " << resp << endl;
 
    f(i,0,number_times){
        //cout << resp << endl;
        long long int add = resp%10;
        if (!add) add = 1;
        resp*=10;
        resp+=add;
    }
    return resp;
}
 
long long int get_luck2(long long int l, long long int r){
    
    long long int dif = r-l;
    long long int number_times = log10(dif);
    //cout << dif << " " << number_times << endl;
    f(i,0,number_times){
        l/=10;
        r/=10;
    }
    l++;
 
    long long int maior = 0;
    long long int menor = 100;
    long long int less = 100;
    long long int resp = 0;
    //cout << l << " " << r << endl;
    for (long long int i=l; i<=r; i++){
        long long int aux = i;
        maior = 0;
        menor = 100;
        while (aux){
            maior = max(maior, aux%10);
            menor = min(menor, aux%10);
            aux/=10;
        }
        if (maior-menor < less and menor != 100){
            less = maior-menor;
            resp = i;
        }
   
        if (less == 0) break;
    }
    //cout << "resp: " << resp << endl;
 
    f(i,0,number_times){
        //cout << resp << endl;
        long long int add = resp%10;
        if (!add) add = 1;
        resp*=10;
        resp+=add;
    }
    return resp;
}
 
int get_luck_orig(long long int n){
    long long int maior = 0;
    long long int menor = 100;
 
    while (n){
        maior = max(maior, n%10);
        menor = min(menor, n%10);
        n/=10;
    }
 
    return maior-menor;
}
 
 
 
int main(){
    int z;
    cin >> z;
    while(z--){
        long long int l, r;
        cin >> l >> r;
        long long int resp = get_luck(l,r);
        if (resp < l or resp > r) resp = get_luck2(l,r);       
        
        if (resp < l or resp > r){
            cout << resp/max(1,(int)(pow(10, (int)log10(resp))));

            resp = get_luck( max(1,l%((int)(pow(10, (int)log10(l))))), r% max(1,((int)(pow(10, (int)log10(r))))));
        }
        cout << resp << endl;
    }
}