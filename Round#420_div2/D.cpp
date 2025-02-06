//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k;
	if (!(cin >> n >> m >> k)) return false;
	vector<vector<bool>> g(n, vector<bool>(m));
	while (k--) {
		int i, j;
		cin >> i >> j, --i, --j;
		g[i][j] = true;
	}

	const array<array<int, 2>, 4> dir{-1, 0, 1, 0, 0, -1, 0, 1};

	queue<array<int, 2>> qu{};
	vector<vector<bool>> vis(n, vector<bool>(m));
	vector<bool> rv(n), cv(m);
	vis[0][0] = true, qu.push({0, 0});
	for (int ans{0}; !qu.empty(); ++ans) {
		queue<array<int, 2>> nq{};
		vector<array<int, 2>> tmp{};
		while (!qu.empty()) {
			auto [i, j]{qu.front()}; qu.pop();
			if (i == n - 1 && j == m - 1) return cout << ans << '\n', true;
			tmp.push_back({i, j});
			for (auto& [di, dj] : dir) {
				auto ni{i + di}, nj{j + dj};
				if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj || !g[ni][nj] || vis[ni][nj]) continue;
				vis[ni][nj] = true, qu.push({ni, nj});
			}
		}
		for (auto& [i, j] : tmp) {
			for (int dj{-1}; dj <= 1; ++dj) {
				int jj{j + dj};
				if (clamp(jj, 0, m - 1) != jj || cv[jj]) continue;
				cv[jj] = true;
				if (jj == m - 1) return cout << ans + 1 << '\n', true;
				for (int ii{0}; ii < n; ++ii) {
					if (g[ii][jj] && !vis[ii][j]) vis[ii][jj] = true, nq.push({ii, jj});
					if (jj - 1 >= 0 && g[ii][jj - 1] && !vis[ii][jj - 1]) vis[ii][jj - 1] = true, nq.push({ii, jj - 1});
					if (jj + 1 < m && g[ii][jj + 1] && !vis[ii][jj + 1]) vis[ii][jj + 1] = true, nq.push({ii, jj + 1});
				}
			}
			for (int di{-1}; di <= 1; ++di) {
				int ii{i + di};
				if (clamp(ii, 0, n - 1) != ii || rv[ii]) continue;
				rv[ii] = true;
				if (ii == n - 1) return cout << ans + 1 << '\n', true;
				for (int jj{0}; jj < m; ++jj) {
					if (g[ii][jj] && !vis[ii][jj]) vis[ii][jj] = true, nq.push({ii, jj});
					if (ii - 1 >= 0 && g[ii - 1][jj] && !vis[ii - 1][jj]) vis[ii - 1][jj] = true, nq.push({ii - 1, jj});
					if (ii + 1 < n && g[ii + 1][jj] && !vis[ii + 1][jj]) vis[ii + 1][jj] = true, nq.push({ii + 1, jj});
				}
			}
		}
		qu = nq;
	}
	return cout << "-1\n", true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
