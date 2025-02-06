//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i{1}; i < n; ++i) cin >> p[i], --p[i];
	vector<pair<int, int>> c(n);
	for (auto& [l, r] : c) cin >> l >> r;

	vector<vector<int>> adj(n);
	for (int i{1}; i < n; ++i) adj[p[i]].push_back(i);

	vector<int> ans(n, 0);
	vector<long long> sum(n, 0);
	vector<int> rc(n, 0);
	int x{0};
	while (true) {
		if (rc[x] == adj[x].size()) {
			if (adj[x].empty()) {
				sum[x] = c[x].se;
				ans[x] = 1;
			} else {
				if (sum[x] < c[x].fi) sum[x] = c[x].se, ++ans[x];
				else if (sum[x] > c[x].se) sum[x] = c[x].se;
			}

			if (x == 0) break;
			ans[p[x]] += ans[x];
			sum[p[x]] += sum[x];
			x = p[x];
		} else x = adj[x][rc[x]++];
	}

	cout << ans[0] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
