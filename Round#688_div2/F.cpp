#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> dp(n, vector<int>(n, n));
	fill(dp[0].begin(), dp[0].end(), 0);
	for (int i{1}; i < n; ++i) {
		int cnt{0};
		for (int j{i - 1}; j >= 0; --j)
			if (j + v[j] >= i)
				dp[i][j + v[j]] = min(dp[i][j + v[j]], dp[j][i - 1] + cnt), ++cnt;

		for (int j{i + 1}; j < n; ++j)
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
	}
	cout << dp[n - 1][n - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
