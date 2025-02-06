//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k;
	if (!(cin >> n >> m >> k)) return false;
	vector<vector<char>> g(n + 2, vector<char>(m + 2, '*'));
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) cin >> g[i][j];
	if (k & 1) return cout << "IMPOSSIBLE\n", true;

	int x1, y1;
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			if (g[i][j] == 'X') x1 = i, y1 = j, g[i][j] = '.';
		}
	if (g[x1 + 1][y1] == '*' && g[x1][y1 - 1] == '*' && g[x1][y1 + 1] == '*' && g[x1 - 1][y1] == '*') {
		return cout << "IMPOSSIBLE\n", true;
	}

	array<array<int, 3>, 4> dir{1, 0, 'D', 0, -1, 'L', 0, 1, 'R', -1, 0, 'U'};

	vector<vector<int>> d(n + 2, vector<int>(m + 2, false));
	queue<pair<int, int>> qu{};
	d[x1][y1] = 1, qu.emplace(x1, y1);
	for (int i{0}; i < k; ++i) {
		queue<pair<int, int>> nq{};
		while (!qu.empty()) {
			auto [x, y]{qu.front()}; qu.pop();
			for (auto& [dx, dy, r] : dir) {
				auto nx{x + dx}, ny{y + dy};
				if (g[nx][ny] == '*' || d[nx][ny]) continue;
				d[nx][ny] = d[x][y] + 1, nq.emplace(nx, ny);
			}
		}
		qu = nq;
	}

	vector<char> ans(k, 'X');
	int x2{x1}, y2{y1};
	for (int i{0}; d[x2][y2] - 1 < k - i; ++i) {
		for (auto& [dx, dy, r] : dir) {
			auto nx{x2 + dx}, ny{y2 + dy};
			if (g[nx][ny] == '.') {
				x2 = nx, y2 = ny;
				ans[i] = r;
				break;
			}
		}
	}

	for (int i{d[x2][y2] - 1}; i >= 1; --i) {
		for (auto& [dx, dy, r] : dir) {
			auto nx{x2 + dx}, ny{y2 + dy};
			if (d[nx][ny] == d[x2][y2] - 1) {
				x2 = nx, y2 = ny;
				ans[k - i] = r;
				break;
			}
		}
	}

	for (auto& e : ans) cout << e;
	return cout << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
