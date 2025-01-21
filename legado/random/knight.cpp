#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAXN = 3e5+10;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

int seg[4*MAXN];
int n;
int lazy[4*MAXN];

void push(int v){
    if (seg[2*v] == INF) seg[2*v] = min(seg[2*v], lazy[v]);
    if (seg[2*v+1] == INF) seg[2*v+1] = min(seg[2*v+1], lazy[v]);
    if (lazy[2*v] == INF) lazy[2*v] = min(lazy[2*v], lazy[v]);
    if (lazy[2*v+1] == INF) lazy[2*v+1] = min(lazy[2*v+1], lazy[v]);
    lazy[v] = INF;
}

void build (int v, int tl, int tr){
    lazy[v] = INF;
    if (tl==tr){
        seg[v] = INF;
        return;
    }
    int mid = tl + (tr - tl)/2;
    build(2*v,tl,mid);
    build(2*v+1,mid+1,tr);
    seg[v] = min(seg[2*v],seg[2*v+1]);
}
void update(int v, int tl, int tr, int l, int r, int x){
    if (l > r) return;
    if (l == tl and r == tr){
        if (seg[v] == INF) seg[v] = min(seg[v],x);
        if (lazy[v] == INF) lazy[v] = min(lazy[v],x);
        return;
    }
    push(v);
    int mid = tl + (tr - tl)/2;
    update(2*v,tl,mid,l,min(mid,r),x);
    update(2*v+1,mid+1,tr,max(l,mid+1),r,x);
    seg[v] = min(seg[2*v],seg[2*v+1]);
}
int query(int v, int tl, int tr, int l, int r){
    if (l > r) return INF;
    if (l == tl and r == tr)
        return seg[v];
    
    push(v);
    int mid = tl + (tr - tl)/2;
    return min(query(2*v,tl,mid,l,min(mid,r)),query(2*v+1,mid+1,tr,max(l,mid+1),r));
}

void solve(){
    int n,m;
    int a,b,c;
    cin >> n >> m;

    
    build(1,0,n-1);
    for (int i=1;i<=m;i++){
        cin >> a >> b >> c;
        a--,b--,c--;
        update(1,0,n-1,a,c-1,c+1);
        update(1,0,n-1,c+1,b,c+1);
    }
    for (int i=0; i<n; i++){
        int val = query(1,0,n-1, i,i);
        if (val == INF) cout << 0 << " ";
        else cout << val << " ";
    }
    cout << endl;
  
}





int main (){
    
    //optimize;

    ll t;
    t = 1;

    //cin >> t;
    while(t--){
        solve();
    }    
    return 0;
}