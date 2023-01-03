#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        queue<char> Jane, John;
        if (k) cout << endl;
        string JanePile = "", JohnPile = "";
        string aux1, aux2;
        cin >> aux1 >> aux2;
        for (int i=0; i< aux1.size(); i++){
            Jane.push(aux1[i]);
            John.push(aux2[i]);
        }       
        

        for (int i=0; i<1000; i++){
            JanePile += Jane.front();
            JohnPile += John.front();

            Jane.pop();
            John.pop();

            if (JanePile[JanePile.size()-1] == JohnPile[JohnPile.size()-1]){
                if (random()/141%2 == 0){
                    
                    JanePile += JohnPile;
                    JohnPile = "";
                    cout << "Snap! for Jane: ";
                    for (auto it = JanePile.rbegin(); it!= JanePile.rend(); it++){
                        cout << *it;
                    }
                    cout << endl;
                }
                else{
                
                    JohnPile += JanePile;
                    JanePile = "";
                    cout << "Snap! for John: ";
                    for (auto it = JohnPile.rbegin(); it!= JohnPile.rend(); it++){
                        cout << *it;
                    }
                    cout << endl;
                
                }             
            }

            if (Jane.size() == 0 and JanePile.size() == 0){
                // john win
                cout << "John wins.\n";
                goto here;
            }
            if (JohnPile.size() == 0 and John.size() == 0){
                //jane wins
                cout << "Jane wins.\n";
                goto here;
            }

            if (Jane.size() == 0){
                for (int j= 0; j<JanePile.size();j++){
                    Jane.push(JanePile[j]);
                }
                JanePile = "";
            }


            if (John.size() == 0){
                for (int j= 0; j<JohnPile.size();j++){
                    John.push(JohnPile[j]);
                }
                JohnPile = "";
            }

        }
        cout << "Keeps going and going ...\n";
        here:
        int asuhidfioauhsdf;
    }
}