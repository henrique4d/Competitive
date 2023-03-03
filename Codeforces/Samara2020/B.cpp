#include <bits/stdc++.h>
using namespace std;
int main(){
 
    vector<long long int> neg;
    vector<long long int> pos;
    long long int cont0 = 0;
    long long int n, t;
    cin >> n >> t;
    long long int aux;
    for (int i=0; i<n; i++){
        cin >> aux;
        if (aux == 0){
            cont0++;
            continue;
        }
        if (aux < 0) neg.push_back(aux);
        if (aux > 0) pos.push_back(aux);
    }
 
    sort(neg.begin(), neg.end(), greater<long long int>());
    
    long long int dist_atual = 0;
 
    int indexPos = 0;
    int indexneg = 0;
 
    long long int best = 0;
    long long int cont = 0;
 
    for (int i=0; i<neg.size(); i++){
        if (-neg[i] > t) break;
        cont++;
        best = max(best,cont);
    }
 
    cont = 0;
 
    for (int i=0; i<pos.size(); i++){
        if (pos[i] > t) break;
        cont++;
        best = max(best,cont);
    }
    
 
    long long int distBase = 0;
 
    cont = 0;
    indexneg = -1;
    indexPos = 0;
    dist_atual = 0;
 
    for (int i=0; i<neg.size(); i++){
        if (-2*neg[i] > t) break;
        cont++;
        best = max(best,cont);
        indexneg++;
    }
    //cout << "cont apos pegar somente os negativos " << cont << endl;
    //cout << "valor dos index: " << indexneg << " " << indexPos << endl;
    if (indexneg != -1) dist_atual = -2*neg[indexneg];
    distBase = dist_atual;
    //cout << dist_atual << endl;
    while (indexPos < pos.size() and distBase + pos[indexPos] <= t){
        //dist_atual += pos[indexPos];
        indexPos++;
        cont++;
        best = max(best, cont);
    }
    //cout << dist_atual << endl;
    
    for (int i=indexneg; i>=0; i--){
        indexneg = i;
        distBase = -2*neg[indexneg];
        //long long int dist_percorrida;
        //dist_percorrida = -2*(neg[indexneg] - neg[indexneg-1]);
        //cout << " para o i de " << i << " a distancia base e " << distBase << " com os dois conts sendo " << indexneg << " " << indexPos << endl;
        //distBase -= dist_percorrida;
        cont = indexneg+indexPos+1;
 
        while (indexPos < pos.size() and distBase + pos[indexPos] <= t){
            //dist_atual += pos[indexPos];
            indexPos++;
            cont = indexneg+indexPos+1;
            best = max(best, cont);
            //cout << "entrou no while e jogou o index pos para " << indexPos << " e o cont para " << cont << endl;
            
            
        }
    }
    //cout << best << endl;
    //cout << cont << " " << best << endl;
 
 
 
 
 
 
    cont = 0;
    indexneg = 0;
    indexPos = -1;
    dist_atual = 0;
    distBase = 0;
 
    for (int i=0; i<pos.size(); i++){
        if (2*pos[i] > t) break;
        cont++;
        best = max(best,cont);
        indexPos++;
    }
    if (indexPos != -1) dist_atual = 2*pos[indexPos];
    distBase = dist_atual;
    
    while (indexneg < neg.size() and distBase - neg[indexneg] <= t){
        //dist_atual += abs(neg[indexneg]);
        indexneg++;
        cont++;
        best = max(best, cont);
    }
    
    for (int i=indexPos; i>=0; i--){
        indexPos = i;
        distBase = 2*pos[indexPos];
        //long long int dist_percorrida;
        //dist_percorrida = 2*(pos[indexPos] - pos[indexPos-1]);
 
        //distBase -= dist_percorrida;
        //cont--;
 
        cont = indexneg+indexPos+1;
        while (indexneg < neg.size() and distBase - neg[indexneg] <= t){
            indexneg++;
            cont++;
            best = max(best, cont);
        }
    }
 
    best+=cont0;
    
    cout << best << endl;
 
}