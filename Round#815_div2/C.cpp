//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) {
			char c;
			cin >> c;
			x = (c == '1');
		}

	int mn{4};
	for (int i{0}; i + 1 < n; ++i)
		for (int j{0}; j + 1 < m; ++j) mn = min(mn, g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1]);
	int c{0};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) c += g[i][j];

	cout << c - max(0, mn - 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
