//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> c(n + 1);
		vector<vector<int>> t(n + 1);
		for (int i{0}; i < n; ++i) ++c[v[i]], t[v[i]].push_back(i);

		vector<vector<int>> dp(n + 1);
		auto minimize{[](int& a, int b) { a = min(a, b); }};
		dp[0] = {0};
		for (int i{1}; i <= n; ++i) {
			int m0{t[i].size()}, m1{t[i - 1].size()};
			dp[i].assign(m0 + 1, n);
			minimize(dp[i][0], dp[i - 1][0] + m0);
			minimize(dp[i][0], dp[i - 1][m1] + m0);
			if (m0) dp[i][1] = dp[i - 1][0] + m0 - 1;
			for (int k{1}, j{m0}; k <= m1; ++k) {
				while (j - 1 >= 0 && t[i][j - 1] > t[i - 1][m1 - k]) --j;
				if (j) minimize(dp[i][m0 - (j - 1)], dp[i - 1][k] + m0 - 1);
			}
			for (int j{1}; j + 1 <= m0; ++j) minimize(dp[i][j + 1], dp[i][j] - 1);
		}

		cout << min(dp[n][0], dp[n].back()) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
