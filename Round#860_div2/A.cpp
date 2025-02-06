//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	for (int i{0}; i < n; ++i) {
		if (a[i] < b[i]) swap(a[i], b[i]);
	}
	cout << (*max_element(a.begin(), a.end()) == a.back() && 
		*max_element(b.begin(), b.end()) == b.back() ? "Yes\n" : "No\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
