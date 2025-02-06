//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int l{1}, r{1000000001};
		while (r - l > 1) {
			int m{(l + r) / 2};
			vector<int> c(n);
			for (int i{0}; i < n; ++i) c[i] = (v[i] >= m ? 1 : -1);
			vector<int> dp(n);
			dp[0] = c[0];
			for (int i{1}; i < n; ++i) {
				if (i % k) {
					dp[i] = dp[i - 1] + c[i];
					if (i - k >= 0) dp[i] = max(dp[i], dp[i - k]);
				} else dp[i] = max(dp[i - k], c[i]);
			}
			(dp[n - 1] > 0 ? l : r) = m;
		}

		cout << l << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
