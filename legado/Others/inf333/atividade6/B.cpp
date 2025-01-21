#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        list<pair<long long int, char>> pedra;

        long long int n, d;
        cin >> n >> d;
        pedra.push_back(make_pair(0,'B'));
        for (int i=0; i<n; i++){
            char type, trash;
            long long int val;
            cin >> type;
            cin >> trash;
            cin >> val;
            pedra.push_back(make_pair(val, type));
        }
        pedra.push_back(make_pair(d,'B'));
        long long int maior = 0;
        

        auto it = pedra.begin();
        while (it != pedra.end()){
            auto atual = it;
            it++;
            if (atual->second == 'S' and it->second == 'S') it++;
            maior = max(maior, it->first - atual->first);
            if (atual->second == 'S') pedra.erase(atual);
        }
        it = pedra.begin();
        while (it != pedra.end()){
            auto atual = it;
            it++;
            maior = max(maior, it->first - atual->first);
        }
        cout << "Case " << l+1 << ": " << maior << endl;
    }
}