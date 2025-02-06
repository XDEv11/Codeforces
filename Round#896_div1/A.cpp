//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n, vector<int>(m, -1));
	for (int i{0}; i < n; ++i) {
		if (i < m - 1) {
			for (int j{0}; j < m; ++j) g[i][(j + 1 + i) % m] = j;
		} else {
			for (int j{0}; j < m; ++j) g[i][j] = (j + 1) % m;
		}
	}

	cout << (m == 1 ? 0 : min(n + 1, m)) << '\n';
	for (auto& v : g) {
		for (auto& x : v) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
