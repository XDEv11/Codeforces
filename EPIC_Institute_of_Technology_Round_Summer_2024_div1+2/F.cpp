//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> p(n, -1);
		for (int i{0}; i < n; ++i) {
			if (!((v[i] & 1) == ((i + 1) & 1) && v[i] <= (i + 1))) continue;
			p[i] = (i + 1) - v[i];
		}

		const int s{n + 1};
		vector<vector<int>> dp(n, vector<int>(n + 1, s));
		for (int i{0}; i < n; ++i) dp[i][i] = 0;
		for (int c{2}; c <= n; c += 2)
			for (int i{0}, j{i + c}; j <= n; ++i, ++j) {
				if (p[i] == -1) continue;
				if (dp[i + 1][j - 1] != s && dp[i + 1][j - 1] <= p[i]) dp[i][j] = p[i];
				for (int k{i + 2}; k < j; k += 2) {
					if (!(dp[i][k] != s && dp[k][j] != s)) continue;
					dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j] - (k - i)));
				}
			}

		vector<int> ans(n + 1);
		for (int j{2}; j <= n; ++j) {
			ans[j] = ans[j - 1];
			for (int i{j - 2}; i >= 0; i -= 2) {
				if (!(dp[i][j] != s && dp[i][j] <= ans[i])) continue;
				ans[j] = max(ans[j], ans[i] + (j - i));
			}
		}

		cout << (ans[n] / 2) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
