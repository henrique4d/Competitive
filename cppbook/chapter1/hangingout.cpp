#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int atual = 0;
    int count = 0;
    for (int i=0; i<k; i++){
        string in;
        int value;
        cin >> in;
        cin >> value;

        if (in == "leave"){
            atual-=value;
        }
        else{
            if(atual + value <= n){
                atual+=value;
            }
            else count++;
        }
    }
    cout << count << endl;
}