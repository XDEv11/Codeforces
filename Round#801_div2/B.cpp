//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n & 1) return cout << "Mike\n", []{}();

	int mn1{numeric_limits<int>::max()}, mn1i, mn2{mn1}, mn2i;
	for (int i{0}; i < n; ++i)
		if (i & 1) {
			if (v[i] < mn2) mn2 = v[i], mn2i = i;
		} else {
			if (v[i] < mn1) mn1 = v[i], mn1i = i;
		}
	cout << (mn1 > mn2 || (mn1 == mn2 && mn1i > mn2i) ? "Mike\n" : "Joe\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
