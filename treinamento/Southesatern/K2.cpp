#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200010
#define INF 1000000000
using namespace std;

int n, m;

struct Edge {
    int to, next;
} e[maxn * 2]; int c1, head[maxn];
inline void add_edge(int u, int v) {
    e[c1].to = v; e[c1].next = head[u]; head[u] = c1++;
}

int w[maxn], du[maxn];
void pre(int u, int fa) {
    bool isleaf = true; w[u] = INF;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to; if (v == fa) continue;
        isleaf = false; pre(v, u); w[u] = min(w[u], w[v]); 
    } if (isleaf) w[u] = u; 
}

vector<int> ans;
void dfs(int u, int fa, int f) {
    vector<pair<int, int>> vec;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to; if (v == fa) continue;
        vec.emplace_back(w[v], v); 
    } sort(vec.begin(), vec.end());
    if (!vec.size()) return ans.push_back(u);
    if (!f) {
        for (int i = 0; i < vec.size(); ++i) dfs(vec[i].second, u, 0);
        ans.push_back(u); 
    } else {
        for (int i = 0; i < vec.size() - 1; ++i) dfs(vec[i].second, u, 0);
        if (u > vec.back().first) dfs(vec.back().second, u, 0), ans.push_back(u);
        else ans.push_back(u), dfs(vec.back().second, u, 1); 
    }
}

void work() {
    cin >> n; fill(head + 1, head + n + 1, -1); c1 = 0; ans.clear(); 
    for (int i = 1; i <= n; ++i) du[i] = 0; 
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        add_edge(x, y); add_edge(y, x);
        ++du[x]; ++du[y];
    } int p = 0; for (int i = n; i; --i) if (du[i] == 1) p = i;
    pre(p, 0); dfs(p, 0, 1);
    for (auto u : ans) cout << u << " "; cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) work(); 
    return 0;
}