#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        int altura_atual = 0;
        int largura_atual = 0;
        int altura_maxima = 0;
        int largura_maxima = 0;
        int x,y;
        while (cin >> x >> y){
            if (x == -1 and y == -1){
                largura_maxima = max(largura_atual,largura_maxima);
                altura_maxima += altura_atual;
                altura_atual = 0;
                largura_atual = 0;
                break;
            }
            if (largura_atual + x <= n){
                largura_atual += x;
                altura_atual = max(altura_atual,y);
            }
            else{
                largura_maxima = max(largura_atual,largura_maxima);
                altura_maxima += altura_atual;
                altura_atual = 0;
                largura_atual = 0;
                largura_atual += x;
                altura_atual = max(altura_atual,y);
            }
        }
        cout << largura_maxima << " X " << altura_maxima << endl;
    }
}