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

vector<int> d;

void bfs(vector<int>* adj, int n, int start=0, int end=-1)
{
    d.assign(n, INF);

    d[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cNode = q.front();
        q.pop();
        if(cNode == end) return;
        
        for(auto nNode: adj[cNode]) if(d[nNode] == INF)
        {
            q.push(nNode);
            d[nNode] = d[cNode]+1;
        }
    }
}

void solve(ll tt)
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> adj[n];
    int u, v;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxDist = 0;
    for(int i = 0 ; i < n ; i++)
    {
        bfs(adj, n, i);
        for(int j = 0 ; j < n ; j++)
            maxDist = max(maxDist, d[j]); 
    }
    int ans = max(2*k+2-(maxDist+1), 0);
    cout << ans << " " << ans << endl;
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