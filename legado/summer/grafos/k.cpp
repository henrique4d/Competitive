#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;


const ll MAXN = 1e5+ 10;
vector<ll> filhos[MAXN];

ll pai[MAXN];
ll altura[MAXN];
pair<ll,ll> tour[MAXN];


pair<ll,ll> st[4*MAXN];
ll lazy[4*MAXN];

// pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
//     if (a.first < b)
// }
vector<ll> a;

vector<ll> ind;

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    if (a > b){
        return a;
    }
    return b;
}

void push(ll v){
    st[2*v].first += lazy[v];
    lazy[2*v] += lazy[v];

    st[2*v+1].first += lazy[v];
    lazy[2*v+1] += lazy[v];

    lazy[v] = 0;

}

void build(ll v, ll tl, ll tr){
    st[v] = {0,0};
    lazy[v] = 0;
    if (tl == tr){
        st[v].first = a[tl];
        st[v].second = ind[tl];
        return;
    }
    ll tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = combine(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if (l > r) return;
    // cout << "chamando update " << tl << " " << tr << " " << l << " " << r << " " << x << endl;
    if (tl == l and tr == r){
        st[v].first += x;
        lazy[v] += x;
        //cout << "subtraindo 1 " << tl  << " " << tr << " " << st[v].first  << endl;
        return;
    }
    push(v);
    ll tm = tl + (tr-tl)/2;
    update(2*v, tl, tm, l, min(tm, r), x);
    update(2*v+1, tm+1, tr, max(tm+1, l),r, x);

    st[v] = combine(st[2*v], st[2*v+1]);
}

pair<ll,ll> query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r){
        return {INT_MIN, 0};
    }

    if (tl == l and tr == r){
        return st[v];
    }
    push(v);
    ll tm = tl + (tr-tl)/2;

    return combine( query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(tm+1, l),r));
}



void dfs(ll u, ll h, ll &cont){
    altura[u] = h;
    tour[u].first = cont;

    a.push_back(altura[u]);
    ind.push_back(u);
    for (ll v:filhos[u]){
        cont++;
        dfs(v, h+1, cont);
    }
    tour[u].second = cont;
}

int main(){

    int n, k;
    cin >> n >> k;
    ll x;
    
    for (int i=1; i<n; i++){
        cin >> x;
        x--;
        filhos[x].push_back(i);
        pai[i] = x;
    }

    ll aux = 0;

    dfs(0,1, aux);
    build((ll)1,(ll)0,n-1);
    ll resp =0;
    // for (int i=0; i<n; i++){
    //     cout << i << " " << altura[i] << " " << tour[i].first << " " << tour[i].second << endl;
    // }

    while (k--){
        pair<ll,ll> best = query((ll)1,(ll)0,n-1,(ll)0,n-1);
        
        //cout << k << " " << best.first << " " << best.second << endl;
        
        resp += best.first;
        
        int atual = best.second;

        //cout << "comecando os updates\n";
        for (int i=0; i<best.first; i++){
            //cout << atual << " " << tour[atual].first << " " << tour[atual].second << endl;
            update((ll)1,(ll)0,n-1, tour[atual].first, tour[atual].second, (ll)-1);
            atual = pai[atual];
        }
//       cout << "////////\n";
    }

    cout << resp << endl;
    return 0;
}