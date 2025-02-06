#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <queue>

using namespace std;

static const array<pair<int, int>, 4> dir{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n + 2, vector<char>(m + 2, '#'));
	pair<int, int> s;
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 'L') s = {i, j};
		}

	queue<pair<int, int>> qu{};
	qu.push(s);
	while (!qu.empty()) {
		auto [x, y]{qu.front()}; qu.pop();
		for (auto& [dx, dy] : dir) {
			if (g[x + dx][y + dy] != '.') continue;

			int cnt{0};
			for (auto& [ddx, ddy] : dir) cnt += (g[x + dx + ddx][y + dy + ddy] == '.');
			if (cnt <= 1) g[x + dx][y + dy] = '+', qu.emplace(x + dx, y + dy);
		}
	}

	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) cout << g[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
