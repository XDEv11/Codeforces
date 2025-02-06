//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [l, r] : v) cin >> l >> r;

	int m;
	{ // rank compression
		vector<int> tmp{};
		for (auto& [l, r] : v) tmp.push_back(l), tmp.push_back(r);
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		map<int, int> idx{};
		for (int i{0}; i < tmp.size(); ++i) idx[tmp[i]] = i;
		for (auto& [l, r] : v) l = idx[l], r = idx[r];
		m = tmp.size();
	}

	sort(v.begin(), v.end());

	vector<vector<int>> dp(n, vector<int>(m));
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < i; ++j) { // taken
			if (v[j].se < v[i].fi) continue;
			dp[i][max(v[i].se, v[j].se)] = max(dp[i][max(v[i].se, v[j].se)],
				(j && v[j].fi ? dp[j - 1][v[j].fi - 1] : 0) + 1);
		}
		for (int k{max(1, v[i].se)}; k < m; ++k) dp[i][k] = max(dp[i][k], dp[i][k - 1]);
		if (i) { // not taken
			for (int k{0}; k < m; ++k) dp[i][k] = max(dp[i][k], dp[i - 1][k]);
		}
	}

	cout << n - 2 * dp[n - 1][m - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tmp{1};
	cin >> tmp;
	while (tmp--) solve();
}
