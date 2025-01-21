#include <bits/stdc++.h>
using namespace std;
int main(){
    int livres;
    while (cin >> livres){
        if (!livres) return 0;
        vector<int> usando(255, 0);
        string timeline;
        cin >> timeline;
        int perdidos = 0;
        for (int i=0; i<timeline.size(); i++){
            if (usando[timeline[i]] == -1){
                usando[timeline[i]] = 0;
                perdidos++;
            }
            else if (usando[timeline[i]]  == 0) {
                if (livres){
                    usando[timeline[i]] = 1;
                    livres--;
                }
                else{
                    usando[timeline[i]] = -1;
                }
            }
            else if (usando[timeline[i]] == 1) {
                usando[timeline[i]] = 0;
                livres++; 
            }
        }
        if (!perdidos){
            cout << "All customers tanned successfully." << endl;
        }
        else {
            cout << perdidos << " customer(s) walked away." << endl;
        }
    }
}