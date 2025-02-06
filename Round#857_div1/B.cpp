//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <set>
#include <limits>
#include <iterator>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [a, b] : v) cin >> a >> b;

	vector<pair<int, int>> v2(n);
	for (int i{0}; i < n; ++i) v2[i] = {v[i].fi, i};
	sort(v2.rbegin(), v2.rend());

	int ans{numeric_limits<int>::max()};

	multiset<int> ms{};
	for (int i{0}; i < n; ++i) ms.insert(v[i].se);
	int mx{-1};
	for (int i{0}; i < n; ++i) {
		auto [a, idx]{v2[i]};
		if (!(i + 1 < n && a == v2[i + 1].fi)) ms.erase(ms.find(v[idx].se));

		auto it{ms.upper_bound(a)};
		if (it != ms.end()) ans = min(ans, abs(a - max(mx, *it)));
		if (it != ms.begin()) ans = min(ans, abs(a - max(mx, *prev(it))));
		if (mx != -1) ans = min(ans, abs(a - mx));

		if (i + 1 < n && a == v2[i + 1].fi) ms.erase(ms.find(v[idx].se));
		mx = max(mx, v[idx].se);
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
