//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<pair<int, int>> ans{};
	int mn{numeric_limits<int>::max()}, j{-1}, mx{numeric_limits<int>::min()}, k{-1};
	for (int i{0}; i < n; ++i) {
		if (v[i] < mn) mn = v[i], j = i;
		if (v[i] > mx) mx = v[i], k = i;
	}
	if (mx > 0 && mn < 0) {
		if (abs(mx) >= abs(mn)) {
			for (int i{0}; i < n; ++i) {
				if (i == k) continue;
				ans.emplace_back(i, k), v[i] += v[k];
			}
		} else {
			for (int i{0}; i < n; ++i) {
				if (i == j) continue;
				ans.emplace_back(i, j), v[i] += v[j];
			}
		}
	}

	bool f{true};
	for (auto& x : v) {
		if (x < 0) {
			f = false;
			break;
		}
	}
	if (f) {
		for (int i{1}; i < n; ++i) ans.emplace_back(i, i - 1), v[i] += v[i - 1];
	} else {
		for (int i{n - 2}; i >= 0; --i) ans.emplace_back(i, i + 1), v[i] += v[i + 1];
	}

	cout << ans.size() << '\n';
	for (auto& [x, y] : ans) cout << (x + 1) << ' ' << (y + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
