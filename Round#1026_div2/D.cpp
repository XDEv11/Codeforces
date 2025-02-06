//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, _n;
		cin >> n >> _n;
		vector<int> b(n);
		for (auto& x : b) cin >> x;
		vector<array<int, 3>> p{};
		int mx;
		while (_n--) {
			int x, y, z;
			cin >> x >> y >> z, --x, --y, mx = max(mx, z);
			p.push_back({x, y, z});
		}

		vector<vector<array<int, 2>>> t(n);
		for (auto& [x, y, z] : p) t[x].push_back({y, z});

		int l{0}, r{mx + 1};
		while (r - l > 1) {
			int m{(l + r) / 2};

			vector<int> dp(n, -1);
			dp[0] = 0;
			for (int x{0}; x < n; ++x) {
				if (dp[x] == -1) continue;
				for (auto& [y, z] : t[x]) {
					if (z > m) continue;
					if (dp[x] + b[x] < z) continue;
					dp[y] = max(dp[y], min(m, dp[x] + b[x]));
				}
			}

			(dp[n - 1] == -1 ? l : r) = m;
		}

		if (r > mx) cout << "-1\n";
		else cout << r << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
