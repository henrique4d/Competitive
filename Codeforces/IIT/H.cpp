#include <bits/stdc++.h>
using namespace std;

vector<int> discover;
vector<int> beg;
vector<int> en;

void convertToArray(list<int> neighbors[], int pos, int &cont){
    discover[cont] = pos;
    beg[pos] = cont;
    for (auto it = neighbors[pos].begin(); it!= neighbors[pos].end(); it++){
        if (beg[*it] != -1) continue;
        cont++;
        convertToArray(neighbors, *it, cont);
    }
    en[pos] = cont;
}


// A utility function to get the
// middle index of given range.
int getMid(int s, int e)
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
int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
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
int getMax(int* st, int n, int l, int r)
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
int constructSTUtil(vector<int> &arr, int ss, int se,
                    int* st, int si)
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
    int mid = getMid(ss, se);
     
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
int* constructST(vector<int>&arr, int n)
{
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
 
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
 
    // Allocate memory
    int* st = new int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int main(){
    int n,q;
    cin >> n >> q;

    vector<int> values(n);
    for (int& x : values) cin >> x;

    list<int> neighbors[n];
    int a,b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    discover.resize(n, -1);
    beg.resize(n, -1);
    en.resize(n, -1);
    int aux = 0;
    convertToArray(neighbors,0, aux);
    
    for (int i=0; i<n; i++){
        cout << beg[i] << " ";
    }
    cout << endl;

    for (int i=0; i<n; i++){
        cout << en[i] << " ";
    }
    cout << endl;
    int* st = constructST(values, n);

  

    
    //cout << beg[3] << " " << en[3] << endl;
    // cout << "Max of values in given range = "
    //      << getMax(st, n, beg[3], en[3]) << endl;
    // 

    // buildSparseTable(values, n);

    // cout << query(beg[0], en[0]) << endl;

}