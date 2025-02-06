//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<vector<pair<int, int>>> dp(n + 1);
		dp[0] = {0, 0};
		for (int i{0}; i < n; ++i) {
			for (auto& d : dp[i - 1]) {
			}
			dp.push_back(0, d.se + 1);
			if (i >= 1) {
				if (v[i] >= v[i - 1]) {
					dp0[i + 1] = min(dp0[i - 1], dp1[i - 1]) + (v[i] + 1) / 2;

				}
				dp0[i + 1] = min(dp0[i - 1], dp1[i - 1]) + (max(v[i] + 1), v[i - 1]) + 1) / 2;
				if (i >= 3) {
					if (v

				}

			}
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
