//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i) {
		rotate(v.begin(), v.begin() + 1, v.end());
		if (is_sorted(v.begin(), v.end())) return cout << "Yes\n", []{}();
	}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
