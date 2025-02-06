//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template <typename T>
using matrix = vector<vector<T>>;
template <typename T>
using tensor = matrix<vector<T>>;

bool solve() {
	const array<array<int, 3>, 4> dir{1, 0, 1, 0, 1, 2, -1, 0, 1, 0, -1, 2};

	int n, m, r;
	if (!(cin >> n >> m >> r)) return false;
	matrix<int> g(n, vector<int>(m));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	tensor<int> dp(n, matrix<int>(m + 1, vector<int>(r + 1, m * 1000 + 1)));
	for (int i{0}; i < n; ++i) dp[i][0][0] = 0;
	for (int j{0}; j < m; ++j)
		for (int i{0}; i < n; ++i) {
			if (g[i][j] == -1) continue;
			bool f{true};
			for (auto& [di, dj, x] : dir) {
				int ni{i + di}, nj{j + dj};
				if (clamp(ni, 0, n - 1) != ni || clamp(nj, 0, m - 1) != nj || g[ni][nj] == -1
					|| (x == 1 && !(g[ni][nj] > g[i][j])) || (x == 2 && !(g[ni][nj] < g[i][j]))) f = false;
			}
			for (int k{f}; k <= r; ++k) {
				dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i][j][k - f] + g[i][j]);
				if (i - 1 >= 0) dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i - 1][j][k - f] + g[i][j]);
				if (i + 1 < n) dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i + 1][j][k - f] + g[i][j]);
			}
		}
	
	int ans{m * 1000 + 1};
	for (int i{0}; i < n; ++i) ans = min(ans, dp[i][m][r]);

	if (ans > m * 1000) cout << "impossible\n";
	else cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
