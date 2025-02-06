//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m, m = n * (n - 1) / 2 - m;

		vector<vector<int>> dp(n + 1, vector<int>(n * (n - 1) / 2 + 1));
		dp[0][0] = 1;
		for (int i{0}; i < n; ++i)
			for (int j{i + 1}; j <= n; ++j) {
				int l{j - i};
				for (int k{0}; k <= n * (n - 1) / 2; ++k) {
					if (dp[i][k]) dp[j][k + l * (l - 1) / 2] = l;
				}
			}
		if (!dp[n][m]) return cout << "0\n", []{}();

		vector<int> ans(n);
		for (int j{n}, k{0}; j; ) {
			int l{dp[j][m]};
			for (int i{j - l}; i < j; ++i) ans[i] = ++k;
			j -= l, m -= l * (l - 1) / 2;
		}

		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
