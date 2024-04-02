#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e5+10;
pair<ll,ll> a[MAXN];
ll h[MAXN];
ll n;

bool maior(ll a, ll b, ll c, ll d){
    return a*d > b*c;
}

int main(){
    set<ll> s;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].first;
        h[i] = a[i].first;
        a[i].first*=-1;
        a[i].second = i;

    }
    sort(a, a+n);

    ll respnum = 0;
    ll respdem = 1;

    for (auto [_,c]:a){    
        auto it = s.insert(c).first;
        int i = c;
        if (it != s.begin()){
            auto itprev = it;
            itprev--;
            int j = *itprev;

            ll num = (h[j] - h[j+1])*(i-j-1) + h[i] - h[j+1];
            ll den = h[j] - h[j+1];
            ll g = __gcd(num, den);
            num/=g;
            den/=g;
            if (maior(num, den, respnum, respdem)){
                respnum = num;
                respdem = den;
            }
        }
        auto itnext = it;
        itnext++;
        if (itnext != s.end()){
            int j = *itnext;

            ll num = (h[j] - h[j-1])*(j-i-1) + h[i] - h[j-1];
            ll den = h[j] - h[j-1];
            ll g = __gcd(num, den);
            num/=g;
            den/=g;
            if (maior(num, den, respnum, respdem)){
                respnum = num;
                respdem = den;
            }
        }
    }

    if (respdem == 1){
        cout << respnum << endl;
    }
    else{
        cout << respnum << "/" << respdem << endl;
    }

}