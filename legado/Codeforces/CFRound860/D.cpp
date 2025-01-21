#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
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

int main(){
    int z;
    cin >> z;
    while(z--){
        int n;
        cin >> n;
        vector<ll> pos;
        vector<ll> neg;
        ll aux;
        ll maior = 0;
        ll menor = 0;
        ll parametro;       
        for (int i=0; i<n; i++){
            cin >> aux;
            if (aux >= 0) pos.push_back(aux);
            else neg.push_back(aux);

            maior = max(maior,aux);
            menor = min(menor,aux);
        }
        parametro = maior-menor;
        sort(all(pos));
        reverse(all(pos));
        sort(all(neg));
        ll val_atual = 0;

        int indexPos = 0;
        int indexNeg = 0;
        vector<ll> resp;
        while (true){

            if (indexPos == pos.size()){
                while (indexNeg < neg.size()){
                    val_atual += neg[indexNeg];
                    resp.pb(neg[indexNeg]);
                    indexNeg++;
                    if ( abs(val_atual) >= parametro){
                        no();
                        goto here;
                    }   
                }
                break;
            }

            if (indexNeg == neg.size()){
                while (indexPos < pos.size()){    
                    val_atual += pos[indexPos];
                    resp.pb(pos[indexPos]);
                    indexPos++;
                    if ( abs(val_atual) >= parametro){
                        no();
                        goto here;
                    }
                }
                break;
            }
            if (val_atual < 0){
                val_atual += pos[indexPos];
                resp.pb(pos[indexPos]);
                indexPos++;
                if ( abs(val_atual) >= parametro){
                    no();
                    goto here;
                }
            }
            else{
                val_atual += neg[indexNeg];
                resp.pb(neg[indexNeg]);
                indexNeg++;
                if ( abs(val_atual) >= parametro){
                    no();
                    goto here;
                }
            }

        }
        
        yes();
        for (int i=0; i<resp.size(); i++){
            if (i) cout << " ";
            cout << resp[i];
        }
        cout << endl;
        here:
        int asuhdfhausdf;
    }    

    return 0;
}