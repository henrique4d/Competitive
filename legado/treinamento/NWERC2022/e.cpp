#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e6+10;
vector<ll> adj[MAXN];


int main(){
    string s;
    cin >> s;
    ll a = -1,b = -1;
    string aux = "";

    for (char c:s){
        if (c == '/'){
            a = atoi(aux.c_str());
            aux = "";
        }
        else{
            aux.push_back(c);
        }
    }
    b = atoi(aux.c_str());

    
    // cout << a << " " << b << endl;
    
    
    ll atual = 0;
    ll tam = 1;
    ll limite = (a+b-1)/b;
    for (int i=1; i<= limite; i++){
        adj[i].push_back(i+1);
        atual += i;
        tam++;
    }

    ll v = limite+2;

    // cout << atual << " " << tam << " " << limite << endl;
    while(true){
        // cout << atual << " " << tam << endl;
        if (b*atual == a*tam) break;
        if (b*atual < a*tam){
            adj[limite].push_back(v);
            atual += limite;
            tam++;
        }
        else{
            if (limite -1 <= 0){
                cout << "impossible\n";
                return 0;
            }
            adj[limite-1].push_back(v);
            atual += limite-1;
            tam++;
        }
        v++;

        // if (v > 1000005){
        //     cout << "impossible\n";
        //     return 0;
        // }    
    }

    vector<pair<ll,ll>> edges;
    for (int i=1; i<=limite; i++){
        for (auto v:adj[i]){
            edges.push_back({i,v});
        }
    }

    cout << tam << " " << edges.size() << endl;
    for (int i=0; i<edges.size(); i++){
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;   
}