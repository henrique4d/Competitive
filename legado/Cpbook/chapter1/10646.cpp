#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    for (int a=0; a<k; a++){
       stack<string> pile;
       for (int i=0; i<52; i++){
           string aux;
           cin >> aux;
           pile.push(aux);
       }
       stack<string> hand;

       for (int i=0; i<25; i++){
           string aux = pile.top();
           hand.push(aux);
           pile.pop();
        }
        int Y = 0;
        for (int i=0; i<3; i++){
            string first = pile.top();
            
            pile.pop();
            int value = 0;
            if (first[0] >= '2' and first[0] <= '9')
                value = first[0] - '0';
            else
                value = 10;

            Y+=value;
            for (int j=0; j< 10-value; j++){
                pile.pop();
            }
       }

        while (!pile.empty()){
            hand.push(pile.top());
            pile.pop();
        }

        for (int i=0; i<Y-1; i++){
            hand.pop();
        }
        cout << "Case " << a+1 << ": " <<  hand.top() << endl;
    }
}