//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <array>

using namespace std;

const array<array<int, 2>, 4> dir{1, 0, 0, 1, -1, 0, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n + 2, vector<char>(m + 2, '0'));
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) cin >> g[i][j];

	vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
	for (int i{1}; i <= n; ++i)
		for (int j{1}; j <= m; ++j) {
			if (g[i][j] == '0' || vis[i][j]) continue;
			int mxx{i}, mxy{j}, mnx{i}, mny{j}, cnt{0};
			queue<pair<int, int>> qu{};
			qu.emplace(i, j), vis[i][j] = true;
			while (!qu.empty()) {
				auto [x, y]{qu.front()}; qu.pop(), ++cnt;
				mxx = max(mxx, x), mxy = max(mxy, y), mnx = min(mnx, x), mny = min(mny, y);
				for (auto& [dx, dy] : dir) {
					auto nx{x + dx}, ny{y + dy};
					if (g[nx][ny] == '0' || vis[nx][ny]) continue;
					qu.emplace(nx, ny), vis[nx][ny] = true;
				}
			}
			if (cnt != (mxx - mnx + 1) * (mxy - mny + 1)) return cout << "NO\n", []{}();
		}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
