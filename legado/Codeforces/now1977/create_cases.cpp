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
#define MAXN 200010
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */
 
int T;
 
void solve() {
    
    int n;
    cin >> n;
    vector<ll> v(n);
   
    ll maior = INT_MIN;
    ll menor = INT_MAX;
    
    ll pos_maior = 0;
    ll pos_menor = 0;
 
    for (int i=0; i<n; i++){
        cin >> v[i];
        if (v[i] > maior){
            maior = v[i];
            pos_maior = i;
        }
        if (v[i] < menor){
            menor = v[i];
            pos_menor = i;
        }
    }
    vector<pair <ll,ll>> resp;
    
    if ( abs(maior) >= abs(menor) ){
        for (int i=0; i<n; i++){
            if (v[i] < 0){
                v[i] += v[pos_maior];
                resp.push_back({i,pos_maior});
            }
        }
        //cout << v << endl;
        for (int i=1; i<n; i++){
            if (v[i] < v[i-1]){
                v[i] += v[i-1];
                resp.push_back({i,i-1});
            }
        }
    }
    else{
        for (int i=0; i<n; i++){
            if (v[i] > 0){
                v[i] += v[pos_menor];
                resp.push_back({i,pos_menor});
            }
            
        }
        for (int i=n-1; i>0; i--){
            if (v[i] < v[i-1]){
                v[i-1] += v[i];
                resp.push_back({i-1,i});
            }
        }
    }
    cout << resp.size() << endl;
    for (int i=0; i<resp.size(); i++){
        cout << resp[i].first+1 << " " << resp[i].second+1 << endl;
    }
    //cout << v << endl;
}
 
int main() {
    for (int i=0;)
    return;
	optimize;
	
	T = 1;
	
	cin >> T;
 
    while(T--) {
		solve();
    }
 
	return 0;
}