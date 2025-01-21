#include <bits/stdc++.h>
using namespace std;
typedef int ll;


int main(){
    int n;
    cin >> n;

    bool jane = true;
    int cont_atual = 0;
    int cont_troca = 1;
    for (int i=1; i<=n; i++){
        if (cont_atual == cont_troca){
            if (cont_troca == 1){
                jane = false;
                cont_troca++;
            }
            else if (jane){
                jane = false;
                cont_troca++;
            }
            else {
                jane = true;
            }
            cont_atual = 0;
        }
        cont_atual++;
    }

    cout << (jane==true?"Jane\n":"John\n");

}