#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000;
map<string,int> lef;
map<string,int> rigt;
map<string,int> an;
int n;

void solve(){
    cin >> n;
    set<string> types;
    int total = 0;
    for (int i=0; i<n; i++){
        string tipo, foot;
        int quant;
        cin >> tipo >> foot >> quant;
        types.insert(tipo);
        total += quant;
        if (foot == "left") lef[tipo] += quant;
        else if (foot == "right") rigt[tipo] += quant;
        else an[tipo] += quant;
    }
    int resp = 0;

    for (auto t:types){
        if (lef[t] == 0 and rigt[t] == 0){
            resp += (bool)an[t];
        }
        else{
            resp += max(lef[t], rigt[t]);
        }
    }
    if (resp == total) cout << "impossible\n";
    else cout << resp+1 << endl;

}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
}