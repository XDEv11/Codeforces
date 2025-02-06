#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> tag(n);
	vector<long long> s(n);
	for (auto& x : tag) cin >> x;
	for (auto& x : s) cin >> x;

	long long mx;
	vector<vector<long long>> dp(n, vector<long long>(n, 0));
	for (int i{0}; i + 1 < n; ++i) {
		mx = 0;
		for (int j{0}; j < i; ++j) {
			if (tag[j] == tag[i]) continue;
			dp[j][i + 1] = max(dp[i][i + 1], dp[j][i] + abs(s[i + 1] - s[i]));
			if (j - 1 >= 0 && tag[i] != tag[k] && tag[k] != tag[i + 1])
				mx = max(mx, abs(s[k] - s[i]) + abs(s[i + 1] - s[k]))
		}
	}

	long long ans{0};
	mx = 0;
	for (int j{0}; j < n - 1; ++j) {
		ans = max(ans, dp[j][n - 1] + mx);
		if (j - 1 >= 0) mx = max(mx, abs(s[n - 1] - s[j]));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
