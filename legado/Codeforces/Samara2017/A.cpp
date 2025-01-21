#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<pair<pair<int,int>, string>> alwayspositivo;
    vector<pair<pair<int,int>, string>> fakepositivo;
    vector<pair<pair<int,int>, string>> negativo;
    

    int total = 0;
    for (int i=0; i<n; i++){
        string aux;
        cin >> aux;
        int saldo = 0;
        bool neg = false;
        int contNeg = 0;
        int menorMarca = 0;
        for (int j=0; j<aux.size(); j++){
            if (aux[j] == '(') saldo++;
            else{
                saldo--;
                contNeg++;
            }
            menorMarca = min(menorMarca, saldo);
            if (saldo < 0) neg = true;
        }    

        //cout << saldo << endl;
        total += saldo;
        if (saldo < 0){
            negativo.push_back(make_pair(make_pair(saldo, -i),aux));
        }
        else if (neg){
            fakepositivo.push_back(make_pair(make_pair(-menorMarca, -i),aux));
        }
        else{
            alwayspositivo.push_back(make_pair(make_pair(saldo, -i),aux));
        }
    }
    sort(fakepositivo.begin(), fakepositivo.end());

    //cout << total << endl;
    if (total){
        cout << "NO\n";
        return 0;
    }
    

    vector<int> order;
 
    int cont = 0;

    for (int i=0; i<alwayspositivo.size(); i++){
        //cout << alwayspositivo[i].second << endl;
        for (int j=0; j< alwayspositivo[i].second.size(); j++){
            if (alwayspositivo[i].second[j] == '(') cont++;
            else cont--;
            if (cont < 0){
                cout << "NO\n";
                return 0;
            }
        }
        order.push_back(alwayspositivo[i].first.second);
    }
    for (int i=0; i<fakepositivo.size(); i++){
        //cout << fakepositivo[i].second << endl;

        for (int j=0; j< fakepositivo[i].second.size(); j++){
            if (fakepositivo[i].second[j] == '(') cont++;
            else cont--;
            if (cont < 0){
                cout << "NO\n";
                return 0;
            }
        }
        order.push_back(fakepositivo[i].first.second);
    }
    for (int i=0; i<negativo.size(); i++){
        //cout << negativo[i].second << endl;

        for (int j=0; j< negativo[i].second.size(); j++){
            if (negativo[i].second[j] == '(') cont++;
            else cont--;
            if (cont < 0){
                cout << "NO\n";
                return 0;
            }
        }
        order.push_back(negativo[i].first.second);
    }

    
    cout << "YES\n";
    for (int i=0; i<order.size(); i++){
        cout << abs(order[i])+1;
        if (i!= order.size() -1) cout << " ";
    }
    cout << endl;


}