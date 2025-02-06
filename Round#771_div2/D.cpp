//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	vector<array<int, 3>> ans{};
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<array<int, 2>> qu{};
	auto add = [&](int i, int j) {
		vis[i][j] = true;
		for (int di{-1}; di <= 0; ++di) {
			if (!(0 <= i + di && i + di + 1 < n)) continue;
			for (int dj{-1}; dj <= 0; ++dj) {
				if (!(0 <= j + dj && j + dj + 1 < m)) continue;
				qu.push({i + di, j + dj});
			}
		}
	};
	{
		int i, j;
		bool f{false};
		for (i = 0; i + 1 < n; ++i) {
			for (j = 0; j + 1 < m; ++j) {
				bool ok{true};
				for (int di{0}; di <= 1; ++di)
					for (int dj{0}; dj <= 1; ++dj)
						if (vis[i + di][j + dj] || g[i + di][j + dj] != g[i][j]) ok = false;
				if (!ok) continue;
				f = true;
				ans.push_back({i, j, g[i][j]});
				for (int di{0}; di <= 1; ++di)
					for (int dj{0}; dj <= 1; ++dj) add(i + di, j + dj);
			}
		}
		if (!f) return cout << "-1\n", []{}();
	}

	while (!qu.empty()) {
		auto [i, j]{qu.front()}; qu.pop();
		int cnt{vis[i][j] + vis[i + 1][j] + vis[i][j + 1] + vis[i + 1][j + 1]};
		if (cnt == 4 || cnt < 2) continue;
		int col{0};
		for (int di{0}; di <= 1; ++di)
			for (int dj{0}; dj <= 1; ++dj)
				if (!vis[i + di][j + dj]) {
					if (col && g[i + di][j + dj] != col) col = -1;
					else col = g[i + di][j + dj];
				}
		if (col == -1) continue;
		ans.push_back({i, j, col});
		for (int di{0}; di <= 1; ++di)
			for (int dj{0}; dj <= 1; ++dj)
				if (!vis[i + di][j + dj]) add(i + di, j + dj);
	}

	reverse(ans.begin(), ans.end());
	vector<vector<int>> g2(n, vector<int>(m));
	for (auto& [i, j, c] : ans)
		for (int di{0}; di <= 1; ++di)
			for (int dj{0}; dj <= 1; ++dj) g2[i + di][j + dj] = c;

	if (g == g2) {
		cout << ans.size() << '\n';
		for (auto& [i, j, c] : ans) cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
	} else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
