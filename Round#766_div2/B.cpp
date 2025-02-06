//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

const array<array<int, 2>, 4> dir{1, 0, 0, 1, -1, 0, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;

	auto bfs = [&](int sx, int sy) {
		vector<vector<int>> g(n, vector<int>(m, -1));
		queue<tuple<int, int, int>> qu{};
		g[sx][sy] = 0;
		qu.emplace(sx, sy, g[sx][sy]);
		while (!qu.empty()) {
			auto [x, y, len]{qu.front()}; qu.pop();
			for (auto& d : dir) {
				auto nx{x + d[0]}, ny{y + d[1]};
				if (!(0 <= nx && nx < n) || !(0 <= ny && ny < m) || g[nx][ny] != -1) continue;
				g[nx][ny] = len + 1;
				qu.emplace(nx, ny, g[nx][ny]);
			}
		}
		return g;
	};
	auto g1{bfs(0, 0)}, g2{bfs(n - 1, 0)}, g3{bfs(0, m - 1)}, g4{bfs(n - 1, m - 1)};

	vector<int> cnt(n + m - 1, 0);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			++cnt[max(max(g1[i][j], g2[i][j]), max(g3[i][j], g4[i][j]))];
		}
	for (int i{1}; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];

	int k{0};
	for (int i{0}; i < n * m; ++i) {
		while (i >= cnt[k]) ++k;
		cout << k << " \n"s[i == n * m - 1];
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
