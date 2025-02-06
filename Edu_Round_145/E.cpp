//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<vector<int>> ans(a + 1, vector<int>(b + 1));
	for (int cd{0}; cd <= a + b; ++cd) {
		int s{0}, l{max(0, cd - b)}, r{min(a, cd)};
		for (auto& x : v) {
			s += x;
			l = max(l, max(0, cd - b) + s);
			r = min(r, min(a, cd) + s);
		}
		if (l >= r) {
			int res{l};
			for (auto& x : v) {
				if (x > 0) res -= min({res, x, b - (cd - res)});
				else res += min({cd - res, -x, a - res});
			}
			for (int c{max(0, cd - b)}; c <= min(a, cd); ++c) ans[c][cd - c] = res;
		} else {
			for (int c{max(0, cd - b)}; c <= min(a, cd); ++c) ans[c][cd - c] = clamp(c, l, r) - s;
		}
	}

	for (int c{0}; c <= a; ++c) {
		for (int d{0}; d <= b; ++d) cout << ans[c][d] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
