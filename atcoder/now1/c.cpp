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
 
#define mod 1000000007LL
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */
 
int T;
const int MAXN = 2e5+10;
ll v[MAXN];

void solve() {
    ll n;
    cin >> n;
    ll media = 0;
    //long double media = 0;
    for (ll i=0; i<n; i++){
        cin >> v[i];
        media += v[i];
    }
    //media/=n;
    ll media_l = media/n;
    ll media_u = (media + n -1)/n;
    ll resp = 0;
    //cout << fixed << setprecision(10) << media << " " << media_l << " " << media_u << endl;
    int cont_l = 0;
    int cont_u = 0;
    ll resp_l = 0;
    ll resp_u = 0;
    for (ll i=0; i<n; i++){
        if (v[i] < media_l){
            resp += media_l - v[i];
            cont_l++;
            resp_l += media_l - v[i];
            
        } 
        if (v[i] > media_u){
            resp += v[i] - media_u;
            cont_u++;
            resp_u += v[i] - media_u;
            
        }
    }
    //cout << resp << " " << resp_l << " " << resp_u << endl;
    resp += abs(resp_l - resp_u);
    resp = (resp+1)/2;
    cout << resp << endl;
}
 
int main() {
 
	// optimize;
	
	T = 1;
	
	//cin >> T;
 
    while(T--) {
		solve();
    }
 
	return 0;
}