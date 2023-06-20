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
 
ll T,N,M,K;
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int menor = INT_MAX;
    int maior = 0;

    long double best_ratio = 0;

    for (int i=0; i<n; i++){
        cin >> v[i].first;
        cin >> v[i].second;
        menor = min(menor, v[i].first);
        maior = max(maior, v[i].first);
    }

    for (int i=0; i<n; i++){
        if (v[i].first - menor)
            best_ratio = max(best_ratio, (long double) v[i].second/(v[i].first - menor));

        if (maior - v[i].first)
            best_ratio = max(best_ratio, (long double) v[i].second/(maior - v[i].first));
    }

    //best_ratio = 180.0*best_ratio/acos(-1);
    
    
    long double resp = atan(best_ratio);

    resp = resp*180/acos(-1);

    cout << fixed << setprecision(15) << resp << endl;

}
 
int main() {
 
	optimize;
	
	T = 1;
	
	//cin >> T;
 
    while(T--) {
		solve();
    }
 
	return 0;
}