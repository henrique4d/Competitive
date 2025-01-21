#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long ll;
const ll MAXN = 1e4+10;
bool contratados[MAXN];

int main(){
    optimize;
    int n,s1,s2;
    cin >> n >> s1 >> s2;
    int n_original = n;

    s1--;
    s2--;
    list<int> l;

    for (int i=1; i<=n; i++){
        l.push_back(i);
    }

    auto it = l.begin();
    auto it2 = l.end();
    it2--;
    
    while (n > 2){
        int tam = s1%n;
        for (int i=0; i<tam; i++){
            it++;
            if (it == l.end()){
                it = l.begin();
            }
        }

        tam = s2%n;
        for (int i=0; i<tam; i++){
            if (it2 == l.begin()){
                it2 = l.end();
            }
            it2--;
        }

        if (it == it2){
            contratados[*it] = true;
            n--;
            auto to_erase = it;
            it++;
            if (it == l.end()){
                it = l.begin();
            }

            if (it2 == l.begin()){
                it2 = l.end();
            }
            it2--;
            
            l.erase(to_erase);
        }
        else{
            auto to_erase1 = it;
            auto to_erase2 = it2;

            while (it == to_erase1 or it == to_erase2){
                it++;
                if (it == l.end()) it = l.begin();
            }
            while (it2 == to_erase1 or it2 == to_erase2){
                if (it2 == l.begin()) it2 = l.end();
                it2--;
            }

            l.erase(to_erase1);
            l.erase(to_erase2);
                        
            n-=2;
        }
    }

    for (auto it = l.begin(); it!=l.end(); it++){
        contratados[*it] = true;
    }
    for (int i=0; i<=n_original; i++){
        if (contratados[i]) cout << i << " ";
    }
    cout << endl;

}