#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n; cin>>n;
 
    long long v[n];
 
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
 
    bool subida = true;
    long long  direita, esquerda = v[0], topo;
    long long res=0;
 
 
    for(int i=1;i<n;i++){
        if(subida && v[i-1]<=v[i]){
            topo = v[i];
        }else if(subida && v[i-1]>v[i]){
            subida = false;
            direita = v[i];
        }else if(!subida && v[i]<=v[i-1] ){
            direita = v[i];
        }else if(!subida && v[i]>v[i-1]){
            subida = true;
            res = max(res,min(abs(topo-direita),abs(topo-esquerda)));
            esquerda = v[i-1];
            i--;
        }
    }
 
    if(!subida){
        res = max(res,min(abs(topo-direita),abs(topo-esquerda)));
    }
 
    cout << res << '\n';
 
 
 
    return 0;
}