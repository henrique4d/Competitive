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

vector<int> mult[10][10];
vector<int> square[10];
vector<int> best;


bool is_possible(vector<int> & result, vector<int> &resp){
    for (int k=0; k<result.size(); k++){
        int val = 0;
        for (int i=0; i<=k; i++){
            if (i >= resp.size() or k-i >= resp.size()) continue;
            val += resp[i]*resp[k-i];
        }
        val %= 10;
        if (val != result[k] ) return false;
    }

    return true;
}


void back_tracking(vector<int> & result, vector<int> &resp, int pos, int n, int m){
    if (pos == -1){
        if (is_possible(result,resp)){
            for (int i=0; i<resp.size(); i++){
                if (resp[i] < best[i] or best[i] == -1){
                    for (int j=0; j<resp.size(); j++){
                        best[j] = resp[j];
                    }
                    break;
                }
                if (resp[i] > best[i]){
                    break;
                }
            }
        }
        return;
    }
    int aux = 0;
    for (int i=1; i <n-pos-1; i++){
        aux += resp[pos+i]*resp[n-1-i];
    }
    
    int a = 2*resp[n-1];    
    int b = result[pos + (m-n)] - aux;

    a = a%10;
    if (b < 0){
        b = 10 - abs(b)%10; 
    }
    b = abs(b)%10;

    for (auto it = mult[a][b].begin(); it!= mult[a][b].end(); it++){
        resp[pos] = *it;
        back_tracking(result, resp, pos-1, n, m);
    }


}

void solve() {
    string in;
    cin >> in;
    vector<int> result(in.size());
    vector<int> resp((in.size()+1)/2);
    int n = resp.size();

    
    best.resize(0);
    
    best.resize(resp.size(), -1);


    for (int i=0; i<in.size(); i++){
        result[i] = in[i] - '0';
    }

    for (int i=0; i<=9; i++){
        square[(i*i)%10].push_back(i);
        for (int j=0; j<=9; j++){
            mult[i][(i*j)%10].pb(j);
        }
    }

    for(auto it = square[result.back()].begin(); it!= square[result.back()].end(); it++){
        resp[n-1] = *it;
        back_tracking(result, resp, n-2, n, in.size());
    }

    if (best[0] == -1){
        cout << -1 << endl;
    }
    else{
        for (int i=0; i<n; i++){
            cout << best[i];
        }
        cout << endl;

    }
    
    return;
}
 
int main() {
 
	//optimize;
	
	T = 1;
	
	//cin >> T;
 
    while(T--) {
		solve();
    }
 
	return 0;
}