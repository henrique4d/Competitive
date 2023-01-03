#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = n;

    int value = 0;
    for (int i=0; i<n; i++){
        int aux;
        cin >> aux;
        if (aux == -1){
            count--;
        }
        else{
            value+=aux;
        }
    }

    double result = (double)value/count;

    cout << fixed << setprecision(15) << result << endl;
}