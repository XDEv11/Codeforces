//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	void solve() {
		int n, m;
		cin >> n >> m;
		bool f{n < m};
		if (f) swap(n, m);
		matrix<char> g(n, vector<char>(m));
		if (!f) {
			for (int i{0}; i < n; ++i)
				for (int j{0}; j < m; ++j) cin >> g[i][j];
		} else {
			for (int i{0}; i < m; ++i)
				for (int j{0}; j < n; ++j) cin >> g[j][i];
		}

		matrix<int> ans(n, vector<int>(m));
		matrix<int> pv(m, vector<int>(m, -1)), nx(m, vector<int>(m, m));
		for (int j{0}; j < m; ++j)
			for (int k{j + 1}; k < m; ++k)
				for (int i{0}; i < n; ++i) {
					if (g[i][j] == '1' && g[i][k] == '1') {
						nx[j][k] = i;
						break;
					}
				}
		for (int i{0}; i < n; ++i) {
			matrix<int> dp(m, vector<int>(m, n * m + 1));
			auto minimize{[]<typename T>(T& a, T b) { a = min(a, b); }};
			for (int j{0}; j < m; ++j)
				for (int k{j + 1}; k < m; ++k) {
					int w{k - j + 1};
					if (nx[j][k] == n) continue;
					if (pv[j][k] != -1) minimize(dp[j][k], w * (nx[j][k] - pv[j][k] + 1));
					if (nx[j][k] == i) {
						pv[j][k] = nx[j][k];
						int l{i + 1};
						while (l < n && !(g[l][j] == '1' && g[l][k] == '1')) ++l;
						nx[j][k] = l;
						if (nx[j][k] == n) continue;
						minimize(dp[j][k], w * (nx[j][k] - pv[j][k] + 1));
					}
				}
			for (int l{m - 1}; l >= 0; --l)
				for (int j{0}; j + l < m; ++j) {
					int k{j + l};
					if (k + 1 < m) minimize(dp[j][k], dp[j][k + 1]);
					if (j - 1 >= 0) minimize(dp[j][k], dp[j - 1][k]);
				}
			for (int j{0}; j < m; ++j) {
				if (dp[j][j] != n * m + 1) ans[i][j] = dp[j][j];
			}
		}

		if (!f) {
			for (int i{0}; i < n; ++i)
				for (int j{0}; j < m; ++j) cout << ans[i][j] << " \n"[j == m - 1];
		} else {
			for (int i{0}; i < m; ++i)
				for (int j{0}; j < n; ++j) cout << ans[j][i] << " \n"[j == n - 1];
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
