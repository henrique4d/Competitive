#include <bits/stdc++.h>
 
    void solve(){
        int n;
        std::cin >> n;
        int z = 0;
        int v[n];
        int k = 1;
 
        for (int i=0;i<n;i++){
            std::cin >> v[i];
        }
        z+=v[0];
        for (int i=1;i<n;i++){
            k = 1;
            while(true){
                if(v[i]*k>z){
                    z = v[i]*k;
                    break;
                }else
                    k++;
            }
 
 
        }
        std::cout << z << std::endl;
    }
 
int main (){
    
    int t;
    std::cin >> t;
 
    while(t--){
        solve();
    }
    
    
    return 0;
 
}