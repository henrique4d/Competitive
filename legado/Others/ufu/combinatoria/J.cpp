#include <bits/stdc++.h>
using namespace std;
long double fat(long double n){
    if (n == 0) return 1;
    return n*fat(n-1);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        long double total = fat(val)/(fat(3)*fat(val-3));
        val--;
        long double comojogo = fat(val)/(fat(2)*fat(val-2));

        long double final = comojogo*100/total;
        cout << fixed << setw(log10(total)+1) << setprecision(0) << total;
        cout  << " " << fixed << setprecision(2) <<  final << "%"<< endl;
    }
}