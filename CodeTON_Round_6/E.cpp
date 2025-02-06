//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<array<bool, 5002>> dp(n + 1);
	dp[0][0] = true;
	for (int i{0}; i < n; ++i) {
		dp[i + 1] = dp[i];
		array<int, 5002> cnt{};
		int m{0};
		for (int j{i}; j >= 0; --j) {
			++cnt[v[j]];
			while (cnt[m]) ++m;
			if (v[i] > m || cnt[v[i]] > 1) continue;
			if (v[j] > m || cnt[v[j]] > 1) continue;
			for (int x{0}; x <= 5001; ++x) {
				if (!dp[j][x]) continue;
				dp[i + 1][x ^ m] = true;
			}
		}
	}

	int ans{5001};
	while (!dp[n][ans]) --ans;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
