#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        bool primo = true;
        for (int j=2; j<sqrt(num); j++){
            if (num%j == 0){
                primo = false;
            }
        }
        if (primo){
            cout << "Primo\n";
        }
        else{
            cout << "Nao Primo\n";
        }
    }
}