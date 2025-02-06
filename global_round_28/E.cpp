//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		if (m > 2 * n - 1) return cout << "NO\n", []{}();

		vector<vector<int>> ans(m, vector<int>(2 * n));
		vector<int> t(2 * n);
		for (int i{0}; i < n; ++i) t[i * 2] = t[i * 2 + 1] = i;
		for (int j{0}; j < m; ++j) {
			ans[j] = t;
			rotate(t.begin(), t.begin() + 1, t.end());
		}

		cout << "YES\n";
		for (int i{0}; i < 2 * n; ++i)
			for (int j{0}; j < m; ++j) cout << (ans[j][i] + 1) << " \n"[j == m - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
