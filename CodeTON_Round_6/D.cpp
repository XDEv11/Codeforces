//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	cin >> k;

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {v[i], i};
	sort(t.begin(), t.end());

	vector<int> ans(n);
	int i{0};
	while (i + 1 < n && t[i].fi == t[i + 1].fi) ++i;
	auto [val, idx]{t[i]};
	int lc;
	{
		int c{k / val};
		k -= c * val;
		for (int j{0}; j <= idx; ++j) ans[j] = c;
		lc = c;
	}
	for (i = i + 1; i < n; ++i) {
		if (t[i].se < idx || (i + 1 < n && t[i].fi == t[i + 1].fi)) continue;
		int c{min(lc, k / (t[i].fi - val))};
		k -= c * (t[i].fi - val);
		for (int j{idx + 1}; j <= t[i].se; ++j) ans[j] = c;
		tie(val, idx) = t[i];
		lc = c;
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
