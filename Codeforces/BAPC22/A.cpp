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
    ll n,k,x;
    cin >> n >> k >> x;

    ll sum = 0;
    ll should_be = x*(n-k);
    vector<ll> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
        sum+=v[i];
    }

    long double best_resp = abs((long double)sum/n - x);
       
    if (k >= 1){
        should_be = x*(n-1);
        for (int i=0; i<n; i++){
            sum -= v[i];
            if ( abs((long double) (sum)/(n-1) - x) < best_resp){
                best_resp = abs((long double) (sum)/(n-1) - x);
            }
            sum+=v[i];
        }
    }
    if (k >= 2){
        should_be = x*(n-2);
        for (int i=0; i<n; i++){
            sum -= v[i];
            for (int j=i+1; j<n; j++){
                sum -= v[j];
                if ( abs((long double) (sum)/(n-2) - x) < best_resp ){
                    best_resp = abs((long double) (sum)/(n-2) - x);
                }
                sum += v[j];
            }
            
            sum+=v[i];
        }
    }

    if (k >= 3){
        should_be = x*(n-3);
        set<ll> left;
        ll expected = sum - should_be;
        for (int i=1; i<n; i++){
            if (i > 1){
                auto it = left.lower_bound(expected - v[i]);
                if (it != left.end()){
                    sum -= *it;
                    sum -= v[i];
                    if ( abs((long double) (sum)/(n-3) - x) < best_resp){
                        best_resp = abs((long double) (sum)/(n-3) - x);
                    }
                    sum += *it;
                    sum += v[i];
                }       
                if (it != left.begin()){
                    it--;
                    sum -= *it;
                    sum -= v[i];
                    if ( abs((long double) (sum)/(n-3) - x) < best_resp ){
                        best_resp = abs((long double) (sum)/(n-3) - x);
                    }
                    sum += *it;
                    sum += v[i];
                }
            }
            for (int j=0; j<i; j++){
                left.insert(v[i] + v[j]);
            }
        }
    }

    if (k >= 4){
        should_be = x*(n-4);
        set<ll> left;
        ll expected = sum - should_be;
        for (int i=1; i<n; i++){
            for (int j=i+1;j<n; j++){
                sum -= v[j];
                expected -= v[j];
                if (i > 1){
                    auto it = left.lower_bound(expected - v[i]);
                    if (it != left.end()){
                        sum -= *it;
                        sum -= v[i];
                        if ( abs((long double) (sum)/(n-4) - x) < best_resp ){
                            best_resp = abs((long double) (sum)/(n-4) - x);
                        }
                        sum += *it;
                        sum += v[i];
                    }     
                    if (it != left.begin()){
                        it--;
                        sum -= *it;
                        sum -= v[i];
                        if ( abs((long double) (sum)/(n-4) - x) < best_resp ){
                            best_resp=abs((long double) (sum)/(n-4) - x);
                        }
                        sum += *it;
                        sum += v[i];
                    }
                }
                sum += v[j];
                expected += v[j];
            }
            for (int j=0; j<i; j++){
                left.insert(v[i] + v[j]);
            }           
        }
    }

    cout << fixed << setprecision(15) << best_resp << endl;
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