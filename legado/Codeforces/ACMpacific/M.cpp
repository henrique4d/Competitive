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
    int n,m;
    cin >> n >> m;

    vector<vector<char>> mapa(n, vector<char>(m));

    vector<vector<bool>> used(n, vector<bool>(m, false));
    int v[8][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> mapa[i][j];
        }
    }

    queue<pair<int,int>> to_process;

    for (int i=0; i<n; i++){
        if (mapa[i][0] == '.' and !used[i][0])
        {
            used[i][0] = true;
            to_process.push({i,0});
        }
        if (mapa[i][m-1] == '.' and !used[i][m-1])
        {
            used[i][m-1] = true;
            to_process.push({i,m-1});
        }
    }
    for (int i=0; i<m; i++){
        if (mapa[0][i] == '.' and !used[0][i])
        {
            used[0][i] = true;
            to_process.push({0,i});
        }
        if (mapa[n-1][i] == '.' and !used[n-1][i])
        {
            used[n-1][i] = true;
            to_process.push({n-1,i});
        }
    }
    while (!to_process.empty()){    
        int x,y;
        x = to_process.front().first;
        y = to_process.front().second;
        to_process.pop();
        for (int k=0; k<8; k++){
            int x1 = x+v[k][0];
            int y1 = y+v[k][1];
            if (x1 < 0 or y1 < 0 or x1>=n or y1 >=m) continue;

            if (v[k][0] == 1 and v[k][1] == 1){
                if ( mapa[x+1][y] == '/' or mapa[x][y+1] == '/') continue;
            }
            if (v[k][0] == -1 and v[k][1] == -1){
                if ( mapa[x-1][y] == '/' or mapa[x][y-1] == '/') continue;
            }
            if (v[k][0] == 1 and v[k][1] == -1){
                if ( mapa[x+1][y] == '\\' or mapa[x][y-1] == '\\') continue;             
            }
            if (v[k][0] == -1 and v[k][1] == 1){
                if ( mapa[x-1][y] == '\\' or mapa[x][y+1] == '\\') continue;
                
            }

            

            if (x1 > 0 and y1 > 0 and x1<n and y1 < m and mapa[x1][y1] == '.' and !used[x1][y1]){
                used[x1][y1] = true;
                to_process.push({x1,y1});        
            }
        }
        
    }
    int cont = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //cout << i << " " << j << " " << cont << endl;
            if (mapa[i][j] == '/' and i<n-1 and j<m-1){
                if (mapa[i+1][j] == '\\' and mapa[i][j+1] == '\\' and mapa[i+1][j+1] == '/'){
                    cont++;
                }
            }
            if (mapa[i][j] == '.' and !used[i][j]){
                cont++;
                used[i][j] = true;
                to_process.push({i,j});
            }

            while (!to_process.empty()){    
                int x,y;
                x = to_process.front().first;
                y = to_process.front().second;
                to_process.pop();
                for (int k=0; k<8; k++){
                    if (v[k][0] == 1 and v[k][1] == 1){
                        if ( mapa[x+1][y] == '/' or mapa[x][y+1] == '/') continue;
                    }
                    if (v[k][0] == -1 and v[k][1] == -1){
                        if ( mapa[x-1][y] == '/' or mapa[x][y-1] == '/') continue;
                    }
                    if (v[k][0] == 1 and v[k][1] == -1){
                        if ( mapa[x+1][y] == '\\' or mapa[x][y-1] == '\\') continue;             
                    }
                    if (v[k][0] == -1 and v[k][1] == 1){
                        if ( mapa[x-1][y] == '\\' or mapa[x][y+1] == '\\') continue;
                        
                    }
                    int x1 = x+v[k][0];
                    int y1 = y+v[k][1];

                    if (x1 > 0 and y1 > 0 and x1<n and y1 < m and mapa[x1][y1] == '.' and !used[x1][y1]){
                        used[x1][y1] = true;
                        to_process.push({x1,y1});        
                    }
                }
            }
        }
    }
    cout << cont << endl;
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