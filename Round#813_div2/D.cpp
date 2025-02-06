//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

const int maxval{1000000000};

void solve1() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int l{0}, r{maxval + 1};
	while (r - l > 1) {
		int m{(l + r) / 2};
		auto t{v}; int c{0};
		for (int i{0}; i < n; ++i) {
			if (2 * t[i] < m) t[i] = maxval, ++c;
		}
		if (c <= k) {
			int mx;
			if (k - c >= 2) mx = maxval;
			else if (k - c == 1) mx = *max_element(t.begin(), t.end());
			else {
				mx = 0;
				for (int i{0}; i + 1 < n; ++i) mx = max(mx, min(t[i], t[i + 1]));
			}
			if (mx < m) r = m;
			else l = m;
		} else r = m;
	}

	cout << l << '\n';
}

void solve2() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (k == n) return cout << maxval << '\n', []{}();

	vector<pair<int, int>> t(n);
	for (int i{0}; i < n; ++i) t[i] = {v[i], i};
	sort(t.begin(), t.end());

	for (int i{0}; i < k - 1; ++i) v[t[i].se] = maxval;
	int mx{0};
	for (int i{0}; i < n; ++i) mx = max(mx, v[i]);
	int ans{min(2 * t[k - 1].fi, mx)};

	v[t[k - 1].se] = maxval;
	mx = 0;
	for (int i{0}; i + 1 < n; ++i) mx = max(mx, min(v[i], v[i + 1]));
	ans = max(ans, min(2 * t[k].fi, mx));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve2();
}
