#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int num){
    //cout << "here" << endl;
    //cout << num << " " << log10(num) << endl;
    double media = 0;
    int aux = num;
    while (aux > 0){
        media+=aux%10;
        aux/=10;
    }
    //cout << media << endl;
    aux = num;
    int digit;
    while (aux > 0){
        digit = aux%10;
        //cout << digit << (double)(media - digit)/(int)(log10(num))   <<  endl;
        if ( (double)(media - digit)/(int)(log10(num)) == digit ) return true;
        aux/=10;
    }
    //cout << "////////////" << endl;
    return false;
}





int main(){
    int a,b,c,q;
    scanf("%d %d %d %d", &a, &b, &c, &q);
    int l,r;
    queue<long long int> toProcess;
    if (a)
    toProcess.push(a);
    if (b)
    toProcess.push(b);
    if (c)
    toProcess.push(c);

    vector<int> perfects;
    set<int> used;

    while (!toProcess.empty()){
        //cout << toProcess.size() << endl;
        long long int val = toProcess.front();
        toProcess.pop();
        //cout << val << endl;
        val*=10;
        if (val > 1e9) continue;
        int novo = val+a;
        if (isPerfect(novo) and used.find(novo) == used.end()) perfects.push_back(novo);
        toProcess.push(novo);
        used.insert(novo);

        novo = val+b;
        if (isPerfect(novo) and used.find(novo) == used.end()) perfects.push_back(novo);
        toProcess.push(novo);
        used.insert(novo);

        novo = val+c;
        if (isPerfect(novo) and used.find(novo) == used.end()) perfects.push_back(novo);
        toProcess.push(novo);
        used.insert(novo);
    }
    sort(perfects.begin(), perfects.end());   
    int best = 0;
    int indexBest = 0;
    // for (int i=0; i<perfects.size(); i++){
    //     cout << perfects[i] << " ";
    // }
    // cout << endl;
    
    // return 0;
    for (int i=0; i<q; i++){
        scanf("%d %d", &l, &r);
        r++;
        auto it1 = lower_bound(perfects.begin(), perfects.end(), l);
        auto it2 = lower_bound(perfects.begin(), perfects.end(), r);
        int cont = it2-it1;
        //cout << cont << endl;
        if (cont > best){
            best = cont;
            indexBest = i;
        }
    }
    indexBest++;
    cout << indexBest << endl;
}