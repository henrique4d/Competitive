#include<bits/stdc++.h>
using namespace std;
 
#define md                   1000000007
#define int                  signed long long int
#define pb                   push_back
#define loop(i,n)            for(int i=0;i<n;i++)
#define loop1(i,k,n)         for(int i=k;i<n;i++)
#define loop2(i,k,n)         for(int i=k;i>=n;i--)
#define read_a(arr)          for(int i=0;i<n;i++){cin>>arr[i];}
#define input(v)             for(auto &x: v) cin>>x
#define all(x)               (x).begin(), (x).end()
#define vi                   vector<int>
#define vvi                  vector<vector<int>>
#define fast_io              ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int32_t main(){
    fast_io;
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int find=0;
        loop(i,n/2){
            if(s[i]!=s[n-i-1]){
                find++;
            }
        }
        string ans;
        loop(i,find){
            cout<<'0';
        }
        int d=n+1-2*find;
        if(n&1){
            while(d--){
                cout<<'1';
            }
            loop(i,find){
                cout<<'0';
            }
        }
        else{
            d/=2;
            while(d--){
                cout<<"10";
            }
            cout<<'1';  
            loop(i,find){
                cout<<'0';
            }
        }
        cout<<endl;
    }
    return 0;
}