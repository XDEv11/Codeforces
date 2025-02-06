//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <limits>

using namespace std;

void solve1() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, t] : v) cin >> x, x *= 2;
	for (auto& [x, t] : v) cin >> t, t *= 2;

	sort(v.begin(), v.end());
	vector<int> np(n, -1);
	int sz{0};
	for (int i{0}; i < n; ++i) {
		if (i + 1 < n && v[i].fi == v[i + 1].fi) continue;
		np[i] = sz++;
	}
	for (int i{0}; i < n; ++i) {
		if (np[i] == -1) continue;
		v[np[i]] = v[i];
	}
	v.resize(sz);
	if (sz == 1) return cout << v[0].fi / 2 << '\n', []{}();

	vector<int> l(sz), r(sz);
	l[0] = v[0].se;
	for (int i{1}; i < sz; ++i) l[i] = max(v[i].se, l[i - 1] + v[i].fi - v[i - 1].fi);
	r[sz - 1] = v[sz - 1].se;
	for (int i{sz - 2}; i >= 0; --i) r[i] = max(v[i].se, r[i + 1] + v[i + 1].fi - v[i].fi);

	int mn{numeric_limits<int>::max()}, ans;
	for (int i{0}; i + 1 < sz; ++i) {
		int p{v[i].fi}, d{v[i + 1].fi - v[i].fi};
		if (l[i] < r[i + 1]) {
			int m{min(d, r[i + 1] - l[i])};
			l[i] += m, d -= m, p += m;
		} else {
			int m{min(d, l[i] - r[i + 1])};
			r[i + 1] -= m, d -= m;
		}
		l[i] += d / 2, r[i + 1] -= d / 2, p += d / 2;
		int c{max(l[i], r[i + 1])};

		if (c < mn) mn = c, ans = p;
	}

	cout << ans / 2;
	if (ans & 1) cout << ".5";
	cout << '\n';
}

void solve2() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& [x, t] : v) cin >> x;
	for (auto& [x, t] : v) cin >> t;

	int mn{numeric_limits<int>::max()}, mx{numeric_limits<int>::min()};
	for (int i{0}; i < n; ++i) mn = min(mn, v[i].fi - v[i].se), mx = max(mx, v[i].fi + v[i].se);

	cout << (mn + mx) / 2 << ((mn + mx) & 1 ? ".5\n" : "\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
