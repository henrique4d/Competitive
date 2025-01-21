#include<bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
typedef long long ll;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628
#define MOD 1000000007

//------------------solution starts below------------------

ll n, maxW, maxV = 0;
vector<int> v, w;
ll DP[101][100001]; 
// i = gets some items until i-1
// j = current value of the knapsack 
// DP[i][j] stores minimum weight

ll dp(int i, int j)
{
    // cout << "chamando dp " << i << " " << j << endl;
    if (j < 0) return INF;
    if (i == 0 and j != 0) return INF;

    if(!i or !j) return 0;
    // cout << i << " " << j << " " << DP[i][j] << endl;
    if(DP[i][j] == INFLL) // If not calculated
        DP[i][j] = min(dp(i-1, j), dp(i-1, j-v[i-1])+w[i-1]); 
        // max(do not get item i-1, get item i-1)

    // cout << i << " " << j << " " << DP[i][j] << endl;
    return DP[i][j];
}

void solve(ll tt)
{
    cin >> n >> maxW;
    v.resize(n);
    w.resize(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> w[i] >> v[i];
        maxV+=v[i];
    }
    
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= maxV ; j++){
                DP[i][j] = INFLL; // Sets everything as not calculated
        }
        
    for(int j = maxV ; j >= 0 ; j--)
        if(dp(n, j) <= maxW)
        {
            cout << j << endl;
            break;
        }
}

int main()
{
    optimize;
    ll tt=1;
    //cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}