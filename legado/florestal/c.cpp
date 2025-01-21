#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const ll MAXN = 2e5+10;
pair<ll,ll> a[MAXN];

int main(){
    ll INFLL = 2e18;
    INFLL += 10;

    ll n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    a[n].first = INFLL;
    
    int i = 0;
    ll tempo = 1;
    priority_queue<ll> pq;
    pq.push(-(INFLL));
    ll ans = 0;

    while (tempo != INFLL){
        while (a[i].first == tempo){
            pq.push(-(a[i].first + a[i].second));
            i++;
        }
        while (-pq.top() < tempo) pq.pop();    
        
        if (-pq.top() != INFLL){
            if (-pq.top() >= tempo){
                ans++;
                pq.pop();
            }
        }
        tempo = tempo+1;
        tempo = max(tempo, min({a[i].first, -pq.top()}));
    }

    cout << ans << endl;   
}