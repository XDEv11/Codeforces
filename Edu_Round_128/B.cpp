//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	int mni{n}, mnj{m};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j)
			if (g[i][j] == 'R') mni = min(mni, i), mnj = min(mnj, j);

	cout << (g[mni][mnj] == 'R' ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
