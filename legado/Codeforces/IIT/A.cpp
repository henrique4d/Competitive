#include <bits/stdc++.h>
using namespace std;

long long int form1(long long int t, long long int n){
    if ( (t/(n-1))%2 == 0) return 2 + (t%(n-1));
    return (n-1)- (t%(n-1));
}


long long int form2(long long int t, long long int n){
    if ( (t/(n-1))%2 == 1) return 2 + (t%(n-1));
    return (n-1)- (t%(n-1));
}

int main(){
    int z;
    cin >> z;
    long long int n, m;
    long long int alturaInicial, larguraInicial;
    for (int l=0; l<z; l++){
        cin >> n >> m >> alturaInicial >> larguraInicial;
        long long int tempo1 = larguraInicial-1;
        long long int tempo2 = m + alturaInicial - 2;

        long long int posSoldado1;
        long long int posSoldado2;
        long long int posSoldado3;
        long long int posSoldado4;

        if (alturaInicial == 1 or larguraInicial == m ){
            cout << "BestWishes\n";
            goto here;
        }
        
        long long int a;
        long long int d;
        a = alturaInicial-1;
        d = 2*(n-1);
        if (a<=tempo1&&(tempo1 -a)%d==0){
            cout << "BestWishes\n";
            goto here;
        }
        
        a = n-alturaInicial-1+n;
        d = 2*(n-1);
        if (a<=tempo1&&(tempo1 -a)%d==0){
            cout << "BestWishes\n";
            goto here;
        }

        a = m-larguraInicial;
        d = 2*(m-1);
        if (a<=tempo2&&(tempo2 -a)%d==0){
            cout << "BestWishes\n";
            goto here;
        }


        a = larguraInicial-1+m-1;
        d = 2*(m-1);
        if (a<=tempo2&&(tempo2 -a)%d==0){
            cout << "BestWishes\n";
            goto here;
        }

        cout << "Farewell\n";
        here:
        int asudhf;

    }
}