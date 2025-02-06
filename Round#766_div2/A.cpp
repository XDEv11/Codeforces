//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, m, r, c;
	cin >> n >> m >> r >> c, --r, --c;
	vector<vector<char>> g(n, vector<char>(m));
	bool f{false};
	for (auto& v : g)
		for (auto& x : v) cin >> x, f = f || (x == 'B');
	if (!f) return cout << "-1\n"s, []{}();
	if (g[r][c] == 'B') return cout << "0\n"s, []{}();

	f = false;
	for (int i{0}; i < n; ++i) f = f || g[i][c] == 'B';
	for (int j{0}; j < m; ++j) f = f || g[r][j] == 'B';
	cout << (f ? 1 : 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
