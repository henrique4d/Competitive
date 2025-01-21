#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e4+10;

vector<pair<ll,ll>> adj[MAXN];


bool dijkstra(ll start, ll end, ll limit, ll maximo){
    vector<bool> visited(MAXN, 0);
    if (start == end) return true;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,start});
    while (!pq.empty()){
        ll dist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (u == end){
            return -dist <= maximo;
        }
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v,w] :adj[u]){
            if (w <= limit) pq.push({dist-w,v});
        }
    }
    return false;
}

ll dijkstra2(ll start, ll end, ll limit, ll maximo){
    vector<bool> visited(MAXN, 0);
    if (start == end) return true;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,start});

    while (!pq.empty()){
        ll dist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (u == end){
            return dist;
        }
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v,w] :adj[u]){
            if (w <= limit) pq.push({dist-w,v});
        }
    }
    return false;
}


int main(){
    ll n,arestas,maximo;
    cin >> n >> arestas >> maximo;

    for (ll i=0; i<arestas; i++){
        ll a,b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    ll dist_maxima = -dijkstra2(1,n,(ll)1e9,(ll)1e9);
    
    dist_maxima = dist_maxima + (long double)maximo*(long double)dist_maxima/100.00;


    ll l = -1;
    ll r = 1e9;

    while (r-l > 1){
        ll m = l + (r-l)/2;
        // cout << m << " " << dijkstra(1, n, m, dist_maxima) << endl;
        if (dijkstra(1, n, m, dist_maxima)) r = m;
        else l = m;
    }
    cout << r << endl;

}