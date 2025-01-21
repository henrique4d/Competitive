#include <bits/stdc++.h>
using namespace std;
typedef int ll;

#define mod 1000000007
#define INF 1000000

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
const ll MAXN = 2e5+10;
vector<ll> g[MAXN];
ll in_degree[MAXN];
ll n,m,a,b;


pair<ll,ll> st[4*MAXN];
ll lazy[4*MAXN];

void push(ll v){
    st[2*v].first += lazy[v];
    st[2*v+1].first += lazy[v];

    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];

    lazy[v] = 0;
}

void build(ll v, ll tl, ll tr){
    lazy[v] = 0;
    if (tl == tr){
        st[v] = {in_degree[tl], tl};
        return;
    }
    ll tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = min(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
    if (l > r) return;
    if (l == tl and r == tr){
        st[v].first += add;
        lazy[v] += add;
        return;
    }
    push(v);

    ll tm = tl + (tr - tl)/2;
    update(2*v, tl, tm, l, min(r,tm), add);
    update(2*v+1, tm+1, tr, max(l, tm+1), r, add);

    st[v] = min(st[2*v], st[2*v+1]);
}



pair<ll,ll> query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return {INF, INF};
    if (l == tl and r == tr) return st[v];
    push(v);
    ll tm = tl + (tr-tl)/2;
    return min( query(2*v, tl, tm, l, min(r,tm) ), query(2*v+1, tm+1, tr, max(l, tm+1), r) );
}




void init(){
    for (ll i=0; i<n+10; i++){
        g[i].clear();
        in_degree[i] = i-1;
    }
}

void solve(){
    cin >> n >> m;
    init();
    multiset<pair<int,int>> arestas;

    priority_queue<ll> pq;
    pq.push(1);
    in_degree[1] = INF;

    for (ll i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        in_degree[b]--;

        arestas.insert({a,b});

        if (in_degree[b] == 0){
            pq.push(b);
            in_degree[b] = INF;
        }
    }
    in_degree[0] = INF;
    build(1, 0, n);

    while (!pq.empty()){
        ll u = pq.top();
        cout << u << " ";
        pq.pop();
        update(1,0,n,u,u,INF);
        update(1,0,n,u+1,n,-1);
        for (auto v:g[u]){
            update(1,0,n,v,v,1);
        }
        pair<ll,ll> aux;
        do{
            aux = query(1,0,n,1,n);
            if (aux.first == 0){
                pq.push(aux.second);
                update(1,0,n,aux.second, aux.second, INF);
            }
        }while (aux.first == 0);
    }
    cout << endl;
}


int main(){
    optimize
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}