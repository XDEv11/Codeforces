//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	array<array<int, 2>, 4> dir{-1, 0, 0, 1, 1, 0, 0, -1};
	array<char, 4> aux{'D', 'L', 'U', 'R'};
	void solve() {
		int n, m;
		cin >> n >> m;
		matrix<char> g(n, vector<char>(m));
		for (auto& v : g)
			for (auto& i : v) cin >> i;

		matrix<bool> vis(n, vector<bool>(m));
		queue<array<int, 2>> qu{};
		for (int i{0}; i < n; ++i) {
			if (g[i][0] == 'L') vis[i][0] = true, qu.push({i, 0});
			if (g[i][m - 1] == 'R') vis[i][m - 1] = true, qu.push({i, m - 1});
		}
		for (int j{0}; j < m; ++j) {
			if (g[0][j] == 'U') vis[0][j] = true, qu.push({0, j});
			if (g[n - 1][j] == 'D') vis[n - 1][j] = true, qu.push({n - 1, j});
		}

		while (!qu.empty()) {
			auto [i, j]{qu.front()}; qu.pop();
			for (int k{0}; k < 4; ++k) {
				auto& [di, dj]{dir[k]};
				int ni{i + di}, nj{j + dj};
				if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj) continue;
				if (vis[ni][nj]) continue;
				if (g[ni][nj] == aux[k]) {
					vis[ni][nj] = true, qu.push({ni, nj});
				}
			}
		}

		int ans{n * m};
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < m; ++j) {
				if (g[i][j] == '?') {
					bool f{true};
					for (auto& [di, dj] : dir) {
						int ni{i + di}, nj{j + dj};
						if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj) continue;
						if (!vis[ni][nj]) f = false;
					}
					ans -= f;
				} else ans -= vis[i][j];
			}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
