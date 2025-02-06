//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n), b(k);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> c(n);
	for (auto& x : b) ++c[x - 1];
	for (int i{n - 2}; i >= 0; --i) c[i] += c[i + 1];

	auto calc{[&](int i, int x) {
		int t{max(0, x - 1) / c[i]};
		x -= t * c[i];
		int j{0};
		while (x) x -= (i < b[j++]);
		return t * k + j;
	}};

	vector<pair<int, int>> v{};
	for (int i{0}; i < n; ++i) {
		if (a[i] > i + 1) continue;
		a[i] = i + 1 - a[i];
		if (c[i] == 0) {
			if (a[i] == 0) v.emplace_back(0, 1);
		} else {
			v.emplace_back(calc(i, a[i]), 1);
			v.emplace_back(calc(i, a[i] + 1), -1);
		}
	}
	sort(v.begin(), v.end());

	int ans{(d - (a[0] != 0)) / 2}, z{};
	for (auto& [x, y] : v) {
		if (x + 1 > d) break;
		z += y;
		ans = max(ans, z + (d - (x + 1)) / 2);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
