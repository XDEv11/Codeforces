#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> p{};
	for (int i{0}; i < n; ++i)
		if (v[i]) p.push_back(i);

	vector<vector<int>> dp(n + 1, vector<int>(p.size() + 1, 10000000));
	dp[0][0] = 0;
	for (int i{0}; i + 1 <= n; ++i)
		for (int j{0}; j <= p.size(); ++j) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (j < p.size() && v[i] == 0)
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(i - p[j]));
		}

	cout << dp.back().back() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
