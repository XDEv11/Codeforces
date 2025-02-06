//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int m, n;
	cin >> m >> n;
	vector<ll> p(n);
	for (auto& x : p) cin >> x;
	vector<vector<int>> r(m, vector<int>(n));
	for (auto& v : r)
		for (auto& x : v) cin >> x;

	vector<bitset<5000>> t(n);
	vector<int> od{};
	for (auto& x : t) x.set();
	for (auto& v : r) {
		vector<vector<int>> cnt(n + 1);
		for (int i{0}; i < n; ++i) cnt[v[i]].push_back(i);
		bitset<5000> bs{};
		for (int i{1}; i <= n; ++i) {
			for (auto& x : cnt[i]) t[x] &= bs;
			for (auto& x : cnt[i]) bs.set(x);
		}
		if (od.empty()) {
			for (int i{1}; i <= n; ++i)
				for (auto& x : cnt[i]) od.push_back(x);
		}
	}

	vector<ll> dp(n);
	for (int _i{0}; _i < n; ++_i) {
		int i{od[_i]};
		dp[i] = p[i];
		for (int j{0}; j < n; ++j) {
			if (t[i][j]) dp[i] = max(dp[i], p[i] + dp[j]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
