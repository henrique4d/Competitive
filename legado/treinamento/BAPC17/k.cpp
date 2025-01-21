#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MAX = 1e3+10;
vector<ll> g[MAX];
ll visited[MAX];
vector<ll> resp;

void dfs(int u){
    visited[u] = true;
    for (auto v:g[u]){
        if (!visited[v]) dfs(v);
    }
    resp.push_back(u);
}


int main(){
    int n;
    cin >> n;
    string s;
    for (int i=0; i<n; i++){
        cin >> s;
        for (int j = i+1; j<n; j++){
            if (s[j] == '1') g[i].push_back(j);
            else g[j].push_back(i);
        }
    }
    dfs(0);
    if (resp.size() == n){
        for (auto it = resp.begin(); it!=resp.end(); it++){
            cout << *it << " ";
        }
    }
    else{
        cout << "impossible";
    }
    cout << endl;
}