//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v0(n), v1(n);
		for (auto& x : v0) cin >> x;
		for (auto& x : v1) cin >> x;

		int ans{}, mx{numeric_limits<int>::min()};
		for (int i{0}; i < n; ++i) {
			if (v0[i] >= v1[i]) ans += v0[i], mx = max(mx, v1[i]);
			else ans += v1[i], mx = max(mx, v0[i]);
		}

		cout << (ans + mx) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
