// Problem LInk: https://cses.fi/problemset/task/1648
// Good Starter Problem for Beginners who want to start Segment Tree
// Few Extra Problem wth same concepts are : 
//    https://cses.fi/problemset/task/1649
//    https://cses.fi/problemset/task/1650

#include<bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define debug(x...)
#define testcase(tc)
#else
#include "debug.h"
#endif

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define allr(v) (v).rbegin(),(v).rend()
#define trav(x) for(auto &i:(x)) // Traverse through each element in the container
#define pr(x) cout << x << endl  // Print a single value and newline
#define yesno(x) cout << ((x) ? "Yes\n" : "No\n") // Print "Yes" or "No" based on the boolean value

const ll INF = ll(2e18); // Set a large value for infinity
const char nl = '\n'; // Newline constant

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); // Fast I/O

	ll n,q;
	cin >> n >> q; // Read the size of the array `n` and the number of queries `q`
	vector<ll> ar(n); // Initialize an array of size `n`
	trav(ar) cin >> i; // Input values into the array

	ll N = 4*n; // Total size needed for the segment tree (typically 4 times the array size)
	vector<ll> seg(N); // Segment tree array

	// Function to build the segment tree
	function<void(ll, ll, ll)> build = [&](ll ind, ll low, ll high) {
		// If low equals high, we are at a leaf node
		if(low == high) {
			seg[ind] = ar[low]; // Set the leaf node to the array value
			return;
		}
		ll mid = (low + high) / 2; // Compute the mid-point of the current range
		build(2*ind+1, low, mid); // Recursively build the left child
		build(2*ind+2, mid+1, high); // Recursively build the right child
		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; // Sum of left and right children
	};
	build(0, 0, n-1); // Start building the segment tree from the root node

	// Function to query the sum over a range
	function<ll(ll, ll, ll, ll, ll)> query = [&](ll ind, ll l, ll r, ll low, ll high) -> ll {
		// If the range is outside the bounds, return 0 (no overlap)
		if(r < low or high < l) return 0;
		// If the current range is completely within the query range, return the segment value
		if(low >= l and high <= r) return seg[ind];
		
		ll mid = (low + high) / 2; // Compute the mid-point of the current range
		ll left = query(2*ind+1, l, r, low, mid); // Query the left child
		ll right = query(2*ind+2, l, r, mid+1, high); // Query the right child
		return left + right; // Return the sum of left and right children
	};

	// Function to update the segment tree at a given position
	function<void(ll, ll, ll, ll, ll)> update = [&](ll ind, ll pos, ll val, ll low, ll high) {
		// If we've reached the leaf node (i.e., the element to update)
		if(low == high) {
			seg[ind] = val; // Update the value at the leaf node
			return;
		}
		ll mid = (low + high) / 2; // Compute the mid-point of the current range
		// Recursively update the correct child (left or right)
		if(pos <= mid) update(2*ind+1, pos, val, low, mid); // Update left child
		else update(2*ind+2, pos, val, mid+1, high); // Update right child
		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; // Update the current node after updating the child
	};

	// Handling multiple queries
	while(q--) {
		ll t; cin >> t; // Read the type of query
		if(t == 1) { // Update query
			ll pos, val; cin >> pos >> val;
			pos--; // Adjust for 0-based indexing
			update(0, pos, val, 0, n-1); // Call the update function
			ar[pos] = val; // Update the array as well
		}
		else { // Range query
			ll l, r; cin >> l >> r;
			l--, r--; // Adjust for 0-based indexing
			cout << query(0, l, r, 0, n-1) << nl; // Output the result of the range query
		}
	}
	return 0;
}
