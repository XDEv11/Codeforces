//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x, --x;

	vector<int> fst(n, -1), lst(n, -1);
	for (int i{0}; i < n; ++i) {
		if (fst[a[i]] == -1) fst[a[i]] = i;
		lst[a[i]] = i;
	}

	vector<pair<int, int>> v{};
	for (int i{0}; i < n; ++i) {
		if (fst[i] != lst[i]) v.emplace_back(fst[i], lst[i]);
	}
	sort(v.begin(), v.end());

	int ans{0};
	int r{-1};
	bool f;
	for (int i{0}; i < v.size(); ) {
		if (r < v[i].fi) r = v[i].fi, f = false;
		int j{i}, mx{0};
		while (j < v.size() && v[j].fi <= r) mx = max(mx, v[j++].se);
		if (mx > r) {
			ans += mx - r - 1, ans -= f;
			r = mx - 1, f = true;
		}
		i = j;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
