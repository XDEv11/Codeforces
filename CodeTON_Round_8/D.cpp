//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(n));
	for (int i{0}; i < n; ++i)
		for (int j{i}; j < n; ++j) cin >> a[i][j];

	vector<vector<ll>> dp(n + 1);
	dp[0] = {0};
	for (int i{0}; i < n; ++i) {
		priority_queue<tuple<ll, int, int>> pq{};
		pq.emplace(dp[i][0], i, 1);
		for (int j{-1}; j < i; ++j) pq.emplace(dp[max(0, j)][0] + a[j + 1][i], j, 1);
		while (dp[i + 1].size() < m && !pq.empty()) {
			auto [mx, j, k]{pq.top()}; pq.pop();
			dp[i + 1].push_back(mx);
			if (k < dp[max(0, j)].size()) pq.emplace(dp[max(0, j)][k] + (j == i ? 0 : a[j + 1][i]), j, k + 1);
		}
	}

	for (auto& x : dp[n]) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
