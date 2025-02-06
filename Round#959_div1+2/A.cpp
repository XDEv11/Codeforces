//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n * m);
		for (auto& x : v) cin >> x;
		if (n * m == 1) return cout << "-1\n", []{}();

		rotate(v.begin(), v.begin() + 1, v.end());

		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) cout << v[i * m + j] << " \n"[j == m - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
