#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll c,d;
    string a,b;

    cin >> a >> b >> c >> d;
    

    for (ll i = 1; i< ((ll)1<<a.size()); i++){
        string s;
        multiset<char> remove;
        for (int j=0; j<a.size(); j++){
            if (i&((ll)1<<j)){
                s.push_back(a[j]);
            }
            else{
                remove.insert(a[j]);
            }
        }
        ll aux = atoll(s.c_str());
        ll daux = d;
        ll caux = c;
        ll g = __gcd(aux,c);
        aux/=g;
        caux/=g;

        g = __gcd(d,c);
        aux/=g;
        daux/=g;

        if ((aux*d) % c == 0){
            ll aux2 = (aux*d)/c;
            string s2 = to_string(aux2);
            bool possible = true;
            ll l = 0;
            for (int k=0; k<b.size(); k++){
                if (l < s2.size() and s2[l] == b[k]){
                    l++;
                }
                else if(remove.find(b[k]) != remove.end()){
                    remove.erase(remove.find(b[k]));
                }
                else{
                    possible = false;
                }
            }
            if (!remove.empty()) possible = false;

            if (possible){
                cout << "possible\n";
                cout << s << " " << s2 << endl;
                return 0;
            }
        }

    }

    cout << "impossible\n";
}