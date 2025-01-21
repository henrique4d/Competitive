#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"


const ll MAXN = 2e5+10;
ll a[MAXN];
ll proximo[MAXN];
int n;

void init(){
    for (int i=0; i<n+10; i++){
        a[i] = 0;
        proximo[i] = i+1;
    }
}

void solve(){
    cin >> n;
    init();
    ll resp = 0;
    multiset<ll> ms;
    
    list<ll> li;
    vector<list<ll>::iterator> iter(n+10);

    for (int i=0; i<n; i++){
        cin >> a[i];
        iter[i] = li.emplace(li.end(), a[i]);

        resp = max(resp,a[i]);
        ms.insert(a[i]);
    }

    iter[n] = li.emplace(li.end(),0);

    ms.insert(0);
    
    cout << resp << endl;
    int q;
    cin >> q;
    ll open;
    
    
    while (q--){
        cin >> open;
        open--;
        auto it = iter[open];
        auto it2 = it;
        it2++;

        
        
        if (it2 != iter[n]){
            ms.erase(ms.find(*it2));
            *it2 += *it;
            ms.insert(*it2);
            
            resp = max(resp,*it2);
        }
        
        ms.erase(ms.find(*it));
        li.erase(it);

        cout << *ms.rbegin() << endl;

    }

}

int main(){
    optimize
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}