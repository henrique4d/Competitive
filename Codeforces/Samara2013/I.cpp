#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int vida = 0;
    long long int danoTomado = 0;
    
    priority_queue<long long int> pq;
    long long int cont =0;

    for (int i=0; i<n; i++){
        cin >> vida;
        long long int val;
        cin >> val;
        danoTomado+=val;
        pq.push(val);
        while (danoTomado > vida){
            cont++;
            danoTomado -= pq.top();
            pq.pop();
        }
    }
    cout << cont << endl;
}