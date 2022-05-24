#include <bits/stdc++.h>
using namespace std;

// function to find
// GCD of pair with
// max GCD in the
// array
long long int findMaxGCD(long long int arr[], long long int n, long long int high)
{
    // Maintaining count array
    long long int count[high + 1] = {0};
    
    for (long long int i = 0; i < n; i++)
        count[arr[i]]++;
 
    // Variable to store the
    // multiples of a number
    long long int counter = 0;
 
    // Iterating from MAX to 1
    // GCD is always between
    // MAX and 1. The first
    // GCD found will be the
    // highest as we are
    // decrementing the potential
    // GCD
    for (long long int i = high; i >= 1; i--)
    {
        long long int j = i;
        counter = 0;
   
        // Iterating from current
        // potential GCD
        // till it is less than
        // MAX
        while (j <= high)
        {
            // A multiple found
 
            if(count[j] >=2)
               return j;
 
           else if (count[j] == 1)        
                counter++;        
 
            // Incrementing potential
            // GCD by itself
            // To check i, 2i, 3i....
            j += i;
 
            // 2 multiples found,
            // max GCD found
            if (counter == 2)        
                return i;
        }
    }
}

int main(){
    int t;
    cin >> t;
    for (int k=0; k<t;k++){
        int n;
        cin >> n;
        long long int high = -1;
        long long int v[n];
        for (int i=0; i<n;i++){
            cin >> v[i];
            high = max(high, v[i]);
        }
        long long int gcd = findMaxGCD(v,n,high);
        
        long long int count = 0;
        for (int i=0; i<n; i++){
            if (v[i]%gcd == 0) count++;
        }
        cout << gcd << " " << count << endl;
    }   
}