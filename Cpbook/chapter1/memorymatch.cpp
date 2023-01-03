#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    bool discovered[n];
    int faceup = 0;
    memset(discovered, false, sizeof(discovered));
    map<string,int> contDisc;
    
    
    for (int i=0; i<k; i++){
        int posA, posB;
        string cardA, cardB;
        cin >> posA >> posB >> cardA >> cardB;
        posA--;
        posB--;

        if (!discovered[posA]){
            discovered[posA] = true;
            contDisc[cardA]++;
        }
        if (!discovered[posB]){
            discovered[posB] = true;
            contDisc[cardB]++;
        }
        if (cardA == cardB){
            contDisc[cardA]-=2;
            contDisc[cardB]-=2;
            faceup++;
        }
    }
    int cont = 0;
    for (auto it = contDisc.begin(); it!= contDisc.end(); it++){
        if (it->second == 2){
          cont++;
          faceup++;  
        } 
    }
    
    if (contDisc.size() >= n/2 or (contDisc.size() >= n/2-1 and faceup == n/2-1)){
        cout << n/2 - faceup + cont << endl;
        return 0;
    }

  
    
    cout << cont << endl;
}