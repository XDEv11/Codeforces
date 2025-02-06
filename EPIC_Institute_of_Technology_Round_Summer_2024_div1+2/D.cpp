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
		for (auto& x : v) ++c[x];

		vector<int> t{};
		for (auto& x : c) {
			if (x) t.push_back(x);
		}
		int m{t.size()};

		vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
		auto update{[](int& x, int y) {
			if (x == -1) x = y;
			else x = min(x, y);
		}};
		dp[0][0] = 0;
		for (int i{0}; i < m; ++i) {
			for (int j{0}; j <= i; ++j) dp[i + 1][j] = dp[i][j];
			for (int j{0}; j <= i; ++j) {
				if (dp[i][j] == -1) continue;
				if (dp[i][j] + t[i] <= i - j) update(dp[i + 1][j + 1], dp[i][j] + t[i]);
			}
		}

		for (int j{m}; j >= 0; --j) {
			if (dp[m][j] == -1) continue;
			cout << (m - j) << '\n';
			return ;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
