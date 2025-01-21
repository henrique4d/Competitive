#include <bits/stdc++.h>
using namespace std;
const long long int N = 200000000;
//long long int *dp;
map<long long int, long long int> dp;



// CPP code for range maximum query and updates
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to get the
// middle index of given range.
long long int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
/*  A recursive function to get the sum of
    values in given range of the array.
    The following are parameters for this
    function.
 
    st       -> Pointer to segment tree
    node     -> Index of current node in
                the segment tree .
    ss & se  -> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[node]
    l & r    -> Starting and ending indexes
                of range query */
long long int MaxUtil(long long int* st, long long int ss, long long int se, long long int l,
            long long int r, long long int node)
{
    // If segment of this node is completely
    // part of given range, then return
    // the max of segment
    if (l <= ss && r >= se)
        return st[node];
 
    // If segment of this node does not
    // belong to given range
    if (se < l || ss > r)
        return -1;
 
    // If segment of this node is partially
    // the part of given range
    int mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}
 
/* A recursive function to update the nodes
   which have the given index in their range.
   The following are parameters st, ss and
   se are same as defined
   above index -> index of the element
   to be updated.*/
void updateValue(int arr[], int* st, int ss, int se,
                 int index, int value, int node)
{
    if (index < ss || index > se)
    {
        cout << "Invalid Input" << endl;
        return;
    }
     
    if (ss == se)
    {  
        // update value in array and in segment tree
        arr[index] = value;
        st[node] = value;
    }
    else {
            int mid = getMid(ss, se);
             
            if (index >= ss && index <= mid)
                updateValue(arr, st,
                            ss, mid, index,
                            value, 2 * node + 1);
            else
                updateValue(arr,
                            st, mid + 1, se,
                            index,
                            value, 2 * node + 2);
             
            st[node] = max(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}
 
// Return max of elements in range from
// index l (query start) to r (query end).
int getMax(long long int* st, long long int n, long long int l, long long int r)
{
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
 
// A recursive function that constructs Segment
// Tree for array[ss..se]. si is index of
// current node in segment tree st
long long int constructSTUtil(long long int arr[], long long int ss, long long int se,
                    long long int* st, long long int si)
{
    // If there is one element in array, store
    // it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then
    // recur for left and right subtrees and
    // store the max of values in this node
    long long int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}
 
/* Function to construct segment tree
   from given array.
   This function allocates memory for
   segment tree.*/
long long int* constructST(long long int arr[], long long int n)
{
    // Height of segment tree
    long long int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    long long int max_size = 2 * (int)pow(2, x) - 1;
 
    // Allocate memory
    long long int* st = new long long int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

long long int calculateDP(long long int i){
    if (dp[i] == 0){
        if (i%2 == 0){
            dp[i] = calculateDP(i/2)+1;
        }
        else{
            dp[i] = calculateDP(3*i+1)+1;
        }
    }
    return dp[i];
}

int main(){
    //dp = new long long int[N];
    //memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    
    
    //Build segment tree from given array
    // Print max of values in array
    // from index 1 to 3
    long long int aux[1000011];
    
    for (int i=1; i<=1000010; i++){
        calculateDP(i);
        aux[i] = dp[i];
    }
    long long int i,j;
    long long int* st = constructST(aux, 1000011);
    while (cin >> i >> j){
        cout << i << " " << j << " ";
        if (i>j) swap(i,j);
        cout << getMax(st, 1000011, i,j) << endl;
    }
    return 0;  
}