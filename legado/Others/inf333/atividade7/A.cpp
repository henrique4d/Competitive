#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        int sum = 0;
        int val = 0;
        int beg = 0;
        int end = 0;
        int best = -1;
        int max_interval = 0;
        int best_beg = -1;
        int best_end = -1;

        for (int i=0; i<n-1; i++){
            cin >> val;
            sum+= val;
            //cout << sum << " " << max_interval << endl;
            if (sum < 0){
                sum = 0;
                beg = i+1;
                end = i+1;
            }

            if (sum > best or (sum == best and i-beg > max_interval)){
                best = sum;
                end = i;
                max_interval = i-beg;
                //cout << "entrou no if" << " " << beg << " " << end  << endl;
                best_beg = beg;
                best_end = end;
            }
        }
        if (best <= 0){
            printf("Route %d has no nice parts\n", l+1);
        }
        else
            printf("The nicest part of route %d is between stops %d and %d\n", l+1, best_beg+1,best_end+2);
    }
}