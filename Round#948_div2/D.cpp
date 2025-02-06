//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

using namespace std;

static void solve() {
	using ll = long long;
	auto myrand{[] {
		static mt19937_64 gen{chrono::system_clock::now().time_since_epoch().count()};
		static uniform_int_distribution<mt19937_64::result_type> dist{1};
		return bind(dist, gen);
	}()};

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mtx(n, vector<int>(m));
	for (auto& vt : mtx)
		for (auto& x : vt) {
			char c;
			cin >> c;
			x = (c == '1');
		}

	vector<ll> r(n);
	for (auto& x : r) x = myrand();

	map<ll, int> mp1{};
	map<ll, pair<int, int>> mp2{};
	for (int j{0}; j < m; ++j) {
		ll x{};
		for (int i{0}; i < n; ++i) {
			if (!mtx[i][j]) continue;
			x ^= r[i];
		}
		for (int i{0}; i < n; ++i) {
			if (++mp1[x ^ r[i]] == 1) mp2[x ^ r[i]] = {i, j};
		}
	}

	int ansv{}; ll ansk;
	for (auto& [k, v] : mp1) {
		if (v > ansv) ansv = v, ansk = k;
	}
	auto [i, j]{mp2[ansk]};
	vector<int> ans(n);
	for (int k{0}; k < n; ++k) ans[k] = (mtx[k][j] ^ (k == i));

	cout << ansv << '\n';
	for (auto& x : ans) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
