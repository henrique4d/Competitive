#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (long long int&x : v) cin >> x;
    sort(v.begin(), v.end(), greater<long long int>());
    
    long long int sum = 0;
    long long int best = 0;
    for (long long int i=0; i<n; i++){
        sum+= v[i];
        //cout << sum << " " << (long long int)((i+1)*(i+2))/2 << endl;
        long long int anterior = best;
        best = max(best, sum - ((i+1)*(i+2))/2);
        if (best == anterior) break;
    }   
    
    cout << best << endl;

    return 0;
}