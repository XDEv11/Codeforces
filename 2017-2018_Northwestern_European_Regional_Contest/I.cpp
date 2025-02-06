//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n, c;
	if (!(cin >> n >> c)) return false;
	vector<pair<int, int>> v(n);
	for (auto& [x, y] : v) cin >> x >> y;

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {v[i].fi - v[i].se, i};
	sort(t.rbegin(), t.rend());

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, c + 1));
	dp[0][0] = 0;
	for (int i{0}; i < n; ++i) {
		int k{t[i].se};
		for (int j{0}; j <= i; ++j) dp[i + 1][j] = dp[i][j];
		for (int j{0}; j <= i; ++j) {
			if (dp[i][j] + max(v[k].fi, v[k].se) > c) continue;
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + v[k].se);
		}
	}

	vector<int> ans{};
	int j{n};
	while (dp[n][j] > c) --j;
	for (int i{n - 1}; i >= 0; --i) {
		if (dp[i + 1][j] == dp[i][j]) continue;
		ans.push_back(t[i].se), --j;
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
