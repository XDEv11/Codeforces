//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	template<typename T>
	using tensor = vector<matrix<T>>;
	void solve() {
		int n, m, q;
		cin >> n >> m >> q;
		vector<array<int, 3>> e(m);
		for (auto& [c, u, v] : e) cin >> u >> v >> c, --u, --v;

		sort(e.begin(), e.end());

		tensor<int> dp(m + 1, matrix<int>(n, vector<int>(n, n)));
		for (int u{0}; u < n; ++u) dp[0][u][u] = 0;
		for (auto& [c, u, v] : e) dp[0][u][v] = dp[0][v][u] = 1;
		for (int w{0}; w < n; ++w)
			for (int u{0}; u < n; ++u)
				for (int v{0}; v < n; ++v) dp[0][u][v] = min(dp[0][u][v], dp[0][u][w] + dp[0][w][v]);
		for (int i{0}; i < m; ++i) {
			auto& [_, a, b]{e[i]};
			for (int u{0}; u < n; ++u)
				for (int v{0}; v < n; ++v) {
					dp[i + 1][u][v] = min({dp[i][u][v], dp[i][u][a] + dp[i][b][v], dp[i][u][b] + dp[i][a][v]});
				}
		}

		while (q--) {
			int a, b, k;
			cin >> a >> b >> k, --a, --b;

			int l{0}, r{m};
			while (r - l > 1) {
				int md{(l + r) / 2};
				(dp[md][a][b] < k ? r : l) = md;
			}

			cout << e[r - 1][0] << ' ';
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
