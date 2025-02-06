//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using int2 = array<int, 2>;
	using int3 = array<int, 3>;
	bool solve() {
		int n;
		if (!(cin >> n)) return false;
		vector<int> v(n);
		for (auto& x : v) cin >> x;
		vector<vector<int3>> q(n);
		int p;
		cin >> p;
		for (int k{0}; k < p; ++k) {
			int i, j, x;
			cin >> i >> j >> x, --i, --j;
			q[j].push_back({i, x, k});
		}

		vector<int> ans(p);
		array<array<int, 12>, 4096> dp;
		dp[0].fill(n);
		for (int x{1}; x < 4096; ++x) dp[x].fill(-1);
		for (int j{0}; j < n; ++j) {
			dp[v[j]].fill(j);
			for (int x{1}; x < 4096; ++x) {
				if (x == v[j]) continue;
				int y{x ^ v[j]};
				for (int c{1}; c < 12; ++c) dp[x][c] = max(dp[x][c], dp[y][c - 1]);
			}

			for (auto& [i, x, k] : q[j]) {
				for (int c{0}; c < 12; ++c) {
					if (i <= dp[x][c]) { ans[k] = c + 1; break; }
				}
			}
		}

		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
