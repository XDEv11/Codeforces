//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	int mx{numeric_limits<int>::min()}, mxi, mxj;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			if (g[i][j] > mx) mx = g[i][j], mxi = i, mxj = j;
	cout << max(mxi + 1, n - mxi) * max(mxj + 1, m - mxj) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
