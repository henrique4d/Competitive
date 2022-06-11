#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    double total = 0;
    cin.ignore();
    for (int i=0; i<n; i++){
        string nome;
        getline(cin, nome, ':');
        cout << nome;
        double value;
        cin >> value;
        total += value;
    }
    cout << endl;
    double media = total/n;
    cout << fixed << setprecision(2) <<  media << endl;
}