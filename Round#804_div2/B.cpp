//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));

	g[0][0] = g[1][1] = 1;
	g[1][0] = g[0][1] = 0;
	for (int j{2}; j < m; j += 2) {
		g[0][j] = g[0][j - 1], g[1][j] = g[1][j - 1];
		g[0][j + 1] = g[0][j - 2], g[1][j + 1] = g[1][j - 2];
	}
	for (int i{2}; i < n; i += 2)
		for (int j{0}; j < m; ++j) {
			g[i][j] = g[i - 1][j];
			g[i + 1][j] = g[i - 2][j];
		}

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
