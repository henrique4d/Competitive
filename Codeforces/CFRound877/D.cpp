#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
 
#define fi first 
#define se second 
#define pb push_back
 
#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"yes\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"no\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MAX 200000+20
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
ll T,N,M,K;

// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree[MAX] = {0}; // To store segment tree
ll lazy[MAX] = {0}; // To store pending updates

/* si -> index of current node in segment tree
	ss and se -> Starting and ending indexes of elements for
				which current nodes stores sum.
	us and ue -> starting and ending indexes of update query
	diff -> which we need to add in the range us to ue */
void updateRangeUtil(ll si, ll ss, ll se, ll us,
					ll ue, ll diff)
{
	// If lazy value is non-zero for current node of segment
	// tree, then there are some pending updates. So we need
	// to make sure that the pending updates are done before
	// making new updates. Because this value may be used by
	// parent after recursive calls (See last line of this
	// function)
	if (lazy[si] != 0)
	{
		// Make pending updates using value stored in lazy
		// nodes
		tree[si] += (se-ss+1)*lazy[si];

		// checking if it is not leaf node because if
		// it is leaf node then we cannot go further
		if (ss != se)
		{
			// We can postpone updating children we don't
			// need their new values now.
			// Since we are not yet updating children of si,
			// we need to set lazy flags for the children
			lazy[si*2 + 1] += lazy[si];
			lazy[si*2 + 2] += lazy[si];
		}

		// Set the lazy value for current node as 0 as it
		// has been updated
		lazy[si] = 0;
	}

	// out of range
	if (ss>se || ss>ue || se<us)
		return ;

	// Current segment is fully in range
	if (ss>=us && se<=ue)
	{
		// Add the difference to current node
		tree[si] += (se-ss+1)*diff;

		// same logic for checking leaf node or not
		if (ss != se)
		{
			// This is where we store values in lazy nodes,
			// rather than updating the segment tree itself
			// Since we don't need these updated values now
			// we postpone updates by storing values in lazy[]
			lazy[si*2 + 1] += diff;
			lazy[si*2 + 2] += diff;
		}
		return;
	}

	// If not completely in rang, but overlaps, recur for
	// children,
	ll mid = (ss+se)/2;
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

	// And use the result of children calls to update this
	// node
	tree[si] = tree[si*2+1] + tree[si*2+2];
}

// Function to update a range of values in segment
// tree
/* us and eu -> starting and ending indexes of update query
	ue -> ending index of update query
	diff -> which we need to add in the range us to ue */
void updateRange(ll n, ll us, ll ue, ll diff)
{
updateRangeUtil(0, 0, n-1, us, ue, diff);
}


/* A recursive function to get the sum of values in given
	range of the array. The following are parameters for
	this function.
	si --> Index of current node in the segment tree.
		Initially 0 is passed as root is always at'
		index 0
	ss & se --> Starting and ending indexes of the
				segment represented by current node,
				i.e., tree[si]
	qs & qe --> Starting and ending indexes of query
				range */
ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
	// If lazy flag is set for current node of segment tree,
	// then there are some pending updates. So we need to
	// make sure that the pending updates are done before
	// processing the sub sum query
	if (lazy[si] != 0)
	{
		// Make pending updates to this node. Note that this
		// node represents sum of elements in arr[ss..se] and
		// all these elements must be increased by lazy[si]
		tree[si] += (se-ss+1)*lazy[si];

		// checking if it is not leaf node because if
		// it is leaf node then we cannot go further
		if (ss != se)
		{
			// Since we are not yet updating children os si,
			// we need to set lazy values for the children
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}

		// unset the lazy value for current node as it has
		// been updated
		lazy[si] = 0;
	}

	// Out of range
	if (ss>se || ss>qe || se<qs)
		return 0;

	// At this poll we are sure that pending lazy updates
	// are done for current node. So we can return value
	// (same as it was for query in our previous post)

	// If this segment lies in range
	if (ss>=qs && se<=qe)
		return tree[si];

	// If a part of this segment overlaps with the given
	// range
	ll mid = (ss + se)/2;
	return getSumUtil(ss, mid, qs, qe, 2*si+1) +
		getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

// Return sum of elements in range from index qs (query
// start) to qe (query end). It mainly uses getSumUtil()
ll getSum(ll n, ll qs, ll qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout <<"Invalid Input";
		return -1;
	}

	return getSumUtil(0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(ll arr[], ll ss, ll se, ll si)
{
	// out of range as ss can never be greater than se
	if (ss > se)
		return ;

	// If there is one element in array, store it in
	// current node of segment tree and return
	if (ss == se)
	{
		tree[si] = arr[ss];
		return;
	}

	// If there are more than one elements, then recur
	// for left and right subtrees and store the sum
	// of values in this node
	ll mid = (ss + se)/2;
	constructSTUtil(arr, ss, mid, si*2+1);
	constructSTUtil(arr, mid+1, se, si*2+2);

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
void constructST(ll arr[], ll n)
{
	// Fill the allocated memory st
	constructSTUtil(arr, 0, n-1, 0);
}





void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i=0; i<n; i++){
        char aux;
        cin >> aux;
        if (aux == '(') v[i] = 1;
        else v[i] =-1;
    }
    vector<ll> sumMax(n);
    vector<ll> sumMin(n);
    
    sumMax[0] = v[0];
    sumMin[0] = v[0];
    ll fake_infinity = 5*n;
    for (int i=1; i<n; i++){
        sumMax[i] = sumMax[i-1] + v[i];
        sumMin[i] = sumMin[i-1] + v[i];
        if (v[i] == v[i-1] == 1){
            sumMax[i] += fake_infinity;
        }
        if (v[i] == v[i-1] == -1){
            sumMin[i] = min(sumMin[i], fake_infinity);
        }
    }
    if (sumMax[n-1] >= 0 and sumMin[n-1] <= 0) yes();
    else no();

    int flip;
    for (int q=0; q<k; q++){
        cin >> flip;
    }


}
 
 
int main() {
 
    optimize;
 
    T = 1;
    
    cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
} 
