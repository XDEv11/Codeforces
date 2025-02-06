//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <deque>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> a(m);
		for (auto& [u, v] : a) cin >> u >> v, --u, --v;

		vector<vector<int>> t(n);
		for (auto& [u, v] : a) t[v].push_back(u);

		vector<int> dp(n + 1);
		dp[0] = 0;
		for (int v{0}; v < n; ++v) {
			dp[v + 1] = dp[v] + 1;
			for (auto& u : t[v]) dp[v + 1] = min(dp[v + 1], dp[u + 1] + 1);
		}

		vector<int> ans0(n), ans1(n);
		for (auto& [u, v] : a) {
			if (u + 1 <= v - (dp[u + 1] + 1)) {
				++ans0[u + 1];
				++ans1[v - (dp[u + 1] + 1)];
			}
		}

		int c{};
		vector<bool> ans(n, true);
		for (int i{0}; i < n - 1; ++i) {
			c += ans0[i];
			if (c) ans[i] = false;
			c -= ans1[i];
		}

		for (int i{0}; i < n - 1; ++i) cout << ans[i];
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
