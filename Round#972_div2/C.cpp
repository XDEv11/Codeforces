//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	const char* name{"narek"};
	bool ck(char c) {
		for (int k{0}; k < 5; ++k) {
			if (c == name[k]) return true;
		}
		return false;
	}
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> t(n, vector<char>(m));
		for (auto& v : t)
			for (auto& x : v) cin >> x;

		vector<vector<int>> dp(n + 1, vector<int>(5, -n * m));
		dp[0][0] = 0;
		for (int i{0}; i < n; ++i) {
			dp[i + 1] = dp[i];
			for (int k{0}; k < 5; ++k) {
				int j{k}, d{};
				for (auto& c : t[i]) {
					if (c == name[j]) {
						++d, j = (j + 1) % 5;
					} else if (ck(c)) --d;
				}
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + d);
			}
			for (int k{1}; k < 5; ++k) dp[i + 1][k - 1] = max(dp[i + 1][k - 1], dp[i + 1][k] - 2);
		}

		cout << dp[n][0] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
