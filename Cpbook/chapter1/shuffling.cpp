#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string comand;
    cin >> comand;

    queue<int> A;
    queue<int> B;
    queue<int>pile;
    int cont = 0;

    bool impar = n%2 == 1;
    if (impar) n--;

    
    for (int i=0; i<n/2; i++){
        A.push(i);
    }
    for (int i=n/2; i<n; i++){
        B.push(i);
    }
    if (impar and comand == "out"){
        A.push(B.front());
        B.pop();
        B.push(n);
    }

    if (impar and comand == "in"){
        B.push(n);
    } 
    while (true){    
        if (comand == "out"){
            bool ordenado = true;
            for (int i=0; i<n; i+=2){
                pile.push(A.front());
                //cout << "inserindo " << A.front() << "na pilha\n";
                pile.push(B.front());
                //cout << "inserindo " << B.front() << "na pilha\n";
                A.pop();
                B.pop();
            }
            if (impar){
                pile.push(A.front());
                A.pop();
            }
            for (int i=0; i<n/2; i++){
                A.push(pile.front());
                //cout << "inserindo " << pile.front() << "em A\n";
                

                if (pile.front() != i){
                    ordenado = false;
                }
                pile.pop();
            }
            for (int i=n/2; i<n; i++){
                B.push(pile.front());

                //cout << "inserindo " << pile.front() << "em B\n";
                
                if (pile.front() != i){
                    ordenado = false;
                }
                pile.pop();
            }
            if (impar){
                A.push(B.front());
                B.pop();
                B.push(pile.front());
                if (pile.front() != n){
                    ordenado = false;
                }
                pile.pop();
            }
            if (ordenado){
                cout << cont+1 << endl;
                return 0;
            }
            cont++;
            //cout << cont << endl;
            //cout << "///////////////" << endl;
        }


        if (comand == "in"){
            bool ordenado = true;
            for (int i=0; i<n; i+=2){
                pile.push(B.front());
                pile.push(A.front());
                A.pop();
                B.pop();
            }
            if (impar){
                pile.push(B.front());
                B.pop();
            }
            for (int i=0; i<n/2; i++){
                A.push(pile.front());
                if (pile.front() != i){
                    ordenado = false;
                }
                pile.pop();
                
            }
            for (int i=n/2; i<n; i++){
                B.push(pile.front());
                if (pile.front() != i){
                    ordenado = false;
                }
                pile.pop();
                
            }
            if (impar){
                if (pile.front() != n){
                    ordenado = false;
                }
                B.push(pile.front());
                
                pile.pop();
            }
            if (ordenado){
                cout << cont+1 << endl;
                return 0;
            }
            cont++;
        }
    }
}