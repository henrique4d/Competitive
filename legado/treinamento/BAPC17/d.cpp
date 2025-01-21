#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MAX = 2e5+10;
vector<pair<ll, ll>> g[MAX];
ll from[MAX];
bool visited[MAX];
bool visited2[MAX];


int main(){
    ll n,m;
    cin >> n >> m;
    ll u,v,w, p;
    set<pair<ll,ll>> forbiden;
    
    bool direct = false;

    for (ll i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }


    priority_queue<pair<ll,pair<ll,ll>>> pq;

    pq.push({0,{1,-1}});
    ll menor_dist;

    bool term = false;
    while(!pq.empty()){
        u = pq.top().second.first;
        p = pq.top().second.second;
        w = pq.top().first;
        
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        forbiden.insert({u,p});
        for (auto [v,d]:g[u]){
            if (!visited[v]){
                pq.push({w-d, {v, u}});
            }
        }
    }

    priority_queue<pair<ll,pair<ll,ll>>> q;

    q.push({0,{0,-1}});

    vector<ll> resp;
    // for (auto it = forbiden.begin(); it!= forbiden.end(); it++){
    //     cout << (*it).first << " " << (*it).second << endl;
    // }
    // cout << endl;

    while (!q.empty()){
        u = q.top().second.first;
        p = q.top().second.second;
        w = q.top().first;

        q.pop();
        //cout << u << " " << p << " " << w << endl;
        if (visited2[u]) continue;
        visited2[u] = true;
        from[u] = p;
        if (u == 1){
            ll atual = from[u];
            resp.push_back(1);
            while (atual != 0){
                resp.push_back(atual);
                atual = from[atual];
            }
            break;
        }

        for (auto [v,d]:g[u]){
        
            if (!visited2[v] and forbiden.find({u,v}) == forbiden.end()){
                q.push({w-d, {v, u}});
            }
        }
    }

    if (resp.size() == 0){
        cout << "impossible\n";
        return 0;
    }
    
    resp.push_back(0);
    cout << resp.size() << " ";

    for (auto it = resp.rbegin(); it!=resp.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

}