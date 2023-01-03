#include <bits/stdc++.h>
using namespace std;



// Function to find the factors of a number
// using the Dixon Factorization Algorithm
bool factor(long long int n)
{
  
    // Factor base for the given number
    long long int base[4] = {2, 3, 5, 7};
  
    // Starting from the ceil of the root
    // of the given number N
    long long int start = int(sqrt(n));
  
    // Storing the related squares
    vector<vector<long long > >pairs;
     
    // For every number from the square root
    // Till N
    long long  len=sizeof(base)/sizeof(base[0]);
    for(long long int i = start; i < n; i++)
    {
        vector<long long int> v;
         
        // Finding the related squares
        for(long long int j = 0; j < len; j++)
        {
            long long int lhs = ((long long int)pow(i,2))% n;
            long long int rhs = ((long long int)pow(base[j],2)) % n;
              
            // If the two numbers are the
            // related squares, then append
            // them to the array
            if(lhs == rhs)
            {
                v.push_back(i);
                v.push_back(base[j]);
                pairs.push_back(v);
            }
                 
        }
    }
  
    // For every pair in the array, compute the
    // GCD such that
    len = pairs.size();
    for (int i = 0; i < len;i++){
        int factor = __gcd(pairs[i][0] - pairs[i][1], n);
          
        // If we find a factor other than 1, then
        // appending it to the final factor array
        if(factor != 1){
            if (factor == n or factor == -1) return true;
            else return false;
        }
            
    }
  }
  
// Driver Code
int main()
{
    cout << factor(10) << endl;
}
 
// This code is contributed by chitranayal



// int main(){
//     vector<long long int> primos;
//     primos.reserve(100000000);

//     long long int a,b;
//     while (cin >> a >> b){
//         primos.resize(0);
//         for (long long int i=a; i<= b; i++){
//             for (long long int j=2; j<sqrt(i) + 0.0001; j++){
//                 if (i%j == 0){
//                     goto here;
//                 } 
//             }
//             primos.push_back(i);
            
//             here:
//             int asdf;
        
//         }
        
//         long long int menor = INT_MAX;
//         long long int maior = -1;
//         long long int maiorbeg;
//         long long int menorbeg;
//         long long int maiorend;
//         long long int menorend;

//         if (primos.size() <=1){
//             printf("There are no adjacent primes.\n");
//             continue;
//         }
//         for (int i=0; i<primos.size()-1; i++){
//             if (primos[i+1] - primos[i] > maior){
//                 maiorbeg = primos[i];
//                 maiorend = primos[i+1];
//                 maior = maiorend - maiorbeg;
//             }
//             if (primos[i+1] - primos[i] < menor){
//                 menorbeg = primos[i];
//                 menorend = primos[i+1];
//                 menor = menorend - menorbeg;
//             }
//         }
 
//         printf("%lld,%lld are closest, %lld,%lld are most distant.\n", menorbeg, menorend, maiorbeg, maiorend);



//     }


// }