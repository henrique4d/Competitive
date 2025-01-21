#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
          int n,m;
          cin>>n>>m;
          vector<int>a(n),b(m);
          for(int i=0;i<n;i++)cin>>a[i];
          for(int i=0;i<m;i++)cin>>b[i];
   
               int y=0;
               for(int i=0;i<m;i++){
                    y = y|b[i];
               }
               int mn=0,mx=0;
               for(int i=0;i<n;i++){
                    mn = mn^(a[i]|y);
                    mx=mx^a[i];
               }
         
          if(n%2==0)cout<<mn<<" "<<mx<<"\n";
          else cout<<mx<<" "<<mn<<"\n";
     }
}