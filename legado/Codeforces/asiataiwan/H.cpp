#include <bits/stdc++.h>
using namespace std;
long long int binary(long long int val){
    long long int l = 0;
    long long int r = INT_MAX;
    long long int meio = l + (r-l)/2;

    while (true){
        //cout << l << " " << r << " " << meio << " " <<  meio * log10(6)  << " " << val << " " << log10(6) << endl;
        if (meio * log10(6) + 1 <= val){
            if ( (meio+1) * log10(6) + 1 > val){
                return meio + 1;
            }
            else{
                l = meio;
            }
        }
        else{
            r = meio;
        }
        meio = l + (r-l)/2;
    }
}

int main(){
    string in;
    cin >> in;
    long long int resp = binary(in.size()+1)+1;
    cout << resp << endl;
    if (in[0] - '0' < 6) resp--;
    if (in == "0") resp = 0;
    cout << resp << endl;

}