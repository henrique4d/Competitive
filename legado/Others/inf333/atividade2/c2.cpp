#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string in;
        cin >> in;
        vector<bool> processed(in.size(), false);
        for (int j=0; j<in.size(); j++){
            if (in[j] == '+' or in[j] == '-' or in[j] == '/' or in[j] == '*' or in[j] == '^'){
                if (processed[j]) continue;
                int k = j+1;
                int abrindo = 0;
                int fechando = 0;
                for (; k<in.size(); k++){
                    
                    swap(in[k], in[k-1]);
                    swap(processed[k], processed[k-1]);
                    if (in[k-1] == '(') abrindo++;
                    if (in[k-1] == ')') fechando++;
                    if (abrindo - fechando == -1){
                        processed[k] = true;
                        break;
                    } 
                }
            }
        }

        in.erase(remove(in.begin(), in.end(), '('), in.end());
        in.erase(remove(in.begin(), in.end(), ')'), in.end());
        cout << in << endl;
    }
}