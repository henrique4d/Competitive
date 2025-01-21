#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll s, p, e, a;
    ll t = 0;
    priority_queue<ll> pq;
    ll resp = 0;
    for (int i=0; i<n; i++){
        cin >> s >> p >> e >> a;
        if (s - t >= a){
            t += a + p - s;
            pq.push(a + p - e);
        }
        else if (!pq.empty() and s - t + pq.top() >= a){
            t += a + p - s;
            pq.push(a + p - e);

            t -= pq.top();
            pq.pop();    
        }
        else{
            t += e -s;
        }
        resp = max(resp, (ll)pq.size());
    }
    cout << resp << endl;
}