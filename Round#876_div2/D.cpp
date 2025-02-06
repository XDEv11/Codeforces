//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> dp(n, vector<int>(n + 1));
	dp[0][0] = 1;
	for (int i{0}; i < n; ++i)
		for (int k{0}; k <= n; ++k)
			for (int j{i + 1}; j < n; ++j) {
				if (v[j] == v[i] + 1) dp[j][k] = max(dp[j][k], dp[i][k] + 1);
				else if (k + 1 <= n) dp[j][k + 1] = max(dp[j][k + 1], dp[i][k] + 1);
			}

	int ans{n};
	for (int i{1}; i <= n; ++i) {
		ans = min(ans, n - dp[n - 1][i]);
		cout << ans << ' ';
	}
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
