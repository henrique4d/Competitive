#include <iostream>
using namespace std; 
#define ll long long
#include <bits/stdc++.h>


int main() {
	long long t;
    cin >> t;
    while(t--){
        ll n,flag=0;;
        cin >> n;
        vector<ll> A(n),B(n,0);
        ll j=n-1;
        ll curr_h=1;
        for(auto &x:A) cin >>x;
        if(A[0]!=n) {cout<<"NO"<<endl;flag=1;continue;}
        
        
        for(int i=1;i<n;i++) {
            for(int k=A[i-1];k>A[i];k--){
                B[j]=curr_h;
                j--;
            }
            curr_h++;
        
        }
        cout << "chegou aqui\n";
        while(j>=0) {B[j]=curr_h;j--;}
        if(flag==0){
            for(int i=0;i<n;i++) {
                cout << i << " " << j << endl;
                if(B[i]!=A[i] || (!B[i]) || (!A[i])) {cout <<"NO"<<endl;flag=1;break;}
            }
            if(flag==0) cout<<"YES"<<endl;
        }
        
    }

    return 0;
}