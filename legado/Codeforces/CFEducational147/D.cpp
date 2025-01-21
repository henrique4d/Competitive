
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
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    cin >> z;
    while(z--){
        ll n,k;
        cin >> n >> k;

        vector<pair<ll, ll>> seg(n);
        f(i,0,n){
            cin >> seg[i].fi;
        }
        f(i,0,n){
            cin >> seg[i].se;
        }

        ll cont_atual = 0;
        ll pos_atual = 0;
        ll index1 = 0;
        ll index2 = 0;
        ll val_atual = 0;
        ll custo_atual;

        ll best = INT_MAX;
      
        while(true){
            if (val_atual < k){
                bool att = true;
                if (index2 == n) break;
                if (k - val_atual + seg[index2].fi -1 < seg[index2].se){
                    att = false;
                }
                pos_atual = min(k - val_atual + seg[index2].fi -1, seg[index2].se);
                cont_atual++;
                val_atual += pos_atual - seg[index2].fi+1;
                custo_atual = 2*cont_atual + pos_atual;
                if (att)
                index2++;
            }
            if (val_atual >= k){
                best = min(best, custo_atual);
            }
            //cout << index1 << " " << index2 << " " << cont_atual << " " << pos_atual << " " << val_atual << " " << custo_atual << endl;

            if (val_atual >= k){
                if (index1 == n) break;
                cont_atual--;
                val_atual -= seg[index1].se - seg[index1].fi+1;
                custo_atual = 2*cont_atual + pos_atual;
                index1++;
                //pos_atual = min(k - val_atual + seg[index2-1].fi -1, seg[index2].se);
                
            }

            //cout << index1 << " " << index2 << " " << cont_atual << " " << pos_atual << " " << val_atual << " " << custo_atual << endl;


            if (val_atual >= k){
                best = min(best, custo_atual);
            }
        }
        if (best == INT_MAX ) best = -1;
        cout << best << endl;
    }
}
