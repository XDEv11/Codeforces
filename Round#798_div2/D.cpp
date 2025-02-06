//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	vector<vector<int>> d1(n, vector<int>(m, -1));
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			if (g[i][j] == 'B') d1[i][j] = 0;
			if (i - 1 >= 0 && d1[i - 1][j] != -1) d1[i][j] = max(d1[i][j], d1[i - 1][j] + 1);
			if (j - 1 >= 0 && d1[i][j - 1] != -1) d1[i][j] = max(d1[i][j], d1[i][j - 1] + 1);
		}
	vector<vector<int>> d2(n, vector<int>(m, -1));
	for (int i{0}; i < n; ++i)
		for (int j{m - 1}; j >= 0; --j) {
			if (g[i][j] == 'B') d2[i][j] = 0;
			if (i - 1 >= 0 && d2[i - 1][j] != -1) d2[i][j] = max(d2[i][j], d2[i - 1][j] + 1);
			if (j + 1 < m && d2[i][j + 1] != -1) d2[i][j] = max(d2[i][j], d2[i][j + 1] + 1);
		}
	vector<vector<int>> d3(n, vector<int>(m, -1));
	for (int i{n - 1}; i >= 0; --i)
		for (int j{0}; j < m; ++j) {
			if (g[i][j] == 'B') d3[i][j] = 0;
			if (i + 1 < n && d3[i + 1][j] != -1) d3[i][j] = max(d3[i][j], d3[i + 1][j] + 1);
			if (j - 1 >= 0 && d3[i][j - 1] != -1) d3[i][j] = max(d3[i][j], d3[i][j - 1] + 1);
		}
	vector<vector<int>> d4(n, vector<int>(m, -1));
	for (int i{n - 1}; i >= 0; --i)
		for (int j{m - 1}; j >= 0; --j) {
			if (g[i][j] == 'B') d4[i][j] = 0;
			if (i + 1 < n && d4[i + 1][j] != -1) d4[i][j] = max(d4[i][j], d4[i + 1][j] + 1);
			if (j + 1 < m && d4[i][j + 1] != -1) d4[i][j] = max(d4[i][j], d4[i][j + 1] + 1);
		}

	int mnd{numeric_limits<int>::max()};
	pair<int, int> ans;
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			int d{max(max(d1[i][j], d2[i][j]), max(d3[i][j], d4[i][j]))};
			if (d < mnd) {
				mnd = d;
				ans = {i, j};
			}
		}

	cout << ans.fi + 1 << ' ' << ans.se + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
