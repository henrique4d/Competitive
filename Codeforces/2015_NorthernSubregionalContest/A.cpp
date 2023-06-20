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
ifstream in("black.in");
ofstream out("black.out");
 
void solve() {
    
    int b, w;
    in >> b >> w;

    char resp[max(b,w)*2][2];

    for (int i=0; i<max(b,w)*2; i++){
        if (i%2) resp[i][0] = '.';
        else resp[i][0] = '@';
    }

    int contb = max(b,w);
    int contw = max(b,w);


    for (int i=0; i<max(b,w)*2; i++){
        if (resp[i][0] == '.'){
            if (contb > b){
                contb--;
                resp[i][1] = '@';
            }
            else resp[i][1] = '.';
        }
        if (resp[i][0] == '@'){
            if (contw > w){
                contw--;
                resp[i][1] = '.';
            }
            else resp[i][1] = '@';
        }
    }
    out << "2 ";
    if (b > w ) out << max(b,w)*2 -1 << endl;
    else out << max(b,w)*2 << endl;
    for (int i=0; i<max(b,w)*2; i++){
        if (i == max(b,w)*2 - 1 and b > w) continue;
        out << resp[i][0];
    }
    out << endl;
    for (int i=0; i<max(b,w)*2; i++){

        if (i == max(b,w)*2 - 1 and b > w) continue;
        out << resp[i][1];
    }
    out << endl;


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