//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<int> ld(n), rd(n);
	for (int i{0}, j{-1}; i < n; ++i) {
		if (i - 1 >= 0 && v[i - 1] != v[i]) j = i - 1;
		ld[i] = j;
	}
	for (int i{n - 1}, j{n}; i >= 0; --i) {
		if (i + 1 < n && v[i + 1] != v[i]) j = i + 1;
		rd[i] = j;
	}

	vector<ll> ls{v}, rs{v};
	for (int i{1}; i < n; ++i) ls[i] += ls[i - 1];
	for (int i{n - 2}; i >= 0; --i) rs[i] += rs[i + 1];

	for (int i{0}; i < n; ++i) {
		int ans{n};
		if (i - 1 >= 0 && ls[i - 1] > v[i]) {
			if (v[i - 1] > v[i]) ans = 1;
			else if (ld[i - 1] >= 0) {
				int l{-1}, r{ld[i - 1] + 1};
				while (r - l > 1) {
					int m{(l + r) / 2};
					if (ls[i - 1] - (m - 1 >= 0 ? ls[m - 1] : 0) > v[i]) l = m;
					else r = m;
				}
				ans = i - l;
			}
		}
		if (i + 1 < n && rs[i + 1] > v[i]) {
			if (v[i + 1] > v[i]) ans = 1;
			else if (rd[i + 1] < n) {
				int l{rd[i + 1] - 1}, r{n};
				while (r - l > 1) {
					int m{(l + r) / 2};
					if (rs[i + 1] - (m + 1 < n ? rs[m + 1] : 0) > v[i]) r = m;
					else l = m;
				}
				ans = min(ans, r - i);
			}
		}
		cout << (ans == n ? -1 : ans) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
