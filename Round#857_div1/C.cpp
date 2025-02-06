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
	vector<vector<int>> a(n);
	for (int i{0}; i < n; ++i) {
		int k;
		cin >> k;
		for (int j{0}; j < k; ++j) {
			int x;
			cin >> x;
			if (a[i].empty() || a[i].back() < x) a[i].push_back(x);
		}
	}

	vector<pair<int, pair<int, int>>> v{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < a[i].size(); ++j) v.emplace_back(a[i][j], make_pair(a[i].back(), a[i].size() - j));
	sort(v.begin(), v.end());

	vector<int> dp(v.size() + 1);
	for (int i{0}; i < v.size(); ++i) {
		int l{i}, r{v.size()};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (v[m].fi <= v[i].se.fi) l = m;
			else r = m;
		}
		dp[r] = max(dp[r], dp[i] + v[i].se.se);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[v.size()] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
