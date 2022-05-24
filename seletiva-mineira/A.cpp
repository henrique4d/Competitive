#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int v[n];
    priority_queue<int> nada;
    priority_queue<int> vende;
    priority_queue<int> compra;
    
    for (int i=0; i<n; i++){
        int value;
        cin >> value;
        if (!vende.empty() and value > vende.top()){
            int value_aux = vende.top();
            nada.push(-1*vende.top());
            vende.pop();
            vende.push(value);
            value = value_aux;
        }
        if (!nada.empty() and value > -1*nada.top()){
            vende.push(value);
            compra.push(-1*nada.top());
            nada.pop();
        }

        nada.push(-value);
    }

    for (int i=n-1; i>=0; i--){
        if (!nada.empty() and v[i] < -1*nada.top()){
            compra.push(-1*nada.top());
            vende.push(v[i]);
        }
        else if (!compra.empty() and v[i] < compra.top() ){
            
        }
    }
    int result = 0;
    //for (int i=0; i<compra.size(); i++){
     //   cout << compra[i] << " ";
     //   result -= compra[i];
    //}
    //cout << endl;

    while (!vende.empty()){
        result += vende.top();
        cout << vende.top() << " ";
        vende.pop();
    }

    cout << endl;

    cout << result << endl;
}